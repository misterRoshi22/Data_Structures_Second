#include <iostream>


#ifndef DATA_STRUCTURES_PRACTICE_DOUBLELINKEDLIST_H
#define DATA_STRUCTURES_PRACTICE_DOUBLELINKEDLIST_H
using namespace std;


template<class T>
class List;

template<class T>
class OrderedList;

template<class T>
class Node {
private:
    T data;
    Node<T> *next;
    Node<T> *prev;
public:
    Node(T data, Node<T> *next = nullptr, Node<T> *prev = nullptr) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    T val() const {
        return data;
    }

    Node *get_next() const {
        return next;
    }

    friend class List<T>;

    friend class OrderedList<T>;
};

template<class T>
class List {
private:
    Node<T> *head;
    Node<T> *tail;

    void remove_node(Node<T> *node) {
        if (node == head) remove_head();
        else if (node == tail) remove_tail();
        else {
            Node<T> *next = node->next;
            Node<T> *prev = node->prev;
            delete node;
            next->prev = prev;
            prev->next = next;
        }
    }

public:
    List() {
        head = tail = nullptr;
    }

    List(const List<T> &list) {
        Node<T> *curr = list->head;
        while (curr != nullptr) {
            add_tail(curr->data);
            curr = curr->next;
        }
    }

    ~List() {
        clear();
    }

    T head_val() const {
        return head->data;
    }

    T tail_val() const {
        return tail->data;
    }

    void add_tail(T data) {
        Node<T> *new_node = new Node<T>(data, nullptr, tail);
        if (is_empty())
            head = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void add_head(T data) {
        if (is_empty())
            add_tail(data);
        else {
            Node<T> *new_node = new Node<T>(data, nullptr, tail);
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print(char extra = '\n') const {
        Node<T> *curr = head;
        cout << "[";
        while (curr != nullptr) {
            cout << curr->data;
            if (curr != tail) cout << ",";
            curr = curr->next;
        }
        cout << "]" << extra;
    }

    void print_reverse(char extra = '\n') {
        Node<T> *curr = tail;
        cout << "[";
        while (curr != nullptr) {
            cout << curr->data;
            if (curr != head) cout << ",";
            curr = curr->prev;
        }
        cout << "]" << extra;
    }

    void remove_head() {
        if (is_empty())
            throw string("EMPTY LIST");
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
    }

    void remove_tail() {
        if (is_empty())
            throw string("EMPTY LIST");
        if (head == tail)
            remove_head();
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }


    void remove_all(T data) {
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (curr->data == data) {
                Node<T> *temp = curr;
                curr = curr->next;
                remove_node(temp);
            } else {
                curr = curr->next;
            }
        }
        if (tail->data == data) remove_tail();
    }

    bool is_empty() const { return head == nullptr; }

    bool search(T data) const {
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (curr->data == data) return true;
            curr = curr->next;
        }
        return false;
    }

    int size() const {
        int count = 0;
        Node<T> *curr = head;
        for (; curr != nullptr; curr = curr->next, count++);
        return count;
    }

    void clear() {
        Node<T> *curr = head;
        while (curr != nullptr) {
            Node<T> *temp = curr;
            curr = curr->next;
            remove_node(temp);
        }
    }

    void append(const List &list) {
        if (this == &list)
            throw string("CAN'T APPEND TO ITSELF");
        Node<T> *curr = list.head;
        while (curr != nullptr) {
            add_tail(curr->data);
            curr = curr->next;
        }
    }

    List<T> &operator=(const List &list) {
        if (this == &list)
            return *this;
        this->clear();
        this->append(list);
        return *this;
    }

    template<class K>
    friend ostream &operator<<(ostream &os, const List<K> &list);
};

template<class K>
ostream &operator<<(ostream &os, const List<K> &list) {
    Node<K> *curr = list.head;
    os << "[";
    while (curr != nullptr) {
        os << curr->val();
        if (curr != list.tail) os << ",";
        curr = curr->get_next();
    }
    os << "]";
    return os;
}

#endif //DATA_STRUCTURES_PRACTICE_DOUBLELINKEDLIST_H
