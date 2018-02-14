/**
 * 做一个空栈，读入字符直至文件尾。如果字符是一个开放符号，则将其压入栈中。
 * 如果字符是一个封闭符号，那么若栈为空，则报错；若栈不为空，则将栈元素弹出。
 * 如果弹出的符号不是对应的开放符号，则报错。在文件尾，如果栈非空则报错。
*/

// ===============================================================

#include <iostream>
#include <string>

#include "Stack.h"

bool braces_check(const std::string& rhs);

int main(int argc, char** argv) {
    Stack<char> stck;
    std::string test1 = "({[]})"; // True
    std::string test2 = "{}[{(())(])}]"; // False
    std::cout << (braces_check(test1) ? "True" : "False") << std::endl;
    std::cout << (braces_check(test2) ? "True" : "False") << std::endl;    
    return 0;
}

bool braces_check(const std::string& rhs) {
    using size_type = std::string::size_type;
    const size_type len = rhs.size();
    Stack<char> stck;
    for (size_type i = 0; i < len; ++i) {
        if (rhs[i] == '{' || rhs[i] == '[' || rhs[i] == '(') {
            stck.push(rhs[i]);
        } else if (rhs[i] == '}') {
            if (stck.empty()) return false;
            if (stck.pop() != '{') return false;
        } else if (rhs[i] == ']') {
            if (stck.empty()) return false;
            if (stck.pop() != '[') return false;
        } else if (rhs[i] == ')') {
            if (stck.empty()) return false;
            if (stck.pop() != '(') return false;
        }
    }
    if (rhs.empty()) {
        return true;
    } else {
        return false;
    }
}