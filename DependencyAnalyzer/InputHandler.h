#pragma once
#include <vector>

class InputHandler
{
public:
    InputHandler(int argc, char* argv[]);
    ~InputHandler() {};

    void printUsage();


    std::vector<std::string> sources_;
    std::vector<std::string> additional_includes_;
};

