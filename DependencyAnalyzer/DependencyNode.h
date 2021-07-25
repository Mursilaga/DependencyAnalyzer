#pragma once

#include <vector>
#include <string>
#include <memory>

class DependencyNode
{
public:
    DependencyNode(std::string path) {
        path_ = path;
    }

    std::string path_;
    std::vector<std::unique_ptr<DependencyNode>> dependencies_;
};

