#ifndef AVLTREE_H
#define AVLTREE_H

template <typename> class AVLNode;
template <typename> class AVLTree;
template <typename T> int height(AVLNode<T>* rt);

template <typename T>
class AVLNode {
    
template <typename> friend int height(AVLNode<T>* rt);
friend class AVLTree<T>;

public:
    AVLNode(const T& elem, AVLNode* lc = nullptr, AVLNode* rc = nullptr, int h = 0) :
        element(elem), left_child(lc), right_child(rc), height(h) { }
    AVLNode(T&& elem, AVLNode* lc = nullptr, AVLNode* rc = nullptr, int h = 0) :
        element(elem), left_child(lc), right_child(rc), height(h) { }

private:
    T element;
    AVLNode* left_child;
    AVLNode* right_child;
    int height;

};

/**
 * 返回结点rt的高度，如果是nullptr则返回-1
 * 这里将函数写成外部函数，设置成为友元
*/
template <typename T>
int height(AVLNode<T>* rt) {
    return (rt == nullptr) ? -1 : rt->height;
}

// ======================================================================================

template <typename T>
class AVLTree {

public:

    static const int ALLOWED_IMBALANCE = 1;

private:
    AVLNode<T>* root;

    void insert(const T& x, AVLNode<T>*& rt);
    void balance(AVLNode<T>*& rt);

};

/**
 * 像一棵子树进行插入的内部方法
 * x是要插入的项
 * rt为该子树的根节点
 * 设置子树的新根
*/
template <typename T>
void AVLTree<T>::insert(const T& x, AVLNode<T>*& rt) {
    if (rt == nullptr) rt = new AVLNode<T>(x);
    else if (x < rt->element) insert(x, rt->left_child);
    else if (rt->element) insert(x, rt->right_child);
    // balance(rt);
}

template <typename T>
void AVLTree<T>::balance(AVLNode<T>*& rt) {
    if (rt == nullptr) return;
    if (height(rt->left_child) - height(rt->right_child) > ALLOWED_IMBALANCE) {
        
    }
}



#endif