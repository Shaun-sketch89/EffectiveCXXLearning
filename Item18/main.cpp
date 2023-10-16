//
// Created by 姚轩 on 2023/10/16.
//
#include <iostream>

enum Week{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

class Date{
public:
    // class interface using enum type
    Date(const Week& w)
    :week(w)
    {}
    Week getWeek(){
        return week;
    }
private:
    Week week;
};

class WrapperInt{
public:
    explicit WrapperInt(int i=0)
            : val(i) {}
    // const-qualifying the return type from operator* can prevent clients from making error for user-defined types:
    // if(a * b = c)
    // we have our types behave consistently with the build-in types
    const WrapperInt operator*(const WrapperInt& rhs){
        this->val *= rhs.val;
        return *this;
    }
    int getVal(){
        return val;
    }
private:
    int val;
};

int main(){
    Week today;
    today = Tuesday;
    Date d(today);
    //Date d(5);
    std::cout << d.getWeek() << std::endl;

    WrapperInt a(2);
    WrapperInt b(3);
    WrapperInt c;
    // if *operator member function return const type, following won't compeile
    //a * b = c;
    std::cout << c.getVal() << std::endl;
    c = a * b;
    std::cout << c.getVal() << std::endl;
}