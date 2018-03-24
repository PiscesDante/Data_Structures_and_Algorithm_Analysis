#include "priority_queue.h"

#include <random>

int main(int argc, char** argv) {
    PriorityQueue<int> pq;
    std::random_device rd;
    for (int i = 0; i < 10; ++i) {
        pq.insert(rd() % 100);
    }
    std::cout << pq << std::endl;
    for (int i = 0; i < 15; ++i) {
        std::cout << pq.getMax() << std::endl;
        pq.delMax();
        std::cout << pq << std::endl;
    }
    return 0;
}