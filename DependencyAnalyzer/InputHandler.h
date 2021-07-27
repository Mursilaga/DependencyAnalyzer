#pragma once
#include <vector>
#include <string>
#include <memory>

class InputHandler {

public:
    InputHandler(int argc, char* argv[]);
    ~InputHandler() {};

    void printUsage();
    std::vector<std::string> getSources();
    std::vector<std::string> getAdditionalIncludes();

private:
    std::vector<std::string> sources_;
    std::vector<std::string> additional_includes_;
};

