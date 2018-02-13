#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename> struct Node;
template <typename> class Stack;
template <typename T>
std::ostream& operator << (std::ostream& os, const Stack<T>& rhs);

// ==================================================

template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>(Node<T>* p = nullptr, T d = T()) :
        prev(p), data(d) { }
};

// ==================================================

template <typename T>
class Stack {

friend struct Node<T>;
friend std::ostream& operator << <T>(std::ostream& os, const Stack<T>& rhs);

public:
    Stack<T>() : // 构造函数
        the_top(nullptr), the_size(0) { }
    Stack<T>(const Stack<T>& rhs); // 拷贝构造函数
    Stack<T>& operator = (const Stack<T>& rhs); // 拷贝赋值运算符

    bool empty() const { return !the_top; }
    std::size_t size() const { return the_size; }

    T top() const;
    void push(T input_data);
    T pop();
    void clear();

    ~Stack<T>(); // 析构函数

private:
    Node<T>* the_top;
    std::size_t the_size;

};

// ====================================================

// 返回栈顶元素：
template <typename T>
T Stack<T>::top() const {
    if (empty()) {
        std::cout << "The stack is empty." << std::endl;
        return T();
    } else {
        return the_top->data;
    }
}

// 压入：
template <typename T>
void Stack<T>::push(T input_data) {
    if (empty()) {
        the_top = new Node<T>(nullptr, input_data);
    } else {
        Node<T>* temp = new Node<T>(the_top, input_data);
        the_top = temp;
        temp = nullptr;
    }
    ++the_size;
}

// 弹出：
template <typename T>
T Stack<T>::pop() {
    T ret = the_top->data;
    Node<T>* del = the_top;
    the_top = the_top->prev;
    delete del;
    del = nullptr;
    --the_size;
    return ret;
}

// 清空：
template <typename T>
void Stack<T>::clear() {
    Node<T>* temp = nullptr;
    while (the_top) {
        Node<T>* temp = the_top->prev;
        delete the_top;
        the_top = temp;
    }
    the_size = 0;
}

// 析构函数：
template <typename T>
Stack<T>::~Stack<T>() {
    Node<T>* temp = nullptr;
    while (the_top) {
        Node<T>* temp = the_top->prev;
        delete the_top;
        the_top = temp;
    }
}

// 输出运算符的重载：
template <typename T>
std::ostream& operator << (std::ostream& os, const Stack<T>& rhs) {
    for (Node<T>* node = rhs.the_top; node; node = node->prev) {
        os << node->data << " ";
    }
    return os;
}

#endif