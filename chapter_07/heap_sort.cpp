#include <iostream>
#include <vector>
#include <random>

template <typename T> void percDown(std::vector<T>& v, int i, int n);
template <typename T> void heap_sort(std::vector<T>& v);

// ===============MAIN================

int main() {
    std::vector<int> iv;
    std::random_device rd;
    for (int i = 0; i < 20; ++i) iv.push_back(rd() % 100);
    for (auto elem : iv) std::cout << elem << " ";
    std::cout << std::endl;
    heap_sort(iv);
    for (auto elem : iv) std::cout << elem << " ";
    std::cout << std::endl;
    return 0;
}

// ====================================

// 标准的堆排序
template <typename T>
void heap_sort(std::vector<T>& v) {
    // 首先建堆
    for (int i = v.size() / 2 - 1; i >= 0; --i) percDown(v, i, v.size());
    for (int j = v.size() - 1; j > 0; --j) {
        std::swap(v[0], v[j]); // 交换最后一个元素和第一个元素
        percDown(v, 0, j); // 将交换上去的元素下沉到合适的位置
    }
}

/*
 * 在deleteMax和buildHeap中用到的堆排序内部方法
 * i是开始下沉的位置
 * n是二叉堆的逻辑大小
 */
template <typename T>
void percDown(std::vector<T>& v, int i, int n) {
    int child;
    for (T temp = v[i]; (2 * i - 1) < n; i = child) {
        child = 2 * i - 1; // 先将将child设定为左孩子
        // 如果左孩子小于右孩子，则将child设定为右孩子
        if (child != n - 1 && v[child] < v[child + 1]) ++child;
        // 如果这时temp小于孩子，则
        if (temp < v[child]) v[i] = v[child];
        else break;
    }
    v[i] = temp;
}