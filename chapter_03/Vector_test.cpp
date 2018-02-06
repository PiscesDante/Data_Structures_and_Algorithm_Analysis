#include <iostream>
#include "Vector.h"

int main(int argc, char** argv) {
    Vector<int> temp;
    for (int i = 0; i < 10; ++i) temp.push_back(i);
    // std::cout << temp.get_size() << std::endl;
    // for (int i = 0; i < temp.get_size(); ++i) {
    //     std::cout << temp[i] << " ";
    // }
    // std::cout << std::endl;

    // temp.resize(3);
    // std::cout << temp.get_size() << std::endl;
    // for (int i = 0; i < temp.get_size(); ++i) {
    //     std::cout << temp[i] << " ";
    // }
    // std::cout << std::endl;


    return 0;
}