//
// Created by Daniel Sterzel on 29/09/2025.
//

#include "Parser.h"
#include <iostream>

void Parser::openFile(const std::string& filepath) {
    if (file.is_open()) {
        file.close();
    }

    file.open(filepath);
    if (!file) {
        std::cerr << "Failed to open the file\n";
    }
}


void Parser::read(const std::string& filepath) {

    openFile(filepath);

    std::string line;
    while (std::getline(file, line)) {
        parsedLines.emplace_back(line);
    }
}

std::string Parser::readRequestLine(const std::string& filepath) {
    openFile(filepath);
    std::string requestLine;
    std::getline(file, requestLine);
    return requestLine;
}

void Parser::viewMsg() const{
    for (auto& line: parsedLines) {
        std::cout << line << "\n";
    }
}
std::string Parser::returnString() const{
    std::string returnStringObject;
    for (auto& line: parsedLines) {
        returnStringObject.append(line).append("\n");
    }
    return returnStringObject;
}

