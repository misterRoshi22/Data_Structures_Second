#ifndef DATA_STRUCTURES_PRACTICE_STACKARRAY_H
#define DATA_STRUCTURES_PRACTICE_STACKARRAY_H

#include <iostream>
#include "QueueArray.h"

using namespace std;

template<class T>
class StackArray {
private:
    T *data;
    size_t last;
    size_t capacity;

    void resize(size_t capacity) {
        if (capacity <= last)
            throw string("INVALID CAPACITY");
        T *temp = new T[capacity];
        for (int i = 0; i <= last; ++i) {
            temp[i] = data[i];
        }
        delete data;
        data = temp;
        this->capacity = capacity;
    }

    bool is_full() const { return last + 1 == capacity; }

public:
    StackArray() {
        data = new T[DEFAULT_CAPACITY];
        last = -1;
        capacity = DEFAULT_CAPACITY;
    }

    StackArray(const StackArray &other) {
        data = new T[other.capacity];
        last = other.last;
        capacity = other.capacity;
        for (int i = 0; i <= last; ++i) {
            data[i] = other.data[i];
        }
    }

    ~StackArray() { delete data; }

    void push(const T &val) {
        if (is_full()) resize(2 * capacity);
        data[++last] = val;
    }

    T pop() {
        if (is_empty()) throw string("EMPTY LIST");
        T val = data[last--];
        if (last + 1 == capacity / 4) resize(capacity / 2);
        return val;
    }

    void clear() {
        last = -1;
        resize(DEFAULT_CAPACITY);
    }

    size_t get_size() const { return last + 1; }

    T get_top() const {
        if (is_empty()) throw string("EMPTY LIST");
        return data[last];
    }

    bool is_empty() const { return last == -1; }

    StackArray<T> &operator=(const StackArray &other) {
        if (this == &other) return *this;
        delete data;
        data = new T[other.capacity];
        last = other.last;
        capacity = other.capacity;
        for (int i = 0; i <= last; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    void print() const {
        cout << "[";
        for (int i = 0; i <= last; ++i) {
            cout << data[i];
            if (i != last) cout << ",";
        }
        cout << "]" << endl;
    }

};

#endif //DATA_STRUCTURES_PRACTICE_STACKARRAY_H
