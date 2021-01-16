//
// Created by krzysztof on 28.12.2020.
//

#include "ProductByCapacity.h"
#include "IOManager.h"

ProductByCapacity::ProductByCapacity(const std::string &name, int capacity) : Product(name, capacity){}

std::string ProductByCapacity::quantityToString() const {
    std::string res;
    if (_quantity < 1000) {
        res = std::to_string(_quantity);
        res += " ml";
    } else {
        res = std::to_string(_quantity/1000);
        res += ".";
        res += std::to_string(_quantity%1000);
        res += " l";
    }
    return res;
}

ProductByCapacity::ProductByCapacity() {
    _name = IOManager::readString("Product name");
    _quantity = IOManager::readInt("How many milliliters?");
}
