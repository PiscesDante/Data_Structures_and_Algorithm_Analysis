#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

template <typename> class BinaryNode;
template <typename> class BinarySearchTree;

// =================================================================

template <typename T>
class BinaryNode {

friend class BinarySearchTree<T>;

public:
    BinaryNode(const T& theElem, BinaryNode* lt, BinaryNode* rt, BinaryNode* pt) :
        element(theElem), left_child(lt), right_child(rt), parent(pt) { }
    
private:
    T element;
    BinaryNode* left_child;
    BinaryNode* right_child;
    BinaryNode* parent;

};

// =================================================================

template <typename T>
class BinarySearchTree {

friend class BinaryNode<T>;

public:
    BinarySearchTree(BinaryNode<T>* rt = nullptr) :
        root(rt) { }
    BinarySearchTree(const BinarySearchTree& rhs);
    ~BinarySearchTree();

    const T findMin() const;
    const T findMax() const;
    bool contains(const T& x) const;
    bool isEmpty() const { return root == nullptr; }
    void printTree();

    void makeEmpty();
    void insert(const T& x);
    void remove(const T& x);

    const BinarySearchTree& operator = (const BinarySearchTree& rhs);

private:
    BinaryNode<T>* root;

    void insert(const T& x, BinaryNode<T>*& rt);
    void printTree(const BinaryNode<T>* rt);
    void freeTree(BinaryNode<T>*& rt);

};

// =================================================================

// ==========function findMin===========

template <typename T>
const T BinarySearchTree<T>::findMin() const {
    if (root == nullptr) return T();
    BinaryNode<T>* ptr = root;
    while (ptr) {
        if (ptr->left_child)
            ptr = ptr->left_child;
        else
            return ptr->element;
    }
}

// ==========function findMax===========

template <typename T>
const T BinarySearchTree<T>::findMax() const {
    if (root == nullptr) return T();
    BinaryNode<T>* ptr = root;
    while (ptr) {
        if (ptr->right_child)
            ptr = ptr->right_child;
        else
            return ptr->element;
    }
}

// ==========function ~BinarySearchTree=============

template <typename T>
void BinarySearchTree<T>::freeTree(BinaryNode<T>*& rt) {
    if (rt->left_child) freeTree(rt->left_child);
    if (rt->right_child) freeTree(rt->right_child);
    if (rt) {
        delete rt;
        rt = nullptr;
    }
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    if (root) freeTree(root);
}

// ===========function printTree=============

template <typename T>
void BinarySearchTree<T>::printTree(const BinaryNode<T>* rt) {
    if (rt == nullptr) return;
    if (rt->left_child) printTree(rt->left_child);
    std::cout << rt->element << std::endl;
    if (rt->right_child) printTree(rt->right_child);
}

template <typename T>
void BinarySearchTree<T>::printTree() {
    printTree(root);
}

// ===========function makeEmpty==============

template <typename T>
void BinarySearchTree<T>::makeEmpty() {
    if (root) freeTree(root);
}

// ===========function insert=============

template <typename T>
void BinarySearchTree<T>::insert(const T& x, BinaryNode<T>*& rt) {
    if (root == nullptr) {
        root = new BinaryNode<T>(x, nullptr, nullptr, nullptr);
    } else {
        if (x > rt->element) {
            if (rt->right_child == nullptr) {
                rt->right_child = new BinaryNode<T>(x, nullptr, nullptr, rt);
            } else {
                insert(x, rt->right_child);
            }
        } else if (x < rt->element) {
            if (rt->left_child == nullptr) {
                rt->left_child = new BinaryNode<T>(x, nullptr, nullptr, rt);
            } else {
                insert(x, rt->left_child);
            }
        }
    }
}

template <typename T>
void BinarySearchTree<T>::insert(const T& x) {
    insert(x, root);
}

// ===========function contains===========

template <typename T>
bool BinarySearchTree<T>::contains(const T& x) const {
    BinaryNode<T>* ptr = root;
    while (ptr) {
        if (x < ptr->element) {
            ptr = ptr->left_child;
        } else if (x > ptr->element) {
            ptr = ptr->right_child;
        } else {
            return true;
        }
    }
    return false;
}

// =========function remove===========

template <typename T>
void BinarySearchTree<T>::remove(const T& x) {
    
}

// ====================================================================

#endif