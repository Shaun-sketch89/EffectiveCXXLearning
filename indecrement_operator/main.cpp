//
// Created by 姚轩 on 2023/10/26.
//
#include <iostream>

int main(){
    int i = 3;
    if(++i == 4){
        std::cout << "prefix" << std::endl;
        std::cout << i << std::endl;
    }
    if(i++ == 4) {
        std::cout << "postfix" << std::endl;
        std::cout << i << std::endl;
    }
}