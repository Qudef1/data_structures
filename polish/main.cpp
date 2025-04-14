#include "Stack.cpp"
#include <iostream>

void polish(char* statement){
    Stack maths;
    char result[50];
    int pointer = 0;
    for(int i = 0; i < sizeof(statement)/sizeof(statement[0]);i++){
        if(statement[i]>='a'&&statement[i]<='z'){
            result[pointer++] = statement[i];
        }
        else if(statement[i]=='('){
            maths.push(statement[i]);
        }
        else if(statement[i]=='+'||statement[i]=='-'){
            while(maths.peek()=='-'||maths.peek()=='+'||maths.peek()=='*'||maths.peek()=='/'){
                result[pointer++]=maths.pop();
            }
            maths.push(statement[i]);
        }
        else if(statement[i]==')'){
            while(maths.peek()!='('){
                result[pointer++]=maths.pop();
            }
            maths.pop();
        }
        else if(statement[i]=='*'||statement[i]=='/'){
            while(maths.peek()=='*'||maths.peek()=='/'){
                result[pointer++]=maths.pop();
            }
            maths.push(statement[i]);
        }
    }
    while(maths.top!=nullptr){
        result[pointer++]=maths.pop();
    }
}
int main(){
    char statement[50];
    std::cout<<"enter your statement"<<std::endl;
    std::cin.getline(statement,50);
    polish(statement);
}