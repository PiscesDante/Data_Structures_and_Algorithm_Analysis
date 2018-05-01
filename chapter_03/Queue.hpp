#ifndef QUEUE_H
#define QUEUE_H

// Class QueueNode
// ==============================================================
template <typename T>
struct QueueNode {
    T val;
    QueueNode<T>* next;
    QueueNode<T>(T d, QueueNode<T>* n = nullptr) :
        val(d), next(n) { }
};

// CLass Queue
// ==============================================================
template <typename T>
class Queue {

public:
    Queue() = default; // 默认构造函数
    Queue& Queue(const Queue& rhs); // 拷贝构造函数
    Queue operator = (const Queue& rhs); // 拷贝赋值运算符

    bool empty() const { return queue_size == 0; } // DONE
    int size() const { return queue_size; } // DONE
    T front();
    T back();
    void push(T input_val);
    void pop();

    ~Queue(); // 析构函数

private:
    QueueNode<T>* head = nullptr;
    QueueNode<T>* tail = nullptr;
    int queue_size = 0;

};

template <typename T>
Queue& Queue<T>::Queue(const Queue& rhs) {
    if (this != &rhs && rhs->head != nullptr) {
        QueueNode<T>* rhs_sentinel = rhs.head;
        while (rhs_sentinel != nullptr) {
            if (head == nullptr) {
                head = new QueueNode(rhs_sentinel->val);
                tail = head;
            } else {
                // TODO
            }
        }
    }
}

#endif