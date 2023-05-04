#ifndef DATA_STRUCTURES_PRACTICE_BST_H
#define DATA_STRUCTURES_PRACTICE_BST_H

#include <iostream>

using namespace std;

template<class T>
class BST; // forward declaration

template<class T>
class BSTNode {
private:
    T val;
    BSTNode<T> *left;
    BSTNode<T> *right;
public:
    BSTNode(T val, BSTNode<T> *left = nullptr, BSTNode<T> *right = nullptr) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    T get_val() { return val; }

    BSTNode<T> *get_left() { return left; }

    BSTNode<T> *get_right() { return right; }

    friend class BST<T>;
};

template<class T>
class BST {
private:
    BSTNode<T> *root;

    bool search(const T &val, BSTNode<T> *node) const {
        if (node == nullptr)
            return false;
        if (node->val == val)
            return true;
        if (val > node->val)
            return search(val, node->right);
        if (val < node->val)
            return search(val, node->left);
    }

    BSTNode<T> *insert(const T &val, BSTNode<T> *node) {
        if (node == nullptr)
            return new BSTNode<T>(val);
        if (val > node->val)
            node->right = insert(val, node->right);
        if (val < node->val)
            node->left = insert(val, node->left);
        return node;
    }

    //deletes a node with 1 or 0 children
    void remove_easy(BSTNode<T> *node, BSTNode<T> *par) {
        if (node == root) {
            node->right ? root = node->right : root = node->left;
        } else {
            if (node == par->right)
                node->right ? par->right = node->right : par->right = node->left;
            else
                node->right ? par->left = node->right : par->left = node->left;
        }
        delete node;
    }


public:
    BST() {
        root = nullptr;
    }

    bool is_empty() const {
        return root == nullptr;
    }

    bool search_recursive(const T &val) const {
        return search(val, root);
    }

    bool search_iterative(const T &val) const {
        BSTNode<T> *curr = root;
        while (curr != nullptr) {
            if (curr->val == val)
                return true;
            if (val > curr->val)
                curr = curr->right;
            else curr = curr->left;
        }
        return false;
    }

    void insert_recursive(const T &val) {
        root = insert(val, root);
    }

    void insert_iterative(const T &val) {
        BSTNode<T> *prev = nullptr;
        BSTNode<T> *curr = root;
        while (curr != nullptr) {
            prev = curr;
            if (val == curr->val) return;
            if (val > curr->val) curr = curr->right;
            else curr = curr->left;
        }

        BSTNode<T> *new_node = new BSTNode<T>(val);

        if (root == nullptr) root = new_node;
        else if (val > prev->val) prev->right = new_node;
        else if (val < prev->val) prev - left = new_node;
    }

    T get_max() const {
        if (is_empty())
            throw string("EMPTY TREE");
        BSTNode<T> *curr = root;
        while (curr->right != nullptr)
            curr = curr->right;
        return curr->val;
    }

    T get_min() const {
        if (is_empty())
            throw string("EMPTY TREE");
        BSTNode<T> *curr = root;
        while (curr->left != nullptr)
            curr = curr->left;
        return curr->val;
    };

    void remove(const T &val) {

    }
};


/// <summary of search>
/// Asymptotic complexity of search_recursive is O(1) in the best case and O(n) in the worst case.
/// Asymptotic complexity of search_iterative is O(1) in the best case and O(n) in the worst case.
/// Best case occurs when the value is found at the root.
/// Worst case occurs when the value is not found or is found at the a leaf and the tree is unbalanced.
/// If the tree is balanced, the worst case is O(log n).
/// </summary of search>

/// <summary of insert>
/// The function first checks if the value is already in the tree.
/// If it is, it returns.
/// Otherwise, it traverses the tree until it finds a null pointer.
/// At this point prev points to the parent of the new node.
/// In addition prev is a leaf or has one child.
/// The function then creates a new node and assigns it to the appropriate pointer of prev.
/// Asymptotic complexity of insert for unbalanced tree is O(1) in the best case and O(n) in the worst case.
/// Best case occurs when the value is inserted as a child to the root.
/// Worst case occurs when the value is inserted as a child to a leaf.
/// Asymptotic complexity of insert for balanced tree is always O(log n) as insertion always happens at the lower levels.
/// </summary of insert>



#endif //DATA_STRUCTURES_PRACTICE_BST_H
