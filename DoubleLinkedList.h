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

    Node<T> *get_head() const {
        return head;
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
            Node<T> *new_node = new Node<T>(data, head, nullptr);
            head->prev = new_node;
            head = new_node;
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

    void insert_after(const T &val1, const T &val2) {
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (curr->data == val2) break;
            curr = curr->next;
        }
        if (curr == nullptr || curr == tail)
            add_tail(val1);
        else {
            Node<T> *next = curr->next;
            Node<T> *new_node = new Node<T>(val1, next, curr);
            curr->next = new_node;
            next->prev = new_node;
        }
    }

    void remove_from(int index, int count) {
        size_t size = 0;
        for (Node<T> *curr = head; curr != nullptr; curr = curr->next, size++);
        if (index < 0 || index >= size || count < 0)
            throw string("INVALID PARAMETERS");

        Node<T> *curr = head;
        while (index--) curr = curr->next;
        while (count-- && curr != nullptr) {
            Node<T> *temp = curr->next;
            remove_node(curr);
            curr = temp;
        }
    }

    void append_list_after(Node<T> *node, const List &l1) {
        if (node == nullptr) {
            Node<T> *curr = l1.tail;
            while (curr) {
                this->add_head(curr->data);
                curr = curr->prev;
            }
        } else {
            Node<T> *curr = node;
            Node<T> *next = node->next;
            Node<T> *insert_node = l1.head;
            while (insert_node != nullptr) {
                Node<T> *new_node = new Node<T>(insert_node->data, next, curr);
                curr->next = new_node;
                next->prev = new_node;
                insert_node = insert_node->next;
                curr = new_node;
                cout << 1;
            }
        }
    }

    bool is_valid(const List &l2, Node<T> *node) {
        if (node != nullptr && node->data == l2.head->data)
            if (node->next != nullptr && node->next->data == l2.head->next->data)
                return true;
        return false;
    }

    Node<T> *delete_2_nodes(Node<T> *node) {
        if (node == nullptr)
            throw string("WTF");
        if (node == head) {
            remove_head();
            remove_head();
            nullptr;
        } else {
            Node<T> *prev = node->prev;
            Node<T> *next = node->next->next->next;
            delete node->next;
            delete node;
            prev->next = next;
            next->prev = prev;
            return prev;
        }
    }


    void replace_sublist(const List &l2, const List &l3) {
        Node<T> *curr = head;
        int i = 0;
        while (curr != nullptr && i != 50) {
            Node<T> *temp = curr->next;
            if (is_valid(l2, curr)) {
                curr = delete_2_nodes(curr);
                this->append_list_after(curr->prev, l3);
            }
            curr = temp;
            // cout << curr->data << endl;
            i++;
        }

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
