//
// Created by krzys on 21.11.2020.
//

#ifndef SHOPPINGAPP_APP_H
#define SHOPPINGAPP_APP_H


#include <vector>
#include "ShoppingList.h"
#include "LinkedList.h"

class App {
    LinkedList<ShoppingList*> _sLists;
    bool _running;

public:
    App();
    void createList();
    bool removeList(int index);
    void removeListNoConfirm(int index);
    void openList();
    void display();
    bool isRunning() const { return _running;};
private:
    void manageAction();
    void terminate() { _running = false;};
    void copyList(ShoppingList* sl);
    void mergeLists();
    void moveProduct(ShoppingList *from);
    bool moveProduct(ShoppingList *from, ShoppingList* dest, int index);
};

#endif //SHOPPINGAPP_APP_H
