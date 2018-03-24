#include <iostream>
#include <utility>
#include <random>
#include <cstddef>

template <typename T>
void shell_sort(std::vector<T>& v) {
    std::size_t len = v.size();
    std::size_t delta = len / 2;
    while (delta >= 1) {
        for (std::size_t i = delta; i < len; ++i) {
            for (std::size_t j = i; j >= delta && v[j] < v[j - delta]; j -= delta) {
                std::swap(v[j], v[j - delta]);
            }
        }
        delta /= 2;
    }
}

int main() {
    std::vector<int> iv;
    std::random_device rd;
    for (int i = 0; i < 20; ++i) iv.push_back(rd() % 100);
    for (auto elem : iv) std::cout << elem << " ";
    std::cout << std::endl;
    shell_sort(iv);
    for (auto elem : iv) std::cout << elem << " ";
    std::cout << std::endl;
    return 0;
}