#include <iostream>
#include <optional>
#include <cstring>
#include <iomanip>
#include <map>


template<typename T>
class Stack{
    private:
    struct Node{
        T value;
        Node* next;

        Node(const T& data):value(data),next(nullptr){}
    };
    Node* top;
    public:
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        while(top!=nullptr){
            pop();
        }
    }
    bool empty(){
        return top == nullptr;
    }
    void pop(){
        
        if(top!=nullptr){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(T x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    T peek(){
        if(top == nullptr){
            return 0;
        }
        T x = top->value;
        return x;
    }

};
bool isBukva(char s){
    if(s>=97&&s<=122){
        return 1;
    }
    return 0;
}
bool isOperator(char s){
    if(s==40||s==43||s==41||s==42||s==45||s==47){
        return 1;
    }
    return 0;
}

int main(){
    std::map<char,double> symbols;
    std::string s1;
    Stack<char> temp;
    std::string exit;
    std::cin >> s1;
   
    
    char prevchar;
    for(int i = 0;i<s1.length();i++){
        
        if(!isBukva(s1[i])&&!isOperator(s1[i])){ //bukvi i operaatori
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(s1[i]<48&&i==0&&s1[i]!='('){//perviy operatror no ne skobka
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(s1[i]<48&&prevchar<48&&prevchar>=42&&s1[i]>=42){//dva operatora 
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(prevchar == '('&&s1[i]==')'){
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(prevchar==')'&&s1[i]=='('){//
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(prevchar==')'&&s1[i]>48){
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(s1[i]>96&&prevchar>96){
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(i==s1.length()-1&&s1[i]!=')'&&s1[i]<96&&s1[i]<123){
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }
        else if(s1[i]==')'&&prevchar<48||prevchar=='('&&s1[i]<48){
            std::cout<<"input is incorrect"<<std::endl;
            return 0;
        }



        
        prevchar = s1[i];
    }
    
    int open=0,closed=0;
    for(int i = 0;i<s1.length();i++){
        
        if(s1[i]>=97&&s1[i]<=122&&!symbols.count(s1[i])){
            double key;
            std::cout<<"enter "<<s1[i]<<' ';
            std::cin>>key;
            symbols.emplace(s1[i],key);
        }
    if(s1[i]=='('){
        open++;
    }
    if(s1[i]==')'){
        closed++;
    }
}
    if(open!=closed){
        std::cout<<"braces are incorrect"<<std::endl;
        return 0;
    }
    
    for (size_t i = 0; i < s1.length(); i++) {
        if (s1[i] >= 'a' && s1[i] <= 'j') {
            exit += s1[i]; 
        } else if (s1[i] == '+' || s1[i] == '-') {
        
            while (!temp.empty() && (temp.peek() == '+' || temp.peek() == '-' || temp.peek() == '*' || temp.peek() == '/')) {
                exit += temp.peek(); 
                temp.pop();
            }
            temp.push(s1[i]); 
        } else if (s1[i] == '*' || s1[i] == '/') {
            
            while (!temp.empty() && (temp.peek() == '*' || temp.peek() == '/')) {
                exit += temp.peek(); 
                temp.pop();
            }
            temp.push(s1[i]); 
        } else if (s1[i] == '(') {
            temp.push(s1[i]); 
        } else if (s1[i] == ')') {
            
            while (!temp.empty() && temp.peek() != '(') {
                exit += temp.peek(); 
                temp.pop();
            }
            if (!temp.empty() && temp.peek() == '(') {
                temp.pop(); 
            }
        }
    }

    
    while (!temp.empty()) {
        exit += temp.peek();
        temp.pop();
    }
    std::cout << exit << std::endl; 

    
    
    Stack<double> result;
    for(int i = 0; i < exit.size();i++){
        if(exit[i]>96){
            result.push(symbols[exit[i]]);
        }
        else{
            double x1,x2;
            x2 = result.peek();
            result.pop();
            x1 = result.peek();
            result.pop();
            switch(exit[i]){
                case '+': result.push(x1+x2);break;
                case '-': result.push(x1-x2);break;
                case '*': result.push(x1*x2);break;
                case '/': result.push(x1/x2);break;
            }
        }
    }
    std::cout<<std::fixed<<std::setprecision(2)<<result.peek()<<std::endl;
    result.pop();
    
    return 0;
}