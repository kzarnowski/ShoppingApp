//
// Created by krzys on 20.11.2020.
//

#include <iostream>
#include "Product.h"

Product::Product(const std::string & name, int quantity) : _name(name), _quantity(quantity) {}

std::ostream &operator<<(std::ostream &os, const Product &p) {
    os << p._name << " : " << p.quantityToString() << std::endl;
    return os;
}

bool Product::sameAs(Product *other) {
    return this->getName() == other->getName() && typeid(*this) == typeid(*other);
}

void Product::addQuantity(int q) {
    _quantity += q;
}
