#include <iostream>
#include <string>
#include <optional>
template<typename T>
class Tree{
    private:
    struct Node{
        Node* left;
        Node* right;
        T value;
        std::string strvalue;
        int height;
        Node(const T& data,std::string strdata):left(nullptr),right(nullptr),value(data),strvalue(strdata),height(1){}
    };
    Node* root;
    void updateHeight(Node *node){
        if(node == nullptr) return;
        int leftheight = node->left ? node->left->height : 0;
        int rightheight = node->right ? node->right->height : 0;
        node->height = std::max(leftheight,rightheight)+1;
    }
    int BalanceVal(Node* node){
        if(node == nullptr) return 0;
        int leftheight = node->left ? node->left->height : 0;
        int rightheight = node->right ? node->right->height : 0;
        return leftheight - rightheight;
    }
    Node* Balance(Node*node){
        if(node == nullptr) return node;
        updateHeight(node);//обновляем высоту для вершины 
        int factor = BalanceVal(node);// factor razvorota
        if(factor>1){//esli bolshe 1 to leviy razvorot
            if(BalanceVal(node->left)>=0){// obnovlyaem stepen levogo rebenka, esli on bolshe nulya, to levi povorot
                return rightRotate(node);
            }
            else{
                node->left = rightRotate(node->left);//lr povorot
                return rightRotate(node);
            }
        }
        if(factor<-1){//elsi menshe 1 to praviy
            if(BalanceVal(node->right)>=0){//rr povorot
                return leftRotate(node);
            }
            else{
                node->right = leftRotate(node->right);//rl povorot 
                return leftRotate(node);
            }
        }
        return node;
    }
    Node* rightRotate(Node* node){
        Node* temp = node->left;
        Node* right = temp->right;
        temp->right = node;
        node->left=right;
        updateHeight(node);
        updateHeight(temp);
        return temp;

    }
    Node* leftRotate(Node* node){
        Node* temp = node->right;
        Node* right = temp->left;
        temp->left = node;
        node->right = right;
        updateHeight(node);
        updateHeight(temp);
        return temp;


    }
    Node* add(Node* node,T value, std::string strvalue){
        if(node==nullptr){
            return new Node(value,strvalue);
        }
        else{
        if(node->value>value){
            node->left = add(node->left,value,strvalue);
        }
        else if(node->value<value){
            node->right = add(node->right,value,strvalue);
        }
        else{
            std::cout<<"value already exists"<<std::endl;
            return new Node(value,node->strvalue);
        }
        }

        return Balance(node);
    }
    Node* search(Node* node, T value){
        if(node ==nullptr){
            return node;
        }
        else if(node->value < value){
            return search(node->right, value);
        }
        else if(node->value> value){
            return search(node->left,value);
        }
        else{

            std::cout<<std::endl<<"required data is - "<<node->strvalue<<std::endl;
            return node;
        }
    }
    Node* task(Node* node,int &counter){
        if(node!=nullptr){
            task(node->left,counter);
            if(node->left==nullptr&&node->right==nullptr) counter++;
            task(node->right,counter);
        }
        return node;
    }
    Node* minValue(Node* node){
        Node* current = node;
        while(current&&current->left!=nullptr){
            current = current->left;
        }
        return current;
    }
    Node* remove(Node* node,T value){
        
        if(node==nullptr){
            return node;
        }
        else if(node->value<value){
            node-> right = remove(node->right,value);
        }
        else if(node->value>value){
            node->left = remove(node->left,value);
        }
        else if(node->value==value) {
            if(node->right == nullptr){
                Node* temp = node->left;
                delete node;
                return temp; 
            }
            else if(node->left==nullptr){
                Node* temp = node->right;
                delete node;
                return temp;
            }
                Node* temp = minValue(node->right);
                node->value = temp->value;
                node->strvalue = temp->strvalue;
                node->right = remove(node->right,temp->value);
            
        }
        return Balance(node);
        
    }
    void printTree(Node* node, int space = 0, int height = 10) const {
        if (node == nullptr) return;

        space += height;

        printTree(node->right, space);

        std::cout << std::endl;
        for (int i = height; i < space; i++) {
            std::cout << ' ';
        }
        std::cout << node->value << "\n";

        printTree(node->left, space);
    }
    void preOrder(Node* node){
        if(node == nullptr) return;
        std::cout<<node->value<<"\t";
        preOrder(node->left);
        preOrder(node->right);
    }
    void inOrder(Node* node){
        if(node == nullptr) return;
        inOrder(node->left);
        std::cout<<node->value<<"\t";
        inOrder(node->right);

    }
    void postOrder(Node* node){
        if(node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout<<node->value<<"\t";
    }
    public:
    void preOrder(){
        preOrder(root);
    }
    void inOrder(){
        inOrder(root);
    }
    void postOrder(){
        postOrder(root);
    }
    void printTree(){
        printTree(root);
    }
    void add(T value,std::string strvalue){
        root = add(root,value,strvalue);
    }
    bool search(T value){
        return search(root,value)!=nullptr;
    }
    void remove(T value){
        root = remove(root, value);
    }
    Tree(){
        root = nullptr;
    }

    
    void task(){
        int counter = 0;
        task(root,counter);
        std::cout<<std::endl<<counter<<" - number of leaves"<<std::endl;
    }
    void Balance(){
        root = Balance(root);
    }
    
};



int main(){
    Tree<int> tree;
    tree.add(1,"afjf");
    tree.add(3, "ghgalsd");
    tree.add(5,"five");
    
    tree.add(6, "nmczl");
    tree.add(4, "ghagal");
    tree.add(7,"fhdf");
    tree.add(8,"ashfh");
    
    tree.printTree();
    int x;
    do{
        std::cout<<"you see the tree\n1. add leave\n2.search the information\n3.see the number of leaves\n4.remove element.\n5.balance tree\n6.preorder\n7.inorder\n8.postorder\n9.exit";
        std::cout<<std::endl;
        std::cin>>x;
        int y;
        std::string z;
        tree.printTree();
        switch(x){
            case 1:
                std::cout<<"enter the number to put in tree\n";
                std::cin>>y;
                std::cout<<"enter string to put into number\n";
                std::cin>>z;
                tree.add(y,z);
                tree.printTree();
                break;
            case 2:
                std::cout<<"enter the number to see the information below\n";
                std::cin>>y;
                tree.search(y);
                break;
            case 3:
                tree.task();
                break;
            case 4:
                std::cout<<"enter the number to delete element\n";
                std::cin>>y;
                tree.remove(y);
                tree.printTree();
                break;
            case 5:
                tree.Balance();
                break;
            case 6:
                tree.preOrder();
                std::cout<<std::endl;
                break;
            case 7: 
                tree.inOrder();
                std::cout<<std::endl;
                break;
            case 8:
                tree.postOrder();
                std::cout<<std::endl;
                break;
            default:
                break;
        }
    }while(x!=9);
    return 0;
}