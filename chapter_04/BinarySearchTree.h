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
    BinaryNode(const T& theElem, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr, BinaryNode* pt = nullptr) :
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
    BinarySearchTree(BinarySearchTree&& rhs);
    ~BinarySearchTree();

    const T& findMin() const;
    const T& findMax() const;
    bool contains(const T& x) const;
    bool isEmpty() const { return root == nullptr; }
    void printTree(std::ostream& os = std::cout);

    void makeEmpty();
    void insert(const T& x);
    void insert(T&& x);
    void remove(const T& x);

    const BinarySearchTree& operator = (const BinarySearchTree& rhs);
    const BinarySearchTree& operator = (BinarySearchTree&& rhs);

private:
    BinaryNode<T>* root;

    void insert(const T& x, BinaryNode<T>*& rt);
    void insert(T&& x, BinaryNode<T>*& rt);
    void remove(const T& x, BinaryNode<T>*& rt);
    BinaryNode<T>* findMin(BinaryNode<T>* rt) const;
    BinaryNode<T>* findMax(BinaryNode<T>* rt) const;
    bool contains(const T& x, BinaryNode<T>* rt) const;
    void makeEmpty(BinaryNode<T>*& rt);
    void printTree(const BinaryNode<T>* rt, std::ostream& os);
    BinaryNode<T>* clone(BinaryNode<T>* rt) const;

};

// ========================================================================================

// 如果在树中找到x，则返回true
template <typename T>
bool BinarySearchTree<T>::contains(const T& x) const {
    return contains(x, root);
} // 编译通过

// 将x插入到树中，忽略重复元
template <typename T>
void BinarySearchTree<T>::insert(const T& x) {
    insert(x, root);
} // 编译通过

// 将x从树中删除，如果没找到x，则什么也不做
template <typename T>
void BinarySearchTree<T>::remove(const T& x) {
    remove(x, root);
} // 编译通过

template <typename T>
bool BinarySearchTree<T>::contains(const T& x, BinaryNode<T>* rt) const {
    if (rt == nullptr) return false; // 如果传进来的指针为nullptr直接返回false
    else if (x < rt->element) return contains(x, rt->left_child); // 如果比当前结点值小，进入左边
    else if (rt->element < x) return contains(x, rt->right_child); // 如果比当前结点值大，进入右边
    else return true; // 匹配
} // 编译通过

/**
 * 以上的contains函数应该使用循环来写的话会减少空间复杂度
 * 以下为循环版本
*/
// template <typename T>
// bool BinarySearchTree<T>::contains(const T& x, BinaryNode<T>* rt) const {
//     while (rt != nullptr) {
//         if (x < rt->element) rt = rt->left_child;
//         else if (rt->element < x) rt = rt->right_child;
//         else return true;
//     }
//     if (rt == nullptr) return false;
// } // 编译通过

// 找出子树t中最小项的内部方法，返回包含最小项的结点
// findMin写成非递归的
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::findMin(BinaryNode<T>* rt) const {
    BinaryNode<T>* min = rt;
    while (min != nullptr) {
        if (min->left_child != nullptr) min = min->left_child;
        else break;
    }
    return min;
} // 编译通过

// 找出子树t上最大项的内部方法，返回包含最大项的结点
// findMax写成递归的
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::findMax(BinaryNode<T>* rt) const {
    if (rt == nullptr) return nullptr;
    if (rt->right_child != nullptr) findMax(rt->right_child);
    else return rt;
} // 编译通过

#endif