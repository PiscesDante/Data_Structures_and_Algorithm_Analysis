#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <iostream>

template <typename> struct Node;
template <typename> class List;
template <typename T>
std::ostream& operator << (std::ostream& os, const List<T>& rhs);

// =======================NODE==========================

template <typename T>
struct Node {
    Node<T>* prev;
    T data;
    Node<T>* next;
    Node(Node<T>* p = nullptr, T d = T(), Node<T>* n = nullptr) :
        prev(p), data(d), next(n) { }
};

// ========================LIST==========================

template <typename T>
class List {

friend struct Node<T>;
friend std::ostream& operator << <T>(std::ostream& os, const List<T>& rhs);

public:
    List() : // 默认构造函数
        head(nullptr), tail(nullptr), the_size(0) { }
    List(const List& rhs); // 拷贝构造函数
    List<T>& operator = (const List<T>& rhs); // 拷贝赋值运算符

    bool empty() const { return !head; }
    std::size_t size() const { return the_size; }
    T& front() { return head->data; }
    T& back() { return tail->data; }

    void push_back(T input_data);
    void push_front(T input_data);
    T pop_back();
    T pop_front();

    void insert(T target_data, T input_data);
    Node<T>* find(T target_data);
    void erase(T target_data);
    void reverse();
    void clear();

    ~List<T>();

private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t the_size;

};

// ======================================================

// 拷贝构造函数
template <typename T>
List<T>::List(const List& rhs) : List() {
    if (!rhs.empty()) {
        for (Node<T>* node = rhs.head; !node; node = node->next) push_back(node->data);
    }
}

// 拷贝赋值运算符
template <typename T>
List<T>& List<T>::operator = (const List<T>& rhs) {
    if (this != &rhs) {
        clear();
        for (Node<T>* node = rhs.head; !node; node = node->next) push_back(node->data);
    }
    return *this;
}

template <typename T>
void List<T>::push_back(T input_data) {
    if (empty()) {
        // 如果链表为空
        head = new Node<T>(nullptr, input_data, nullptr);
        tail = head;
    } else {
        // 如果链表不为空
        Node<T>* temp_new = new Node<T>(tail, input_data, nullptr);
        tail->next = temp_new;
        tail = temp_new;
    }
    ++the_size;
}

template <typename T>
void List<T>::push_front(T input_data) {
    if (empty()) {
        head = new Node<T>(nullptr, input_data, nullptr);
        tail = head;
    } else {
        Node<T>* temp_new = new Node<T>(nullptr, input_data, head);
        head->prev = temp_new;
        head = temp_new;
    }
    ++the_size;
}

template <typename T>
T List<T>::pop_back() {
    T ret = tail->data;
    Node<T>* del = tail;
    tail = tail->prev;
    delete del;
    del = nullptr;
    --the_size;
    return ret;
}

template <typename T>    
T List<T>::pop_front() {
    T ret = head->data;
    Node<T>* del = head;
    head = head->next;
    delete del;
    del = nullptr;
    --the_size;
    return ret;
}

template <typename T>
void List<T>::insert(T target_data, T input_data) {
    Node<T>* pos;
    for (pos = head; pos && pos->data != target_data; pos = pos->next);
    if (pos) {
        if (pos == tail) {
            push_back(input_data);
        } else {
            Node<T>* temp_next = pos->next;
            Node<T>* temp_new = new Node<T>(pos, input_data, pos->next);
            pos->next = temp_new;
            temp_next->prev = temp_new;
            temp_new = nullptr;
            ++the_size;
        }
    } else {
        push_back(input_data);
    }
}

template <typename T>
Node<T>* List<T>::find(T target_data) {
    Node<T>* sentinel;
    for (sentinel = head; sentinel && sentinel->data != target_data; sentinel = sentinel->next);
    return sentinel;
}

template <typename T>
void List<T>::erase(T target_data) {
    Node<T>* pos = find(target_data);
    if (pos) {
        pos->next->prev = pos->prev;
        pos->prev->next = pos->next;
        delete pos;
        pos = nullptr;
        --the_size;
    }
}

template <typename T>
void List<T>::reverse() {
    tail = head;
    while (head) {
        Node<T>* temp_next = head->next;
        Node<T>* swap_temp_ptr = head->prev;
        head->prev = head->next;
        head->next = swap_temp_ptr;
        if (temp_next) {
            head = temp_next;
        } else {
            break;
        }
    }
}

template <typename T>
void List<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp_next = head->next;
        delete head;
        head = temp_next;
    }
    tail = nullptr;
    the_size = 0;
}

// 析构函数：
template <typename T>
List<T>::~List() {
    while (head != nullptr) {
        Node<T>* temp_next = head->next;
        delete head;
        head = temp_next;
    }
    tail = nullptr;
}

template <typename T>
std::ostream& operator << (std::ostream& os, const List<T>& rhs) {
    for (Node<T>* node = rhs.head; node; node = node->next) {
        os << node->data << " ";
    }
    return os;
}

#endif