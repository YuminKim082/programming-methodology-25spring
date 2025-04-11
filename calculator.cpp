#include "calculator.h"
#include <stdexcept>

int INT_MAX = 2147483647;
int INT_MIN = -2147483648;

int Calculator::add(int a, int b) {
    // TODO
    if (a == INT_MAX && b == 1) {
        throw std::overflow_error("Integer overflow");
    }
    if (a == INT_MIN && b == -1) {
        throw std::overflow_error("Integer overflow");
    }

    if(a == 0 && b == 0) {
        return 0;
    }
    return a+b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if (a == INT_MIN && b == 1) {
        throw std::overflow_error("Integer overflow");
    }
    if (a == INT_MAX && b == -1) {
        throw std::overflow_error("Integer overflow");
    }
    return a-b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (a > 0 && b > 0 && a > INT_MAX / b) {
        throw std::overflow_error("Integer overflow");
    }
    if (a < 0 && b < 0 && a < INT_MIN / b) {
        throw std::underflow_error("Integer underflow");
    }
    if (a > 0 && b < 0 && a > INT_MIN / b) {
        throw std::underflow_error("Integer underflow");
    }
    if (a < 0 && b > 0 && a < INT_MAX / b) {
        throw std::overflow_error("Integer overflow");
    }
    if (a == 0 || b == 0) {
        return 0;
    }
    return a*b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (a > 0 && b < 0 && a > INT_MIN / b) {
        throw std::underflow_error("Integer underflow");
    }
    if (a < 0 && b > 0 && a < INT_MAX / b) {
        throw std::overflow_error("Integer overflow");
    }
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    
    if (a == INT_MIN && b == -1) {
        throw std::overflow_error("Integer overflow");
    }
    if (a == INT_MAX && b == 1) {
        throw std::overflow_error("Integer overflow");
    }
    if (a == INT_MIN && b == 1) {
        throw std::underflow_error("Integer underflow");
    }
    if (a == INT_MAX && b == -1) {
        throw std::overflow_error("Integer overflow");
    }
    return a/b;
}