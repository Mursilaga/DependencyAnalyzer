#pragma once

#include "DependencyNode.h"
#include "IncludeSeeker.h"

#include <map>

class Analyzer {

public:
    Analyzer() {};
    ~Analyzer() {};

    void exec(int argc, char* argv[]);


private:
    std::map<std::string, unsigned> files_freq_;
    std::unique_ptr<IncludeSeeker> seeker;
    std::vector<std::shared_ptr<DependencyNode>> dependency_roots_;

    void buildDependencyTree(std::shared_ptr<DependencyNode> node);
    void countFrequencies();
    void countFrequenciesInOne(std::shared_ptr<DependencyNode> branch);
};

