#include <iostream>
#include "queue.h"

int main(){
    queue a;
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(10);
    std::cout<<std::endl;
    std::cout<<std::endl<<"read from begin:"<<std::endl;
    a.show_begin();
    std::cout<<std::endl<<"read from end:"<<std::endl;
    a.show_end();
    a.task();
    std::cout<<std::endl;
    a.show_begin();
    return 0;
}