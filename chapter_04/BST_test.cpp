#include <iostream>
#include <random>
#include <utility>

#include "BinarySearchTree.h"


int main(int argc, char** argv) {
    BinarySearchTree<int> bst;
    std::random_device rd;
    for (int i = 0; i < 10; ++i) {
        bst.insert(rd() % 100);
    }
    bst.insert(55);
    bst.printTree(std::cout);
    bst.remove(55);
    std::cout << std::endl;
    bst.printTree(std::cout);

    return 0;
}