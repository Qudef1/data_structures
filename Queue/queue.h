#pragma once 
#include "Node.h"
struct queue
{
    public:
    queue();
    ~queue();
    void push(int value);
    int pop();
    void show_begin();
    void show_end();
    void task();
    private:
    Node* first;
    Node* last;
};
