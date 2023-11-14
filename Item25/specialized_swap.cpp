//
// Created by 姚轩 on 2023/11/10.
//
#include <iostream>
#include <vector>
#include "widget.h"

// specialize swap in namespace std
namespace std{
    template<>
    void swap<Widget>(Widget& a, Widget& b){
        std::cout << "specialized swap call" << std::endl;
        a.swap(b);
    }
}

int main(){
    std::vector<double> a(100, 1);
    std::vector<double> b(100, 3);
    WidgetImpl *widget_impl_a = new WidgetImpl(a);
    WidgetImpl *widget_impl_b = new WidgetImpl(b);
    Widget widget_a(widget_impl_a);
    Widget widget_b(widget_impl_b);

    std::swap(widget_a, widget_b);

    int aa = 1;
    int bb = 3;
    std::swap(aa, bb);
    std::cout << aa << "; " << bb << std::endl;

    return 0;
}