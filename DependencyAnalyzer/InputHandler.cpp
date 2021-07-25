#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler(int argc, char* argv[]) {
    if (argc % 2 != 0) {
        std::cout << "invalid parameters count!\n\n";
        printUsage();
    } 
}


void InputHandler::printUsage() {
    std::cout << "usage:\n\
    analyzer <sources path> [options]\n\
    options:\n\
        -I - path for source files search\n\
    example:\n\
        DependencyAnalyzer.exe d:\\mysources\\ -I d:\\mysources\\includes -I d:\\mylibrary\n";
}