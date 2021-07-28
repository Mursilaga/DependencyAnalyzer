#pragma once
#include "DependencyNode.h"
#include <map>

class OutputWriter {

public:
    OutputWriter() {};
    ~OutputWriter() {};

    void printTree(std::shared_ptr<DependencyNode> node);
    void printFreq(std::shared_ptr<std::map<std::string, unsigned>> files_freq);
    void printUsage();

private:
    void printNodeWithChilds(std::shared_ptr<DependencyNode> node, int deep);
};

