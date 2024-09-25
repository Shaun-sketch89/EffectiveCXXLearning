//
// Created by 姚轩 on 2024/9/25.
//
#include <iostream>

template<typename T, std::size_t N> void array_init(T (&parm)[N]){
    for(std::size_t i = 0; i != N; ++i){
        parm[i] = i;
    }
}

int main(){
    int a[10];
    double b[20];

    array_init(a);
    array_init(b);

    for (std::size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++){
        std::cout << a[i] << std::endl;
    }

    return 0;
}