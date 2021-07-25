#pragma once

#include "DependencyNode.h"

class Analyzer
{
public:
    Analyzer() {};
    ~Analyzer() {};

    std::unique_ptr<DependencyNode> dependency_root_;
};

