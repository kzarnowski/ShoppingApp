//
// Created by krzysztof on 28.12.2020.
//

#include "ProductByPieces.h"
#include "IOManager.h"

ProductByPieces::ProductByPieces(const std::string &name, int pieces) : Product(name, pieces) {}

std::string ProductByPieces::quantityToString() const {
    std::string res = std::to_string(_quantity);
    res += " pcs";
    return res;
}

ProductByPieces::ProductByPieces() {
    _name = IOManager::readString("Product name");
    _quantity = IOManager::readInt("How many pieces?");
}
