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
    bool inside_multistring_comment = false;

    if (input.is_open()) {
        while (std::getline(input, line)) {
            line = std::regex_replace(line, std::regex("/\\*.*\\*/"), ""); //cut comment in one string like /*comment*/

            if (inside_multistring_comment) { //cut comment in the beginning of line
                auto end_comment_pos = line.find("*/");
                if (end_comment_pos != std::string::npos) {
                    inside_multistring_comment = false;
                    line = line.substr(end_comment_pos + 2);
                }
                else {
                    line = ""; //all line is inside multi string comment
                }
            }

            if (!inside_multistring_comment) { //cut comment in the ending of line
                auto comment_pos = line.find("\*");
                if (comment_pos != std::string::npos) {
                    inside_multistring_comment = true;
                    line = line.substr(0, comment_pos - 1);
                }
            }

            if (std::regex_search(line, std::regex("^#include *[<\"].+\.[hc]pp[>\"]$"))) {
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
