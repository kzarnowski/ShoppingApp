//
// Created by krzysztof on 28.12.2020.
//

#include "ProductByWeight.h"
#include "IOManager.h"

ProductByWeight::ProductByWeight(const std::string &name, int weight) : Product(name, weight) {}

std::string ProductByWeight::quantityToString() const {
    std::string res;
    if (_quantity < 1000) {
        res = std::to_string(_quantity);
        res += " gr";
    } else {
        res = std::to_string(_quantity/1000);
        res += ".";
        res += std::to_string(_quantity%1000);
        res += " kg";
    }
    return res;
}

ProductByWeight::ProductByWeight() {
    _name = IOManager::readString("Product name");
    _quantity = IOManager::readInt("How many grams?");
}
