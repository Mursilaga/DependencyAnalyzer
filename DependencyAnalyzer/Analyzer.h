#pragma once

#include "DependencyNode.h"
#include "IncludeSeeker.h"

#include <map>

class Analyzer {

public:
    Analyzer(std::vector<std::string> src, std::vector<std::string> additional);
    ~Analyzer() {};

    void exec();
    void buildDependencyTree(std::shared_ptr<DependencyNode> node);
    void countFrequencies();

private:
    std::string root_dir_;
    std::map<std::string, unsigned> files_freq_;
    std::unique_ptr<IncludeSeeker> seeker;
    std::vector<std::shared_ptr<DependencyNode>> dependency_roots_;

    void countFrequenciesInOne(std::shared_ptr<DependencyNode> branch);
};

