#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

// WRITE YOUR CODE HERE
void plus(Stack<int>& stack){
    int b=stack.top();
    stack.pop();
    int a=stack.top();
    stack.pop();
    stack.push(a+b);
}

void minus(Stack<int>& stack){
    int b=stack.top();
    stack.pop();
    int a=stack.top();
    stack.pop();
    stack.push(a-b);
}

void multiplies(Stack<int>& stack){
    int b=stack.top();
    stack.pop();
    int a=stack.top();
    stack.pop();
    stack.push(a*b);
}

void divides(Stack<int>& stack){
    int b=stack.top();
    stack.pop();
    int a=stack.top();
    stack.pop();
    stack.push(a/b);
}

void negate(Stack<int>& stack){
    int b=stack.top();
    stack.pop();
    stack.push(-b);
}

#endif // __stack_rpn__