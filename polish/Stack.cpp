#include "Stack.h"
#include "Node.h"
#include <iostream>

Stack::Stack():top(nullptr){}
Stack::~Stack(){
    while(top!=nullptr){
        pop();
    }
}

void Stack::push(char value){
    Node* left = new Node(value);
    left->next = top;
    top = left;
}
char Stack::pop(){
    if(top == nullptr){
        std::cout<<"stack is empty"<<std::endl;
        return -1;
    }
    Node* temp = top;
    char result = temp->value;
    top = top->next;
    delete temp;
    return result;
}
char Stack::peek(){
    if(top == nullptr){
        std::cout<<"stack is empty"<<std::endl;
        return -1;
    }
    
    return top->value;
}
void Stack::task(){
    Stack Temp;
    while(top!=nullptr){
        Node* temp = top;
        if(temp->value%2!=0) Temp.push(temp->value);
        top = top->next;
        delete temp;
    }
    while(Temp.top!=nullptr){
        push(Temp.pop());
    }
}
void Stack::show(){
    Node* temp = top;
    while(top!=nullptr){
        std::cout<<top->value<<std::endl;
        top = top->next;
    }
}
