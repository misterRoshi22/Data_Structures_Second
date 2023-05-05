#ifndef DATA_STRUCTURES_PRACTICE_ORDEREDLIST_H
#define DATA_STRUCTURES_PRACTICE_ORDEREDLIST_H

#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template<class T>
class OrderedList {
private:
    Node<T> *head;
    Node<T> *tail;

    void add_tail(const T &val) {
        if (tail == nullptr) {
            head = tail = new Node<T>(val);
        } else {
            tail->next = new Node<T>(val, nullptr, tail);
            tail = tail->next;
        }
    }

    void add_head(const T &val) {
        if (head == nullptr) {
            head = tail = new Node<T>(val);
        } else {
            head->prev = new Node<T>(val, head, nullptr);
            head = head->prev;
        }
    }

    void remove_tail() {
        if (is_empty())
            throw string("LIST IS EMPTY");
        else if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T> *prev = tail->prev;
            delete tail;
            tail = prev;
            tail->next = nullptr;
        }
    }

    void remove_head() {
        if (is_empty())
            throw string("LIST IS EMPTY");
        else if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T> *next = head->next;
            delete head;
            head = next;
            head->prev = nullptr;
        }
    }

public:
    OrderedList() {
        head = tail = nullptr;
    }

    OrderedList(const OrderedList<T> &list) {
        head = tail = nullptr;
        this->append(list);
    }

    void clear() {
        while (!is_empty())
            remove_head();
    }


    ~OrderedList() {
        clear();
    }

    bool is_empty() const {
        return head == nullptr;
    }

    void append(const OrderedList<T> &list) {
        if (*this == list)
            throw string("CAN'T APPEND LIST TO ITSELF");
        Node<T> *curr = list.head;
        while (curr != nullptr) {
            this->insert(curr->data);
            curr = curr->next;
        }
    }

    void insert(const T &val) {
        if (is_empty())
            add_tail(val);
        else {
            if (val <= head->data)
                add_head(val);
            else if (val >= tail->data)
                add_tail(val);
            else {
                Node<T> *curr = head;
                while (val > curr->data)
                    curr = curr->next;
                Node<T> *prev = curr->prev;
                Node<T> *new_node = new Node<T>(val, curr, prev);
                prev->next = new_node;
                curr->prev = new_node;
            }
        }
    }

    void print() const {
        cout << "[";
        Node<T> *curr = head;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr)
                cout << ",";
            curr = curr->next;
        }
        cout << "]\n";
    }
};


#endif //DATA_STRUCTURES_PRACTICE_ORDEREDLIST_H
