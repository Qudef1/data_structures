#pragma once


struct Stack{
    public:
    Stack();
    ~Stack();
    void push(char value);
    char pop();
    char peek();
    void task();
    void clear();
    void show();
    void foo();
    struct Node* top;
};