#ifndef HASHTABLE_H
#define HASHTABLE_H

/**
 * 该哈希表的解决冲突的的方法：
 * 将冲突的对象建立成为冲突链
*/

template <typename T>
class hash_table {

public:
    hash_table(int sz = 101) :
        current_size(sz) { }
    bool contains(const T& x);
    void makeEmpty();
    bool insert(const T& x);
    bool insert(T&& x);
    bool remove(const T& x);

private:
    std::vector<std::list<T>> the_lists; // 链表的数组
    int current_size;

    void re_hash();
    std::size_t my_hash(const T& x) const;

};

#endif