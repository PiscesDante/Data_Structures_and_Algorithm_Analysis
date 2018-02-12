#include "List.h"

#include <iostream>

int main(int argc, char** argv) {
    List<int> lis;
    for (int i = 0; i < 10; ++i) lis.push_back(i);
    std::cout << lis << std::endl;

    for (int i = 0; i < 5; ++i) lis.push_front(i);
    std::cout << lis << std::endl;

    lis.insert(6, 123);
    std::cout << lis << std::endl;

    lis.erase(123);
    std::cout << lis << std::endl;

    lis.reverse();
    std::cout << lis << std::endl;

    return 0;
}