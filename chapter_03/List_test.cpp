#include "List.h"

#include <iostream>

int main(int argc, char** argv) {
    List<int> lis;
    std::cout << lis.empty() << std::endl;
    lis.push_back(123);
    // std::cout << lis << std::endl;
    return 0;
}