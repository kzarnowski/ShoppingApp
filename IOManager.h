//
// Created by krzys on 22.11.2020.
//

#ifndef SHOPPINGAPP_IOMANAGER_H
#define SHOPPINGAPP_IOMANAGER_H

#include <string>

class IOManager {
    //manage console input-output
public:
    static int readInt(const std::string & message);
    static std::string readString(const std::string &  message);
};

#endif //SHOPPINGAPP_IOMANAGER_H