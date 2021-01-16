//
// Created by krzys on 21.11.2020.
//

#include "App.h"
#include <iostream>
#include "IOManager.h"

App::App() {
    this->_running = true;
}

void App::display() {
    // main menu
    std::cout << std::endl << "  Shopping App  " << std::endl;
    std::cout << "----------------\n";

    for (int i = 0; i<_sLists.size(); i++) {
        std::cout << i+1 << ". " << _sLists.get(i)->getName() << std::endl;
    }
    std::cout << "----------------\n"
                 "1. New list\n"
                 "2. Open list\n"
                 "3. Merge lists\n"
                 "4. Exit\n";
    manageAction();
}

void App::manageAction() {
    // manage user input from main menu
    int action = IOManager::readInt("Choose action");
    switch (action) {
        case 1:
            createList();
            break;
        case 2:
            openList();
            break;
        case 3:
            mergeLists();
            break;
        case 4:
            terminate(); // close app
            break;
        default:
            std::cout << "Wrong argument" << std::endl;
    }
}

void App::createList() {
    // action 1
    std::string name = IOManager::readString("Name");
    this->_sLists.add(new ShoppingList(name));
}

void App::openList() {
    // action 2 - display products and edit options
    if (this->_sLists.empty()) {
        std::cout << "No list to open." << std::endl;
        return;
    }
    int index = IOManager::readInt("Choose list number");
    if (index > this->_sLists.size()) {
        std::cout << "List does not exist." << std::endl;
        return;
    }
    ShoppingList* sl = this->_sLists.get(index-1);

    bool isOpen = true;
    while (isOpen) {
        std::cout << std::endl << *sl;
        std::cout << "\n----------------\n"
                     "1. Add product\n"
                     "2. Delete product\n"
                     "3. Rename list\n"
                     "4. Copy list\n"
                     "5. Delete list\n"
                     "6. Move product\n"
                     "7. Back\n";

        // manage opened list
        int action = IOManager::readInt("Choose action");
        switch (action) {
            case 1:
                sl->addProduct();
                break;
            case 2:
                sl->removeProduct();
                break;
            case 3:
                sl->rename();
                break;
            case 4:
                copyList(sl);
                isOpen = false;
                break;
            case 5:
                isOpen = !removeList(index);
                break;
            case 6:
                moveProduct(sl);
                break;
            case 7:
                isOpen = false;
                break;
            default:
                std::cout << "Wrong argument";
        }
    }
}

bool App::removeList(int index) {
    int confirm = IOManager::readInt("Are you sure?\n"
                    "1. Yes\t 2. No\n");
    if (confirm == 1) {
        // run ~ShoppingList() and remove item from vector
        this->_sLists.remove(index-1);
        //this->_sLists.erase(_sLists.begin()+index-1);
        return true;
    } else {
        return false;
    }
}

void App::removeListNoConfirm(int index) {
    this->_sLists.remove(index-1);
    //this->_sLists.erase(_sLists.begin()+index-1);
}

void App::copyList(ShoppingList* sl) {
    auto* cp = new ShoppingList(*sl);
    this->_sLists.add(cp);
}

void App::mergeLists() {
    if (this->_sLists.size() < 2) {
        std::cout << "There must be at least two lists to merge." << std::endl;
        return;
    }
    std::cout << "Choose list numbers to merge." << std::endl;
    int i1 = IOManager::readInt("List 1");
    int i2 = IOManager::readInt("List 2");
    ShoppingList* list1 = this->_sLists.get(i1 - 1);
    ShoppingList* list2 = this->_sLists.get(i2 - 1);

    if (list1 == list2) {
        std::cout << "Cannot merge list with itself." << std::endl;
        return;
    }

    list1->rename();
    int size = list2->getSize();
    for (int i = 0; i < size; i++) {
        moveProduct(list2, list1, 1);
        if (list1->isFull()) return;
    }

    removeListNoConfirm(i2);
}


void App::moveProduct(ShoppingList *from) {
    int p = IOManager::readInt("Choose product to move");
    int i = 1;
    for (int i=1; i<=_sLists.size(); i++) {
        std::cout << i++ << ". " << _sLists.get(i-1)->getName() << std::endl;
    }
    int index = IOManager::readInt("Choose destination list number");
    if (index > this->_sLists.size()) {
        std::cout << "List does not exist." << std::endl;
        return;
    }
    ShoppingList* dest = this->_sLists.get(index-1);
    moveProduct(from, dest, p);
}

bool App::moveProduct(ShoppingList *from, ShoppingList *dest, int index) {
    if(dest->isFull()) {
        std::cout << "Destination list is full. Cannot move product." << std::endl;
        return false;
    }

    if(!dest->mergeProduct(from->getItems().at(index-1))) {
        dest->addProduct(from->getItems().at(index-1));
    }
    from->removeProduct(index);
    return true;
}
