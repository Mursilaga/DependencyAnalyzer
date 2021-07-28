#include "InputHandler.h"
#include <iostream>


void InputHandler::handle(int argc, char* argv[]) {
    if (argc % 2 != 0) {
        input_validation_ = false;
        return;
    }

    for (int i = 2; i < argc; i += 2) {
        if (std::string(argv[i]) != "-I") {
            input_validation_ = false;
            return;
        }
    }

    root_dir_ = argv[1];
    for (int i = 3; i < argc; i += 2) {
        additional_includes_.push_back(argv[i]);
    }
    input_validation_ = true;
}


bool InputHandler::isValid() {
    return input_validation_;
}


std::string InputHandler::getRootDir() {
    return root_dir_;
}


std::vector<std::string> InputHandler::getAdditionalIncludes() {
    return additional_includes_;
}