//
// Created by krzys on 22.11.2020.
//

#include "IOManager.h"
#include <iostream>

int IOManager::readInt(const std::string & message) {
    std::cout << message << ": ";
    std::string input;
    std::getline(std::cin, input);
    return atoi(input.c_str());
}

std::string IOManager::readString(const std::string & message) {
    std::cout << message << ": ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}
