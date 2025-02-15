#include "queue.h"
#include "Node.h"
#include <iostream>

queue::queue(){
    first = nullptr;
    last = nullptr;
}
queue::~queue(){
    while(first!=nullptr){
        pop();
    }
}
void queue::show_begin(){
    Node* temp = first;
    while(temp != nullptr){
        std::cout<<temp->value<<std::endl;
        temp = temp->next;
        
    }
}

void queue::show_end(){
    Node* temp = last;
    while(temp !=nullptr){
        
        std::cout<<temp->value<<std::endl;
        if(temp == first) 
            break;
        temp = temp->prev;
    }
}

void queue::push(int value){
    Node* temp= new Node(value);
    if(first == nullptr){
        first = temp;
        last = first;
    }
    else{
        Node* ptr = last;
        last->next = temp;
        last = temp;
        last->prev = ptr;
    }
    
}

int queue::pop(){
    Node* temp = first;
    if(first==nullptr){
        std::cout<<"queue is empty"<<std::endl;
        return -1;
    }
    int result = first->value;
    first = first->next;
    delete temp;
    return result;
}
void queue::task(){
    Node* current = first;
    Node* prev = nullptr;

    while(current!=nullptr){
        Node* temp = current;
        if(current->value%2==0){
            if(prev == nullptr){
                first = current->next;
                if(first == nullptr){
                    last = nullptr;
                }
            }

            else{
                prev->next = current->next;
                if(current->next==nullptr){
                    last = prev;
                }
                
            }
            current = current->next;
            delete temp;
        }
        else{
            prev = current;
            current = current->next;
        }

    }
}
