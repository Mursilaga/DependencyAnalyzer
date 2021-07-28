#include "OutputWriter.h"
#include <iostream>

void OutputWriter::printTree(std::shared_ptr<DependencyNode> node) {
    printNodeWithChilds(node, 0);
}


void OutputWriter::printNodeWithChilds(std::shared_ptr<DependencyNode> node, int deep) {
    std::cout << std::string(deep*2, '.') + node->name_ << (node->exist_ ? "" : " (!)") << std::endl;
    for (auto n : node->dependencies_) {
        printNodeWithChilds(n, deep+1);
    }
}


void OutputWriter::printFreq(std::shared_ptr<std::vector<std::pair<std::string, int>>> files_freq) {
    std::cout << std::endl;
    for (auto file : *files_freq) {
        std::cout << file.first << " " << file.second << std::endl;
    }
}


void OutputWriter::printUsage() {
    std::cout << "\nusage:\n\
    DependencyAnalyzer.exe <sources path> [options]\n\
    options:\n\
        -I - path for source files search\n\
    example:\n\
        DependencyAnalyzer.exe d:\\mysources\\ -I d:\\mysources\\includes -I d:\\mylibrary\n";
}