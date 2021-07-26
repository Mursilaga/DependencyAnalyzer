#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler(int argc, char* argv[]) {
    if (argc % 2 != 0) {
        std::cout << "invalid parameters count!\n\n";
        printUsage();
    }
    else {
        sources_.push_back(argv[1]);
        for (int i = 3; i <= argc; i += 2) {
            additional_includes_.push_back(argv[i]);
        }
        //TODO check option, check path
    }
}


std::vector<std::string> InputHandler::getSources() {
    return sources_;
}


std::vector<std::string> InputHandler::getAdditionalIncludes() {
    return additional_includes_;
}


void InputHandler::printUsage() {
    std::cout << "usage:\n\
    analyzer <sources path> [options]\n\
    options:\n\
        -I - path for source files search\n\
    example:\n\
        DependencyAnalyzer.exe d:\\mysources\\ -I d:\\mysources\\includes -I d:\\mylibrary\n";
}