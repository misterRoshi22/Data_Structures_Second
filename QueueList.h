#ifndef DATA_STRUCTURES_PRACTICE_QUEUELIST_H
#define DATA_STRUCTURES_PRACTICE_QUEUELIST_H

#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template<class T>
class QueueList {
private:
    List<T> list;
public:
    QueueList() {};

    QueueList(const QueueList<T> &other) {
        list = other.list;
    }

    ~QueueList() {};

    void enqueue(const T &val) {
        list.add_tail(val);
    }

    T dequeue() {
        if (list.is_empty())
            throw string("QUEUE IS EMPTY");
        T val = list.head_val();
        list.remove_head();
        return val;
    }

    void clear() {
        list.clear();
    }

    size_t get_size() const {
        return list.size();
    }

    T get_front() const {
        return list.head_val();
    }

    T get_last() const {
        return list.tail_val();
    }

    bool is_empty() const {
        return list.is_empty();
    }

    QueueList<T> &operator=(const QueueList<T> &other) {
        list = other.list;
        return *this;
    }

    void print() const {
        list.print();
    }

    void postpone() {
        if (list.is_empty()) return;
        T old_head = this->dequeue();
        T new_head = this->dequeue();
        list.add_head(old_head);
        list.add_head(new_head);
    }
};

template<class T>
void remove_all(QueueList<T> &queueList, T val) {
    QueueList<T> temp;
    while (!queueList.is_empty()) {
        T current = queueList.dequeue();
        if (current != val) {
            temp.enqueue(current);
        }
    }
    queueList = temp;
}

template<class T>
void move_first_to(QueueList<T> &queueList, int pos) {
    if (queueList.is_empty())
        throw string("QUEUE IS EMPTY");
    int size = queueList.get_size();
    T old_head = queueList.dequeue();
    QueueList<T> temp;
    for (int i = 0; i < size; i++) {
        if (i == pos) {
            temp.enqueue(old_head);
        } else temp.enqueue(queueList.dequeue());
    }
    queueList = temp;

}

#endif //DATA_STRUCTURES_PRACTICE_QUEUELIST_H
