#pragma once
#include <vector>
#include <string>

class IncludeSeeker {

public:
    IncludeSeeker(std::vector<std::string> src, std::vector<std::string> additional);
    ~IncludeSeeker() {};

    std::vector<std::string> getFileDependencies(std::string file_name);
    std::string getPathIfFileExist(std::string file_name);

private:
    std::vector<std::string> sources_;
    std::vector<std::string> additional_includes_;
};
