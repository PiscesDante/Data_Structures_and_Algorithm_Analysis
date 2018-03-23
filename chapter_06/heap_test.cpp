#include "priority_queue.h"

#include <random>

int main() {

    BinaryHeap<int> bh;
    std::random_device rd;
    for (int i = 0; i < 20; ++i) {
        bh.insert(rd() % 100);
    }
    bh.printContent();

    std::cout << "=============================" << std::endl;

    for (int i = 0; i < 15; ++i) {
        bh.deleteMin();
        bh.printContent();
    }
    return 0;
}