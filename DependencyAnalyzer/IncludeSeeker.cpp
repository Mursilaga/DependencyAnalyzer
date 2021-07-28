#include "IncludeSeeker.h"
#include <fstream>
#include <regex>


IncludeSeeker::IncludeSeeker(std::string root_dir, std::vector<std::string> additional) {
    root_dir_ = root_dir;
    additional_includes_ = additional;
}


std::vector<std::string> IncludeSeeker::getFileDependencies(std::string path) {
    std::ifstream input(path);
    std::string line;
    std::vector<std::string> result;
    if (input.is_open()) {
        std::regex rex("^#include *[<\"].+\.[hc]pp[>\"]$"); //TODO catch multistring comment
        while (std::getline(input, line)) {
            if (std::regex_search(line, rex)) {
                std::size_t pos = line.find("\"");
                if(pos == std::string::npos)
                    pos = line.find("<");
                result.push_back(line.substr(pos));
            }
        }
        input.close();
    }

    return result;
}

std::string IncludeSeeker::getPathIfFileExist(std::string file_name) {
    std::vector<std::string> directories_for_seek;
    if (file_name.find("<") != std::string::npos)
        directories_for_seek = additional_includes_;
    else
        directories_for_seek = { root_dir_ };
    
    std::string result = "";
    for (auto iter = directories_for_seek.begin(); iter < directories_for_seek.end(); iter++) {
        result = *iter + "\\" + file_name;
        std::ifstream input(result);
        if (input.is_open()) {
            input.close();
            return result;
        }
        else {
            result = "";
        }
    }
    return result;
}
