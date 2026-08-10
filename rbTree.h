//
// Created by luke-masko on 8/7/26.
//
#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

#include <iostream>

template <class T>
class RedBlackTreeNode {
public:
    T data;
    std::string color;
    RedBlackTreeNode<T> *left, *right, *parent;

    RedBlackTreeNode()
    : data(T()), left(nullptr), right(nullptr), parent(nullptr), color("BLACK") {}

    explicit RedBlackTreeNode(T val)
    : data(val), left(nullptr), right(nullptr), parent(nullptr), color("BLACK") {}
};

template <class T>
class RedBlackTree {
public:
    RedBlackTree() {
        NIL = new RedBlackTreeNode<T>;
        NIL->color = "black";
        NIL->left = NIL->right = NIL;
        root = NIL;
    }

    void insert(T);
    void inorderTraversal(RedBlackTreeNode<T> *);
    [[nodiscard]] RedBlackTreeNode<T> *getRoot() const { return root; };

private:
    RedBlackTreeNode<T> *root = nullptr;
    RedBlackTreeNode<T> *NIL = nullptr;
    void leftRotate(RedBlackTreeNode<T> *&);
    void rightRotate(RedBlackTreeNode<T> *&);
    void fixInsert(RedBlackTreeNode<T> *&);
};


template <class T>
void RedBlackTree<T>::leftRotate(RedBlackTreeNode<T> *&x) {
    RedBlackTreeNode<T> *y = x->right;
    x->right = y->left;

    if (x->parent == nullptr)  root = x;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;
}

template <class T>
void RedBlackTree<T>::rightRotate(RedBlackTreeNode<T> *&x) {
    RedBlackTreeNode<T> *y = x->left;
    x->left = y->right;

    if (y->right != NIL)  y->right->parent = x;
    y->parent = x->parent;

    if (x->parent == nullptr)  root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;

    y->right = x;
    x->parent = y;
}

template <class T>
void RedBlackTree<T>::fixInsert(RedBlackTreeNode<T> *&k) {
    while (k != root && k->parent->color == "RED") {
        if (k->parent == k->parent->parent->left) {
            if (auto* uncle = k->parent->parent->right; uncle->color == "RED") {
                k->parent->color = "BLACK";
                uncle->color = "BLACK";
                k->parent->parent->color = "RED";
                k = k->parent->parent;
            }
            else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = "BLACK";
                k->parent->parent->color = "RED";
                rightRotate(k->parent->parent);
            }
        } else {
            if (auto* uncle = k->parent->parent->left; uncle->color == "RED") {
                k->parent->color = "BLACK";
                uncle->color = "BLACK";
                k->parent->parent->color = "RED";
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = "BLACK";
                k->parent->parent->color = "RED";
                leftRotate(k->parent->parent);
            }
        }
    }
    root->color = "BLACK";
}


template <class T>
void RedBlackTree<T>::insert(T data) {
    auto *node = new RedBlackTreeNode<T>(data);
    node->left = node->right = NIL;

    RedBlackTreeNode<T> *parent = nullptr;
    auto *current = root;

    while (current != NIL) {
        parent = current;
        if (node->data < current->data) current = current->left;
        else current = current->right;
    }

    node->parent = parent;

    if (parent == nullptr) root = node;
    else if (node->data < parent->data) parent->left = node;
    else parent->right = node;

    if (node->parent == nullptr) {
        node->color = "BLACK";
        return;
    }
    if (node->parent->parent == nullptr) return;
    fixInsert(node);
}

template <class T>
void RedBlackTree<T>::inorderTraversal(RedBlackTreeNode<T> *node) {
    if (node != NIL) {
        inorderTraversal(node->left);
        std::cout << node->data << " (" << node->color << ") ";
        inorderTraversal(node->right);
    }
}

#endif //RED_BLACK_TREE_RBTREE_H
