//
// Created by luke-masko on 8/7/26.
//
#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

#include <iostream>

template <typename T>
class RedBlackTreeNode {
public:
    T data;
    std::string color;
    RedBlackTreeNode<T> *left, *right;

    explicit RedBlackTreeNode(T data)
    : data(data), left(nullptr), right(nullptr) {};
};


#endif //RED_BLACK_TREE_RBTREE_H
