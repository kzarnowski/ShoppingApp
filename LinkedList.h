//
// Created by krzysztof on 16.01.2021.
//

#ifndef ZARNOWSKIKRZYSZTOF_ETAP3_LINKEDLIST_H
#define ZARNOWSKIKRZYSZTOF_ETAP3_LINKEDLIST_H
#include <iostream>

template<class T> class LinkedList;
template<typename T> std::ostream& operator<< (std::ostream& os, const LinkedList <T>& l);

template<class T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template<class T>
class LinkedList {
    Node<T>* _head;
    Node<T>* _end;
    int _size;

public:
    LinkedList();
    ~LinkedList();

    bool empty() const;
    T get(int index);
    void add(T item);
    void remove(int index);
    friend std::ostream& operator<< <> (std::ostream& os, const LinkedList<T>& l);
    int size();
private:
    Node<T>* getNode(int index) const;
};

template<class T>
LinkedList<T>::LinkedList() {
    _head = nullptr;
    _end = nullptr;
    _size = 0;
}

template<class T>
bool LinkedList<T>::empty() const {
    return _size == 0;
}

template<class T>
T LinkedList<T>::get(int index) {
    return getNode(index)->data;
}

template<class T>
void LinkedList<T>::add(T item) {
    // add new item at the end of the list
    auto* p = new Node<T>;
    p->data = item;
    p->next = nullptr;
    p->prev = _end;
    if (_size == 0)  {
        _head = p;
        _end = p;
    } else {
        _end->next = p;
        _end = p;
    }
    _size++;
}

template<class T>
void LinkedList<T>::remove(int index) {
    if (index >= _size || index < 0) {
        return; // THROW EXCEPTION
    } else if (index == 0 && _size == 1) {
        // remove the only one
        delete _head->data;
        _head = nullptr;
        _end = nullptr;
        _size = 0;
    } else if (index == 0) {
        // remove first
        delete _head->data;
        _head->next->prev = nullptr;
        _head = _head->next;
        _size--;
    } else if (index == _size - 1) {
        // remove last
        delete _end->data;
        _end->prev->next = nullptr;
        _end = _end->prev;
        _size--;
    } else {
        // remove from inside
        Node<T>* r = getNode(index);
        delete r->data;
        r->prev->next = r->next;
        r->next->prev = r->prev;
        _size--;
    }

}

template<class T>
Node<T> *LinkedList<T>::getNode(int index) const {
    if (index >= _size || index < 0) {
        return nullptr; // THROW EXCEPTION
    }

    Node<T>* p = _head;
    for(int i=0; i<index; i++) {
        p = _head->next;
    }
    return p;
}

template<class T>
LinkedList<T>::~LinkedList() {
    while(!this->empty()) {
        remove(0);
    }
}

//template<class T>
//std::string LinkedList<T>::toString() const {
//    std::string res;
//    if (this->empty()) {
//        res = "Empty list\n";
//    } else {
//        Node<T>* p = _head;
//        while (p) {
//            res += p->data;
//            res += '\n';
//            p = p->next;
//        }
//    }
//    return res;
//}

template<class T>
std::ostream& operator<< (std::ostream& os, const LinkedList<T>& l) {
    if (l.empty()) {
        os << "Empty list" << std::endl;
    } else {
        Node<T>* p = l._head;
        while (p) {
            os << p->data << std::endl;
            p = p->next;
        }
    }
    return os;
}

template<class T>
int LinkedList<T>::size() {
    return _size;
}

#endif //ZARNOWSKIKRZYSZTOF_ETAP3_LINKEDLIST_H
