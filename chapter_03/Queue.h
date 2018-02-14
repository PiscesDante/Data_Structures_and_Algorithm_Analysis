#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>(T d = T(), Node<T>* n = nullptr) :
        data(d), next(n) { }
};

template <typename T>
class Queue {

public:
    

private:


};

#endif