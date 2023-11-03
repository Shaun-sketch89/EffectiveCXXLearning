//
// Created by 姚轩 on 2023/11/3.
//
class Rational {
    friend const Rational& operator*(const Rational& lhs, const Rational& rhs);
public:
    Rational(int numerator = 0, int denominator = 1): n(numerator), d(denominator){}
private:
    int n,d;
};

// trying to return a reference
// create a new object on the stack(local variable)
// warning: reference to stack memory associated with local variable 'result' returned
const Rational& operator*(const Rational& lhs, const Rational& rhs){
    Rational result(lhs.n*rhs.n, lhs.d*rhs.d);
    return result;
}

int main(){
    Rational a(1,2);
    Rational b(3,5);
    Rational c = a * b;
    return 0;
}