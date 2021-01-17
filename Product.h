//
// Created by krzys on 20.11.2020.
//

#ifndef SHOPPINGAPP_PRODUCT_H
#define SHOPPINGAPP_PRODUCT_H

#include <string>

class Product {
protected:
    std::string _name;
    int _quantity;

public:
    explicit Product(std::string  name = "New product", int quantity = 1);
    std::string getName() const { return this->_name;};
    int getQuantity() const { return _quantity; };
    void addQuantity(int q);
    virtual std::string quantityToString() const = 0;
    friend std::ostream & operator<<(std::ostream &os, const Product & p);
    virtual ~Product() = default;
    bool sameAs(Product* other);
};

#endif //SHOPPINGAPP_PRODUCT_H