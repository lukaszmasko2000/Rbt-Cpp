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

    explicit RedBlackTreeNode(T data)
    : data(data), left(nullptr), right(nullptr), parent(nullptr) {};
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

    if (y->right != NIL)  y->rigth->parent = x;
    y->parent = x->parent;

    if (x->parent == nullptr)  root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;

    y->right = x;
    x->parent = y;
}

template <class T>
void RedBlackTree<T>::fixInsert(RedBlackTreeNode<T> *&k) {
    while (k != root && k->parent->color == "red") {

    }
}



#endif //RED_BLACK_TREE_RBTREE_H
