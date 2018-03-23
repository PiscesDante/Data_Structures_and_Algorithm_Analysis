#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <utility>
#include <iostream>

template <typename T>
class BinaryHeap {

public:
    BinaryHeap() = default;
    // BinaryHeap(const std::vector<T>& items);
    
    bool isEmpty() const { return array.empty(); }
    const T& findMin() const { return array[0]; }

    void insert(const T& x);
    // void insert(T&& x);
    void deleteMin();
    
    void makeEmpty();
    void printContent();

private:
    std::vector<T> array; // 堆的数组
    
    void buildHeap();
    void percolateDown(int hole);

};

// =======================================================================

template <typename T>
void BinaryHeap<T>::printContent() {
    for (T elem : array) std::cout << elem << " ";
    std::cout << std::endl;
}

/**
 * 这个堆的最小元应该在根上
 * 如果考虑任意子树也应该是一个堆，那么任意结点就应该小于它的所有后裔
*/

/**
 * 为将一个元素X插入到堆中，我们先将这个元素插入到最后一个位置上
 * 如果X的插入没有破坏堆的性质，那么插入完成。
 * 否则我们将X和其父结点的元素进行交换，如此进行直到符合堆的性质
*/

// 将项x插入堆，允许重复元
template <typename T>
void BinaryHeap<T>::insert(const T& x) {
    array.push_back(x); // 先将元素插入最后一位
    std::size_t x_pos = array.size() - 1; // 取得新元素的秩
    while (x_pos / 2 >= 0 && x < array[x_pos / 2]) {
        std::swap(array[x_pos], array[x_pos / 2]);
        x_pos /= 2;
    }
    // 如果比父节点的元素小，则和父节点交换元素值
}

// 删除最小项，如果为空则抛出UnderflowException异常
/**
 * 这里删除最小项的步骤是先将做最后一个元素换到堆顶
 * 然后将最后一个元素resize掉
 * 然后将堆顶的那个元素下沉到符合堆的性质的位置即可
*/
template <typename T>
void BinaryHeap<T>::deleteMin() {
    // if (isEmpty()) return;
    std::swap(array[0], array[array.size() - 1]); // 交换首尾元素
    array.resize(array.size() - 1);
    std::size_t pos = 0; 
    while (2 * pos < array.size()) {
        int j = 2 * pos;
        if (array[pos] < array[j]) ++j;
        if (array[pos] < array[j]) break;
        std::swap(array[pos], array[j]);
        pos = j;
    }
}



#endif