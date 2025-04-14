#pragma once 

struct Node{
    int value;
    char* strvalue;
    Node* parent;
    Node* left ;
    Node* right;
    Node(int,char[]);
};