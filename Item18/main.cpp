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
    // following defined as member function
    /*
    const WrapperInt operator*(const WrapperInt& rhs){
        this->val *= rhs.val;
        return *this;
    }
     */

    // note here we define member function const
    // otherwise member function cannot be called by const object
    // member function declared const cannot change the value of class
    int getVal() const{
        return val;
    }
    void setVal(int v){
        val = v;
    }
private:
    int val;
};

//operator * normally defined as non-member function
const WrapperInt operator*(const WrapperInt& lhs, const WrapperInt& rhs){
    WrapperInt res(lhs);
    res.setVal(lhs.getVal() * rhs.getVal());
    return res;
}

int main(){
    Week today;
    today = Tuesday;
    Date d(today);
    //Date d(5);
    std::cout << d.getWeek() << std::endl;

    WrapperInt a(2);
    WrapperInt b(3);
    WrapperInt c;
    // if *operator member function return const type, following won't compile
    //a * b = c;
    std::cout << c.getVal() << std::endl;
    c = a * b;
    std::cout << c.getVal() << std::endl;
}