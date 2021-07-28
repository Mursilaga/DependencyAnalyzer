#include "Analyzer.h"
#include "InputHandler.h"
#include "OutputWriter.h"

#include <filesystem>
#include <iostream>
#include <regex>
#include <algorithm>

void Analyzer::exec(int argc, char* argv[]) {
    InputHandler input;
    OutputWriter writer;

    input.handle(argc, argv);
    if (!input.isValid()) {
        writer.printUsage();
        return;
    }

    std::string root_dir = input.getRootDir();
    seeker = std::make_unique<IncludeSeeker>(root_dir, input.getAdditionalIncludes());
    
    for (auto& file : std::filesystem::recursive_directory_iterator(root_dir)) { //TODO may be move to IncludeSeeker filesystem work?

        if (std::regex_search(file.path().filename().string(), std::regex(".+\.[hc]pp$"))) { //work only with .cpp or .hpp files, exclude directories
            auto root = std::make_shared<DependencyNode>(file.path().filename().string());
            root->path_ = file.path().string();
            buildDependencyTree(root);
            dependency_roots_.push_back(root);

            writer.printTree(root);
        }
    }

    countFrequencies();
    sortFrequencies();
    writer.printFreq(std::make_shared<std::vector<std::pair<std::string, int>>>(files_freq_sorted));
}


void Analyzer::buildDependencyTree(std::shared_ptr<DependencyNode> node) {
    if (node->path_ == "") {
        node->path_ = seeker->getPathIfFileExist(node->name_);
    }
    
    if(node->path_ != "") {
        node->exist_ = true;
        std::vector<std::string> dependencies = seeker->getFileDependencies(node->path_);
        for (auto iter = dependencies.begin(); iter < dependencies.end(); iter++) {
            auto new_node_ptr = std::make_shared<DependencyNode>((*iter).substr(1, (*iter).size() - 2));
            new_node_ptr->parent_ = node;
            if (!isCyclicDependency(new_node_ptr)) { //Cyclic dependencies ignored in tree
                node->dependencies_.push_back(new_node_ptr);
                buildDependencyTree(new_node_ptr);
            }
        }
    }
    else {
        node->exist_ = false;
    }
}


bool Analyzer::isCyclicDependency(std::shared_ptr<DependencyNode> node) {
    auto name = node->name_;
    while (node->parent_ != nullptr) {
        node = node->parent_;
        if (node->name_ == name)
            return true;
    }
    return false;
}


void Analyzer::countFrequencies() {
    for (auto root : dependency_roots_) {
        auto file_iter = files_freq_.find(root->name_);
        if (file_iter == files_freq_.end())
            files_freq_.insert({ root->name_, 0 });

        for (auto node : root->dependencies_) {
            countFrequenciesInOne(node);
        }
    }
}


void Analyzer::sortFrequencies() {
    for (auto file : files_freq_) {
        files_freq_sorted.push_back(file);
    }

    std::sort(files_freq_sorted.begin(), files_freq_sorted.end(),
        [](auto a, auto b) {
            if (a.second == b.second)
                return a.first < b.first;
            else
                return a.second > b.second;
        });
}


void Analyzer::countFrequenciesInOne(std::shared_ptr<DependencyNode> branch) {
    auto file_iter = files_freq_.find(branch->name_);
    if (file_iter == files_freq_.end())
        files_freq_.insert({ branch->name_, 1 });
    else
        file_iter->second++;

    for (auto node : branch->dependencies_) {
        countFrequenciesInOne(node);
    }
}