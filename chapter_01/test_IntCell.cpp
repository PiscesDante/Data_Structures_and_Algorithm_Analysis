#include <iostream>

#include "IntCell.h"

int main(int argc, char* argv[]) {
    IntCell m; // or, IntCell m(0); but not IntCell m();
    m.write(5);
    std::cout << "Cell contents: " << m.read() << std::endl;
    return 0;
}