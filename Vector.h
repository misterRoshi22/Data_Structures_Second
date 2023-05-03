//
// Created by shaba on 03/05/2023.
//

#ifndef DATA_STRUCTURES_PRACTICE_VECTOR_H
#define DATA_STRUCTURES_PRACTICE_VECTOR_H

#include <iostream>

using namespace std;

template<class T>
class Vector {
private:
    T *data;
    int capacity;
    int size;

    bool is_full() const;

    void resize();

public:
    Vector();

    Vector(const Vector &other);

    ~Vector();

    void push_back(const T &val);

    void pop_back();

    void psuh_front(const T &val);

    void pop_front();

    void insert(int index, const T &val);

    void remove(int index);

    void clear();

    int get_size() const;

    int get_capacity() const;

    bool is_empty() const;

    T &operator[](int index);

    Vector &operator=(const Vector &other);

    void print() const;
};


#endif //DATA_STRUCTURES_PRACTICE_VECTOR_H
