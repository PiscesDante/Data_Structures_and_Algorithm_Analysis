#include <utility>
#include <iostream>
#include <random>

template <typename T>
void insertion_sort(std::vector<T>& v) {
    for (std::size_t i = 1; i < v.size(); ++i) {
        for (std::size_t j = i; j > 0 && v[j] < v[j - 1]; --j) {
            std::swap(v[j], v[j - 1]);
        }
    }
}


// 测试程序
int main() {
    std::vector<int> iv;
    std::random_device rd;
    for (int i = 0; i < 100; ++i) iv.push_back(rd() % 100);
    for (auto elem : iv) std::cout << elem << " ";
    std::cout << std::endl;
    insertion_sort(iv);
    for (auto elem : iv) std::cout << elem << " ";
    std::cout << std::endl;
    return 0;
}