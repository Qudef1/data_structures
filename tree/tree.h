#pragma once 
#include "Node.h"
struct Tree{
    Node* root ;
    Tree();
    ~Tree();
    void add(int,char[]);
    void remove();
    void search();
    void balance();
    void go();
};
