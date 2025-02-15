#pragma once


struct Stack{
    public:
    Stack();
    ~Stack();
    void push(int value);
    int pop();
    int peek();
    void task();
    void clear();
    void show();
    void foo();
    private:
    struct Node* top;
};