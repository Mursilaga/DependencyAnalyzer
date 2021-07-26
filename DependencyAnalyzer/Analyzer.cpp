#include "Analyzer.h"

Analyzer::Analyzer(std::vector<std::string> src, std::vector<std::string> additional) {
    dependency_root_ = std::make_unique<DependencyNode>(src[0]);
    seeker = std::make_unique<IncludeSeeker>(src, additional);
}


void Analyzer::start() {
    auto root = std::make_shared<DependencyNode>("\"test.cpp\""); //TODO build trees for all directory
    buildDependencyTree(root);

}


void Analyzer::buildDependencyTree(std::shared_ptr<DependencyNode> node) {
    node->path_ = seeker->getPathIfFileExist(node->name_);
    if(node->path_ != "") {
        node->exist_ = true;
        std::vector<std::string> dependencies = seeker->getFileDependencies(node->path_);
        for (auto iter = dependencies.begin(); iter < dependencies.end(); iter++) {
            auto new_node_ptr = std::make_shared<DependencyNode>(*iter);
            node->dependencies_.push_back(new_node_ptr);
            buildDependencyTree(new_node_ptr);
        }
    }
    else {
        node->exist_ = false;
    }

}