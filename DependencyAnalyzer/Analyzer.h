#pragma once

#include "DependencyNode.h"
#include "IncludeSeeker.h"

class Analyzer
{
public:
    Analyzer(std::vector<std::string> src, std::vector<std::string> additional);
    ~Analyzer() {};

    void start();
    void buildDependencyTree(std::shared_ptr<DependencyNode> node);

private:
    std::unique_ptr<DependencyNode> dependency_root_;
    std::unique_ptr<IncludeSeeker> seeker;
};

