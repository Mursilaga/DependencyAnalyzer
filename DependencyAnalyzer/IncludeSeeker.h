#pragma once
#include <vector>
#include <string>

class IncludeSeeker {

public:
    IncludeSeeker() {};
    ~IncludeSeeker() {};

    std::vector<std::string> getFileDependencies(std::string file_name);
    std::string getPathIfFileExist(std::string file_name, std::vector<std::string> directories_for_seek);
};

