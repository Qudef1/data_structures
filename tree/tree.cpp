#include "Node.h"
#include "tree.h"

Tree::Tree():root(nullptr){}

Tree::~Tree(){
    delete root;
}
void Tree::add(int val,char strval[]){
    if(root == nullptr){
        root = new Node(val,strval);
    }
    else{
        Node* element = new Node(val,strval);
        
    }
}
void Tree::balance(){

}
void Tree::remove(){

}
void Tree::search(){

}
void Tree::go(){

}