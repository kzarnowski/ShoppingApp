//
// Created by krzys on 20.11.2020.
//

#include "ShoppingList.h"
#include "ProductByPieces.h"
#include "ProductByWeight.h"
#include "ProductByCapacity.h"
#include <iostream>
#include <utility>
#include "IOManager.h"
#include "Exceptions.h"

ShoppingList::ShoppingList(std::string  name) : _name(std::move(name)) {}

ShoppingList::ShoppingList(const ShoppingList &other) {
    *this = other;
}

ShoppingList::~ShoppingList() {
    for (Product* p : this->_items)
        delete p;
}

bool ShoppingList::isFull() const {
    return this->getSize() == maxSize;
}

void ShoppingList::addProduct() {
    if (this->isFull()) {
        throw ShoppingListOverflow();
    }
    std::string name = IOManager::readString("Product name");
    int unit = IOManager::readInt("Set unit: 1.pieces  2.grams  3.milliliters");
    int quantity;
    Product* p;
    switch (unit) {
        case 1:
            quantity = IOManager::readInt("How many pieces?");
            p = new ProductByPieces(name, quantity);
            break;
        case 2:
            quantity = IOManager::readInt("How many grams?");
            p = new ProductByWeight(name, quantity);
            break;
        case 3:
            quantity = IOManager::readInt("How many milliliters?");
            p = new ProductByCapacity(name, quantity);
            break;
        default:
            throw ActionOutOfRange("Wrong unit selected.");
    }
    this->_items.push_back(p);
}

void ShoppingList::addProduct(Product* p) {
    this->_items.push_back(p);
}

void ShoppingList::removeProduct() {
    if (this->getSize() == 0) {
        throw ProductOutOfRange("List is empty. No product to delete.");
    }
    int index = IOManager::readInt("Item index");
    if (index > this->getSize()) {
        throw ProductOutOfRange();
    }
    this->_items.erase(_items.begin()+index-1);
}

void ShoppingList::rename() {
    std::cout << "New list name: ";
    std::getline(std::cin, this->_name);
}

std::ostream &operator<<(std::ostream &os, const ShoppingList &sl) {
    os << sl._name << std::endl;
    os << "----------------\n";
    if (sl.getSize() == 0) {
        os << "Empty list";
    } else {
        int i = 1;
        for (Product* p : sl._items)
            os << i++ << ". " << *p;
    }
    return os;
}

ShoppingList & ShoppingList::operator=(ShoppingList const &other) {
    if (this == &other)
        return *this;

    // deallocate memory in overwritten object
    for (Product* p : this->_items)
        delete p;

    this->_items.clear();
    this->_name = other._name;
    for (Product* p : other._items) {
        // create new product depending on its type
        if (auto* pp = dynamic_cast<ProductByPieces*>(p)) {
            this->_items.push_back(new ProductByPieces(pp->getName(), pp->getQuantity()));
        } else if (auto* pw = dynamic_cast<ProductByWeight*>(p)){
            this->_items.push_back(new ProductByWeight(pw->getName(), pw->getQuantity()));
        } else if (auto* pc = dynamic_cast<ProductByCapacity*>(p)){
            this->_items.push_back(new ProductByCapacity(pc->getName(), pc->getQuantity()));
        }
    }
    return *this;
}

void ShoppingList::removeProduct(int index) {
    this->_items.erase(_items.begin()+index-1);
}

bool ShoppingList::mergeProduct(Product *p) const {
    for (Product* other : this->getItems()) {
        if (p->sameAs(other)) {
            other->addQuantity(p->getQuantity());
            return true;
        }
    }
    return false;
}









