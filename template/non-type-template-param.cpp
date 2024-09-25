//
// Created by 姚轩 on 2024/9/25.
//
#include <iostream>

template<typename T, std::size_t N> void array_init(T (&parm)[N]){
    for(std::size_t i = 0; i != N; ++i){
        parm[i] = i;
    }
}

template<typename T, std::size_t N> void array_display(const T* parm){
    for(std::size_t i = 0; i != N; ++i){
        std::cout << parm[i] << std::endl;
    }
}

int main(){
    int a[10];
    double b[20];

    array_init(a);
    array_init(b);

    array_display<int, 10>(a);

    return 0;
}