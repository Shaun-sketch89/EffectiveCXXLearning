//
// Created by 姚轩 on 2023/11/3.
//
#include <iostream>

class Rational {
    //friend const Rational& operator*(const Rational& lhs, const Rational& rhs);
    // a right way that returns an object
    friend const Rational operator*(const Rational& lhs, const Rational& rhs);
    friend bool operator==(const Rational& lhs, const Rational& rhs);
public:
    Rational(int numerator = 0, int denominator = 1): n(numerator), d(denominator){}
private:
    int n,d;
};

bool operator==(const Rational& lhs, const Rational& rhs){
    if((lhs.n == rhs.n) && (lhs.d == rhs.d)){
        return true;
    }else{
        return false;
    }
}
/*
// trying to return a reference
// create a new object on the stack(local variable)
// warning: reference to stack memory associated with local variable 'result' returned
const Rational& operator*(const Rational& lhs, const Rational& rhs){
    Rational result(lhs.n*rhs.n, lhs.d*rhs.d);
    return result;
}

// trying to return a reference
// create a new object on the heap(use new)
// This is a guaranteed resource leak
const Rational& operator*(const Rational& lhs, const Rational& rhs){
    Rational *result = new Rational(lhs.n*rhs.n, lhs.d*rhs.d);
    return *result;
}

// trying to return a reference
// create a local static variable
// this one immediately raises thread-safety hackles
// its deeper flaw, consider perfectly reasonable client code: if((a*b) == (c*d))...
const Rational& operator*(const Rational& lhs, const Rational& rhs){
    static Rational result(lhs.n*rhs.n, lhs.d*rhs.d);
    return result;
}
 */

// the right way that returns an object
const Rational operator*(const Rational& lhs, const Rational& rhs){
    Rational result(lhs.n*rhs.n, lhs.d*rhs.d);
    return result;
}

int main(){
    /*
    Rational a(1,2);
    Rational b(3,5);
    Rational c = a * b;
    */

    /*
    Rational w,x,y,z;
    w = x * y * z;
    */

    Rational a(1,2), b(3,4);
    Rational c(2,3), d(3,4);
    if((a*b)==(c*d)){
        std::cout << "do whatever’s appropriate when the products are equal;" << std::endl;
    }else{
        std::cout << "do whatever’s appropriate when they are not;" << std::endl;
    }
}