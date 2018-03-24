#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
#include <cstddef>
#include <utility>

#include <random>

template <typename> class PriorityQueue;
template <typename T> std::ostream& operator << (std::ostream& os, const PriorityQueue<T>& rhs);

template <typename T>
class PriorityQueue {

friend std::ostream& operator << <T>(std::ostream& os, const PriorityQueue<T>& rhs);

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue<T>& rhs);
    PriorityQueue& operator = (const PriorityQueue<T>& rhs);

    void delMax();
    T getMax() const { return a[1]; }
    void insert(const T item);
    std::size_t size() const { return a.size() - 1; }
    bool isEmpty() const { return !(a.size() - 1); }

    ~PriorityQueue() = default;

private:
    std::vector<T> a;

};

// ========================================================

template <typename T>
PriorityQueue<T>::PriorityQueue() {
    a.push_back(-1);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhs) {
    a = rhs.a;
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator = (const PriorityQueue& rhs) {
    if (this != &rhs) { a = rhs.a; }
    return *this;
}

template <typename T>
void PriorityQueue<T>::delMax() {
    if (isEmpty()) return;
    a[1] = a[size()];
    a.resize(size());
    int i = 1;
    while (2 * i <= size()) {
        int j = 2 * i;
        if (a[j] < a[j + 1]) ++j;
        if (a[i] > a[j]) break;
        std::swap(a[i], a[j]);
        i = j;
    }
}

template <typename T>
void PriorityQueue<T>::insert(const T item) {
    a.push_back(item);
    int i = size();
    while (i >= 1 && (i / 2) >= 1) {
        if (a[i] < a[i / 2]) break;
        std::swap(a[i], a[i / 2]);
        i /= 2;
    }
}

template <typename T>
std::ostream& operator << (std::ostream& os, const PriorityQueue<T>& rhs) {
    for (std::size_t i = 1; i < rhs.a.size(); ++i) {
        os << rhs.a[i] << " ";
    }
    return os;
}

#endif