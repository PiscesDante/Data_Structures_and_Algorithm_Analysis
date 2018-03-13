#include <iostream>

template <typename T>
struct BinaryNode {
    T element;
    BinaryNode<T>* left_child;
    BinaryNode<T>* right_child;
};

int main() {
    BinaryNode<int> bn;
    bn.element = 15;
    std::cout << bn.element << std::endl;

    return 0;
}