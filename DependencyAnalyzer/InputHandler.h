#pragma once
#include <vector>
#include <string>
#include <memory>

class InputHandler {

public:
    InputHandler() {};
    ~InputHandler() {};

    void handle(int argc, char* argv[]);
    bool isValid();
    std::string getRootDir();
    std::vector<std::string> getAdditionalIncludes();

private:
    bool input_validation_ = false;
    std::string root_dir_;
    std::vector<std::string> additional_includes_;
};

