//
// Created by 姚轩 on 2023/11/10.
//
#include <iostream>
#include <vector>
#include "widget.h"

namespace std{
    //1. implementation when Widget is not a template
    //In general, we're not permitted to alter the contents of the std namespace, but we are allowed to totally specialize standart templates
    /*
    template<>
    void swap<Widget>(Widget& a, Widget& b){
        std::cout << "specialized swap call" << std::endl;
        a.swap(b);
    }
     */
    //2. partial specialization that legal for class templates, but not for function templates
    // error! function template partial specialization is not allowed (~~~~ swap<Widget<T>> ~~~~)
    /*
    template<typename T>
    void swap<Widget<T>>(Widget<T>& a, Widget<T>& b){
        a.swap(b);
    }
     */
    //3. we can overload
    // but in std namespace, it's not okay to add new templates
    // this will compile and run, but maybe result in undefined behaviour?
    /*
    template<typename T>
    void swap(Widget<T>& a, Widget<T>& b){
        std::cout << "specialized swap call" << std::endl;
        a.swap(b);
    }
     */
}

int main(){
    std::vector<double> a(100, 1);
    std::vector<double> b(100, 3);
    WidgetStuff::WidgetImpl<double> *widget_impl_a = new WidgetStuff::WidgetImpl<double>(a);
    WidgetStuff::WidgetImpl<double> *widget_impl_b = new WidgetStuff::WidgetImpl<double>(b);
    WidgetStuff::Widget<double> widget_a(widget_impl_a);
    WidgetStuff::Widget<double> widget_b(widget_impl_b);

    // from a client's view, we call swap
    // there may exist 3 swap: 1. std default swap 2. std specialized swap 3. T-specific swap in or not in a namespace(definitely not in std)
    swap(widget_a, widget_b);
    widget_a.showInfo();
    widget_b.showInfo();

    int aa = 1;
    int bb = 3;
    std::swap(aa, bb);
    std::cout << aa << "; " << bb << std::endl;

    return 0;
}