#include <iostream>
#include <cstddef>

#include "Stack.h"

int main(int argc, char** argv) {
    Stack<int> stck;
    // std::cout << stck.empty() << std::endl;
    // std::cout << stck.size() << std::endl;
    std::cout << stck.top() << std::endl;
    // std::cout << stck << std::endl;
    for (std::size_t i = 0; i < 7; ++i) stck.push(i);
    std::cout << stck << std::endl;
    std::cout << stck.pop() << std::endl;
    std::cout << stck << std::endl;

    return 0;
}