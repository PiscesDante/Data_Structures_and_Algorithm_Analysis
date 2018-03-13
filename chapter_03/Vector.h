#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <utility>

template <typename T>
class Vector {

public:
    Vector(std::size_t initial_size = 0);
    Vector(const Vector& rhs);
    Vector& operator = (const Vector& rhs);
    T& operator [] (const std::size_t k) { return pointer[k]; }

    std::size_t get_size() const { return the_size; }
    std::size_t get_capacity() const { return the_capacity; }
    bool empty() const { return !the_size; }

    void resize(std::size_t n);
    void push_back(T rhs);
    void insert(std::size_t k, T rhs);
    void erase(T rhs);
    void reserve(std::size_t assigned_capacity);
    const T& back() const { return pointer[the_size - 1]; }
    T pop_back() { return pointer[the_size-- - 1]; }

    T* begin() { return pointer; }
    T* end() { return (pointer + the_size); }
    const T* cbegin() const { return pointer; }
    const T* cend() const { return (pointer + the_size); }

    ~Vector();

private:
    std::size_t the_size = 0;
    std::size_t the_capacity = 0;
    T* pointer = nullptr;

};

// =======================================================================================

template <typename T>
Vector<T>::Vector(std::size_t initial_size) :
    the_size(initial_size), the_capacity((initial_size == 0) ? 10 : initial_size * 2)
{
    pointer = new T[the_capacity];
    for (std::size_t i = 0; i < the_size; ++i) pointer[i] = 0;
}

template <typename T>
Vector<T>::Vector(const Vector& rhs) :
    the_size(rhs.the_size), the_capacity(rhs.the_capacity)
{
    pointer = new T[rhs.the_capacity];
    for (std::size_t i = 0; i < rhs.the_size; ++i) {
        pointer[i] = (rhs.pointer)[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& rhs) {
    if (this != &rhs) {
        the_size = rhs.the_size;
        the_capacity = rhs.get_capacity;
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
        for (std::size_t i = 0; i < n; ++i) temp_array[i] = std::move(pointer[i]);
    } else {
        std::size_t i;
        for (i = 0; i < the_size; ++i) temp_array[i] = std::move(pointer[i]);
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
    if (the_size < k) return;
    if (the_size == k) {
        this->push_back(rhs);
        return;
    }
    if (the_size < the_capacity) {
        the_size += 1;
        std::size_t l;
        for (l = k + 1; l < the_size; ++k, ++l) {
            pointer[l] = pointer[k];
        }
        pointer[k] = rhs;
    } else {
        T* temp = new T[the_capacity * 2];
        std::size_t i;
        for (i = 0; i < k; ++i) temp[i] = pointer[i];
        temp[i++] = rhs;
        for (std::size_t l = k; l < the_size; ++l, ++i) {
            temp[i] = pointer[l];
        }
        delete[] pointer;
        pointer = temp;
        ++the_size;
    }
}

template <typename T>
void Vector<T>::erase(T rhs) {
    std::size_t i;
    for (i = 0; i < the_size; ++i) {
        if (rhs == pointer[i]) break;
    }
    if (i < the_size) {
        for (std::size_t j = i + 1; j < the_size; ++j, ++i) {
            pointer[i] = pointer[j];
        }
        --the_size;
    }
}

template <typename T>
void Vector<T>::reserve(std::size_t assigned_capacity) {
    if (assigned_capacity < the_capacity) return;
    the_capacity = assigned_capacity;
    T* temp = new T[the_capacity];
    for (std::size_t i = 0; i < the_size; ++i) {
        temp[i] = pointer[i];
    }
    delete[] pointer;
    pointer = temp;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] pointer;
    pointer = nullptr;
}

#endif