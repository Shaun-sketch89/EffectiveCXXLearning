//
// Created by 姚轩 on 2024/2/12.
//
#include "iostream"

class Widget{
    friend std::ostream& operator<<(std::ostream&, const Widget&);
    friend std::ostream& operator<<(std::ostream&, Widget&);
public:
    explicit Widget(int a = 0): attr(a){}
    // copy assignment operator returns a reference to *this which is a convention
    Widget& operator=(int a){
        attr = a;
        return *this;
    }
    Widget& operator=(Widget& rhs){
        attr = rhs.attr;
        return *this;
    }
private:
    int attr;
};

std::ostream& operator<<(std::ostream& out, const Widget& w){
    out << w.attr;
    return out;
}

std::ostream& operator<<(std::ostream& out, Widget& w){
    out << w.attr;
    return out;
}

int main(){
    Widget a, b, c;
    a = b = c = 5;
    std::cout << a << std::endl;
    Widget d(88);
    a = d;
    std::cout << a << std::endl;
}