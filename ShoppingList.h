//
// Created by krzys on 20.11.2020.
//

#ifndef SHOPPINGAPP_SHOPPINGLIST_H
#define SHOPPINGAPP_SHOPPINGLIST_H

#include <string>
#include <vector>
#include "Product.h"


constexpr int maxSize = {10};

class ShoppingList {
    std::string _name;
    std::vector<Product*> _items;

public:
    explicit ShoppingList(std::string  name = "New list");
    ShoppingList(const ShoppingList & sl);
    ~ShoppingList();
    std::string getName() const { return this->_name;};
    std::vector<Product*> getItems() const { return _items;};
    int getSize() const { return this->_items.size();};

    bool isFull() const;
    void addProduct();
    void addProduct(Product* p);
    void removeProduct();
    void removeProduct(int index);
    void rename();
    bool mergeProduct(Product* p) const;

    ShoppingList & operator=(ShoppingList const & other);
    friend std::ostream & operator<<(std::ostream & os, const ShoppingList & sl);
};

#endif //SHOPPINGAPP_SHOPPINGLIST_H
