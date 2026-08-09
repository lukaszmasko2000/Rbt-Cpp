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
    RedBlackTreeNode<T> *left, *right;

    explicit RedBlackTreeNode(T data)
    : data(data), left(nullptr), right(nullptr) {};
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

    void insert(T data);
    void inorderTraversal(RedBlackTreeNode<T> *node);
    [[nodiscard]] RedBlackTreeNode<T> *getRoot() const { return root; };

private:
    RedBlackTreeNode<T> *root = nullptr;
    RedBlackTreeNode<T> *NIL = nullptr;
    void leftRotate(RedBlackTreeNode<T> *&node);
    void rightRotate(RedBlackTreeNode<T> *&node);
    void fixInsert(RedBlackTreeNode<T> *&node);
};


#endif //RED_BLACK_TREE_RBTREE_H
