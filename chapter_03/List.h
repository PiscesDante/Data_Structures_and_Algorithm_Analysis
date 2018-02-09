#ifndef LIST_H
#define LIST_H

#include <cstddef>

// =======================NODE==========================

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
};

// ========================LIST==========================

template <typename T>
class List {

public:
    List() : 
        head(nullptr), tail(nullptr), the_size(0) { }
    List(const List<T>& rhs); // 拷贝构造函数
    List& operator = (const List<T>& rhs); // 拷贝赋值运算符
    bool empty() const { return !head; }
    
    ~List();

private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t the_size;

};

// ======================================================

// 拷贝构造函数：
template <typename T>
List<T>::List(const List<T>& rhs) {
    if (rhs.empty()) {
        head = nullptr;
        tail = nullptr;
        the_size = 0;
    }

}

// 析构函数：
template <typename T>
List<T>::~List() {
    while (head != nullptr) {
        Node<T>* temp_next = head->next;
        delete head;
        head = temp_next;
    }
}


#endif