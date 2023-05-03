//
// Created by shaba on 03/05/2023.
//

#ifndef DATA_STRUCTURES_PRACTICE_STACKLIST_H
#define DATA_STRUCTURES_PRACTICE_STACKLIST_H

#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template<class T>
class StackList {
private:
    List<T> list;
public:
    StackList() {}; // default constructor

    ~StackList() {}; // destructor

    StackList(const StackList<T> &other) {
        list = other.list;
    }

    void push(const T &val) {
        list.add_tail(val);
    }

    T pop() {
        if (list.is_empty()) throw string("Stack is empty");
        T val = list.tail_val();
        list.remove_tail();
        return val;
    }

    void clear() {
        list.clear();
    }

    int get_size() const {
        return list.size();
    }

    T get_top() const {
        return list.tail_val();
    }

    bool is_empty() const {
        return list.is_empty();
    }

    StackList<T> &operator=(const StackList<T> &other) {
        list = other.list;
        return *this;
    }

    void print() const {
        list.print();
    }

};

#endif //DATA_STRUCTURES_PRACTICE_STACKLIST_H
