//
// Created by Daniel Sterzel on 29/09/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <fstream>

class Parser {
public:
    Parser() = default;
    void read(const std::string& filepath);
    void openFile(const std::string& filepath);
    void viewMsg() const;
    std::string readRequestLine(const std::string& filepath);
    std::string returnString() const;
private:
    std::vector<std::string> parsedLines = {};
    std::ifstream file;

};



#endif //PARSER_H
