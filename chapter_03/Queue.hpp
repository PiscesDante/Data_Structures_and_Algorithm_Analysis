#ifndef QUEUE_H
#define QUEUE_H

// Class QueueNode
// ==============================================================
template <typename T>
struct QueueNode {
    T val;
    QueueNode* next;
    QueueNode(T d, QueueNode* n = nullptr) :
        val(d), next(n) { }
};

// CLass Queue
// ==============================================================
template <typename T>
class Queue {
public:
    Queue() = default;
    Queue(const Queue& rhs);
    Queue& operator = (const Queue& rhs);

    bool empty() const { return queue_size == 0; }
    int size() const { return queue_size; }
    T& front();
    T& back();
    void push(T input_val);
    void pop();

    ~Queue();

private:
    QueueNode<T>* head = nullptr;
    QueueNode<T>* tail = nullptr;
    int queue_size = 0;

};

// CLass Queue Definition
// ==============================================================

// 拷贝构造函数定义
template <typename T>
Queue<T>::Queue(const Queue& rhs) {
    QueueNode<T>* temp = rhs.head;
    while (temp != nullptr) {
        push(temp->val);
        temp = temp->next;
    }
}

// 拷贝赋值运算符
template <typename T>
Queue<T>& Queue<T>::operator = (const Queue& rhs) {
    if (this != &rhs) {
        ~Queue();
        Queue(rhs);
    }
    return *this;
}

// 获取队头（可修改的引用）
template <typename T>
T& Queue<T>::front() { return *head; }

// 获取队尾（可修改的引用）
template <typename T>
T& Queue<T>::back() { return *tail; }

// 入队
template <typename T>
void Queue<T>::push(T input_val) {
    QueueNode<T>* new_node = new QueueNode<T>(input_val);
    if (head == nullptr) {
        head = new_node;
        tail = head;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    ++queue_size;
}

// 出队
template <typename T>
void Queue<T>::pop() {
    if (empty()) return;
    QueueNode<T>* del = head;
    head = head->next;
    delete del;
    del = nullptr;
    --queue_size;
}

// 析构函数
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) pop();
    head = nullptr;
    tail = nullptr;
}

#endif