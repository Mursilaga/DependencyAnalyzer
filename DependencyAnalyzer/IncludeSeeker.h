#pragma once
#include <vector>
#include <string>

class IncludeSeeker {

public:
    IncludeSeeker(std::string src, std::vector<std::string> additional);
    ~IncludeSeeker() {};

    std::vector<std::string> getFileDependencies(std::string file_name);
    std::string getPathIfFileExist(std::string file_name);

private:
    std::string root_dir_;
    std::vector<std::string> additional_includes_;
};

