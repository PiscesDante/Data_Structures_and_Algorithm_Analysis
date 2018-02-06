#include <iostream>
#include "Vector.h"

int main(int argc, char** argv) {
    Vector<int> temp;
    for (int i = 0; i < 10; ++i) temp.push_back(i);

    // temp.resize(3);

    // temp.erase(6);

    // temp.push_back(1777);

    // temp.insert(6, 163);

    // temp.reserve(1000);

    // std::cout << temp.pop_back() << std::endl;


    std::cout << temp.get_capacity() << std::endl;
    std::cout << temp.get_size() << std::endl;
    for (int i = 0; i < temp.get_size(); ++i) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;

    // for (auto iter = temp.begin(); iter != temp.end(); ++iter) {
    //     std::cout << *iter << " ";
    // }
    // std::cout << std::endl;

    return 0;
}