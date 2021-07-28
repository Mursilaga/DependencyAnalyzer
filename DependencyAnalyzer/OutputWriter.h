#pragma once
#include "DependencyNode.h"
#include <map>

class OutputWriter {

public:
    OutputWriter() {};
    ~OutputWriter() {};

    void printTree(std::shared_ptr<DependencyNode> node);
    void printFreq(std::shared_ptr<std::vector<std::pair<std::string, int>>> files_freq);
    void printUsage();

private:
    void printNodeWithChilds(std::shared_ptr<DependencyNode> node, int deep);
};

