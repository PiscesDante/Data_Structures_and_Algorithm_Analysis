#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template <typename> class BinaryNode;
template <typename> class BinarySearchTree;

// =================================================================

template <typename T>
class BinaryNode {

friend class BinarySearchTree<T>;

public:
    BinaryNode(const T& theElem, BinaryNode* lt, BinaryNode* rt) :
        element(theElem), left_child(lt), right_child(rt) { }
    
private:
    T element;
    BinaryNode* left_child;
    BinaryNode* right_child;

};

// =================================================================

template <typename T>
class BinarySearchTree {

public:
    BinarySearchTree(BinaryNode<T>* rt = nullptr) :
        root(rt) { }
    BinarySearchTree(const BinarySearchTree& rhs);
    ~BinarySearchTree();

    const T& findMin() const;
    const T& findMax() const;
    bool contains(const T& x) const;
    bool isEmpty() const { return root; }
    void printTree() const;

    void makeEmpty();
    void insert(const T& x);
    void remove(const T& x);

    const BinarySearchTree& operator = (const BinarySearchTree& rhs);

private:
    BinaryNode<T>* root;

    // 私有递归函数
    bool contains(BinaryNode<T>* rt, const T& x);
    void insert(BinaryNode<T>* rt, const T& x);

};

// =================================================================

// ===========function insert=============




// ===========function contains===========

template <typename T>
bool contains(const T& x, BinaryNode<T>* rt) {
    if (x == rt->element) {
        return true;
    } else if (x > rt->element) {
        if (rt->right_child) {
            contains(x, rt->right_child);
        } else {
            return false;
        }
    } else if (x < rt->element) {
        if (rt->left_child) {
            contains(x, rt->left_child);
        } else {
            return false;
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& x) const {
    if (isEmpty()) return false;
    return contains(x, root);
}

// =========================================

#endif