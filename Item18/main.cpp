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
    friend std::ostream& operator<<(std::ostream&, const WrapperInt&);
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
    //同时定义一个复合赋值操作符, 作为成员函数
    //注意返回值类型 以及行参定义
    const WrapperInt& operator*=(const WrapperInt& rhs){
        val = this->val * rhs.val;
        return *this;
    }

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

// IO operator
// note the defination of function interface
// 由于第一个形参是std::ostream类型，所以必须定义为非成员函数
//（若定义为成员函数，第一个形参是类本身，必须要WrapperInt i; i << cout; 这样使用，与用户熟悉的默认内置类型使用方式不同）
// 函数通常要访问类中的成员，因此一般定义为类的友元
std::ostream& operator<<(std::ostream& out, const WrapperInt& wi){
    // 通常进行最小化的格式化，不输出换行，而是让用户具体决定输出形式，这也与内置类型的输出保持一致
    out << wi.val;
    return out;
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

    c = a * b;
    std::cout << c.getVal() << std::endl;

    // 我们对于WrapperInt类型重载了输出操作符，因此可以如下直接输出
    std::cout << c << std::endl;

    a *= b;
    std::cout << a.getVal() << std::endl;

    // 我们对于WrapperInt类型重载了输出操作符，因此可以如下直接输出
    std::cout << a << std::endl;
}