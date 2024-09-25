//
// Created by 姚轩 on 2024/9/25.
//
#include <iostream>

template<typename T, std::size_t N> 
void array_init(T (&parm)[N]){
    for(std::size_t i = 0; i < N; ++i){
        parm[i] = i;
    }
}

/*
模板形参说明:
- T: 类型参数,表示数组元素的类型
- N: 非类型模板参数,表示数组的大小

函数形参说明:
- T (&parm)[N]: 引用参数,引用一个类型为T、大小为N的数组
*/
template<typename T, std::size_t N> 
void array_display(const T (&parm)[N]) {
    for(std::size_t i = 0; i < N; ++i) {
        std::cout << parm[i] << ' ';
    }
    std::cout << std::endl;
}

int main(){
    int a[10];
    double b[20];

    array_init(a);
    array_init(b);

    array_display(a);  // 不需要显式指定模板参数
    array_display(b);

    return 0;
}