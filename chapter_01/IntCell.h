/**
 * A class for simulating an integer memory cell.
 * 1.4 C++ class
 * start from page 9
*/

// ===============================================

#ifndef INTCELL_H
#define INTCELL_H

class IntCell {

public:
    /**
     * Construct the IntCell.
     * Initial value is initial_value.
     * 
     * 注：IntCell的构造函数是explicit的。所有的单参数的构造函数都必须是explicit的，
     * 以避免后台的类型转换。否则，一些宽松的规则将允许在没有显式类型转换操作的情况下
     * 进行类型转换。
    */
    IntCell(const int initial_value = 0) :
        stored_value(initial_value) { }
    IntCell(const IntCell& rhs) :
        stored_value(rhs.stored_value) { } // 拷贝构造函数
    
    IntCell& operator = (const IntCell& rhs); // 拷贝赋值运算符

    /**
     * Return the stored value.
    */
    inline int read() const { return stored_value; }

    /**
     * Change the stored value to x.
    */
    void write(int x) { stored_value = x; }

    ~IntCell() = default;
    
private:
    int stored_value;

};

// ============================================================

IntCell& IntCell::operator = (const IntCell& rhs) {
    if (this != &rhs) {
        this->stored_value = rhs.stored_value;
    }
    return *this;
}

#endif