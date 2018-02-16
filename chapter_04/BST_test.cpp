#include <iostream>

#include "BinarySearchTree.h"

int main(int argc, char** argv) {
    BinarySearchTree<int> bst;
    bst.insert(15);
    bst.insert(17);
    bst.insert(5);
    bst.printTree();
    bst.makeEmpty();
    std::cout << bst.isEmpty() << std::endl;

    return 0;
}