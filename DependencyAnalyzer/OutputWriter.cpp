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


void OutputWriter::printFreq(std::shared_ptr<std::map<std::string, unsigned>> files_freq) {
    std::cout << std::endl;
    for (auto file : *files_freq) {
        std::cout << file.first << " " << file.second << std::endl;
    }
}