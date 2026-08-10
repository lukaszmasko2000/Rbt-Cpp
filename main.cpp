#include <iostream>
#include "rbTree.h"


int main() {

    RedBlackTree<int> rbt;

    rbt.insert(10);
    rbt.insert(15);
    rbt.insert(20);
    rbt.insert(30);

    std::cout << "Inorder Traversal -> ";
    rbt.inorderTraversal(rbt.getRoot());
    std::cout << std::endl;

    return 0;
}