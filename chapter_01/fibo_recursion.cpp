/**
 * 斐波那契数列的递归实现方式：
*/

// ===========================================

#include <iostream>

void fibo_recursion(int curr, int next, int count);

int main(int argc, char* argv[]) {
    fibo_recursion(1, 0, 10);
    return 0;
}

void fibo_recursion(int curr, int delta, int count) {
    if (count > 0) {
        int temp = curr + delta;
        std::cout << temp << " ";
        fibo_recursion(delta, temp, --count);
    } else {
        std::cout << std::endl;
    }
}