#pragma once

#include <vector>
#include <string>
#include <memory>

class DependencyNode {

public:
    DependencyNode(std::string name) {
        name_ = name;
    }

    bool in_additional_dirs_ = false;
    bool exist_ = false;
    std::string name_;
    std::string path_;
    std::shared_ptr<DependencyNode> parent_ = nullptr;
    std::vector<std::shared_ptr<DependencyNode>> dependencies_;
};

