#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

template <typename T>
class Vector {

public:
    Vector(std::size_t initial_size = 0); // 默认构造函数
    Vector(const Vector& rhs); // 拷贝构造函数
    Vector& operator = (const Vector& rhs); // 拷贝赋值运算符
    T& operator [] (const std::size_t k) { return pointer[k]; } // 重载下标运算符

    std::size_t get_size() const { return the_size; }
    std::size_t get_capacity() const { return the_capacity; }
    bool empty() const { return the_size == 0; }
    void resize(std::size_t n);
    void push_back(T rhs);
    void insert(std::size_t k, T rhs);
    void erase(T rhs);

    ~Vector(); // 析构函数

private:
    std::size_t the_size;
    std::size_t the_capacity;
    T* pointer;

};

// =======================================================================

template <typename T>
Vector<T>::Vector(std::size_t initial_size) :
    the_size(initial_size), the_capacity((initial_size == 0) ? 10 : initial_size * 2) {
        pointer = new T[the_capacity];
        for (std::size_t i = 0; i < the_size; ++i) pointer[i] = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs) {
    pointer = new T[rhs.the_capacity];
    for (std::size_t i = 0; i < rhs.the_size; ++i) {
        pointer[i] = (rhs.pointer)[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& rhs) {
    if (this != &rhs) {
        delete[] pointer;
        pointer = new T[rhs.the_capacity];
        for (std::size_t i = 0; i < rhs.the_size; ++i) {
            pointer[i] = (rhs.pointer)[i];
        }
    }
    return *this;
}

template <typename T>
void Vector<T>::resize(std::size_t n) {
    std::size_t temp_size = n;
    std::size_t temp_capacity = ((n == 0) ? 10 : (n * 2));
    std::size_t i = 0;
    T* temp_array = new T[temp_capacity];
    if (n <= the_size) {
        for (std::size_t i = 0; i < n; ++i) temp_array[i] = pointer[i];
    } else {
        std::size_t i;
        for (i = 0; i < the_size; ++i) temp_array[i] = pointer[i];
        for (; i < n; ++i) temp_array[i] = 0;
    }
    delete[] pointer;
    pointer = temp_array;
    the_size = temp_size;
    the_capacity = temp_capacity;
}

template <typename T>
void Vector<T>::push_back(T rhs) {
    if (the_size < the_capacity) {
        pointer[the_size++] = rhs;
    } else {
        T* temp = new T[the_capacity * 2];
        for (std::size_t i = 0; i < the_size; ++i) temp[i] = pointer[i];
        delete[] pointer;
        pointer = temp;
        pointer[the_size++] = rhs;
    }
}

template <typename T>
void Vector<T>::insert(std::size_t k, T rhs) {
    // TODO
}

template <typename T>
void Vector<T>::erase(T rhs) {
    // TODO
}

template <typename T>
Vector<T>::~Vector() {
    delete[] pointer;
    pointer = nullptr;
}

#endif