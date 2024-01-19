//
// Created by 姚轩 on 2024/1/19.
//
struct Base{
    int memfcn();
    virtual int fcn();
};

int Base::memfcn() {
    return 0;
}

struct Derived : Base{
    // 编译器工作原理是根据名字由局部作用域向外查找，一旦找到就不再找了
    // 使用using声明，可以在不重新定义基类函数的情况下，实现重载
    using Base::memfcn;
    int memfcn(int);

    int fcn(int);
};

int Derived::memfcn(int) {
    return 0;
}

int Derived::fcn(int) {
    return 0;
}

int main(){
    Base b; Derived d;

    // 1. calls Base::memfcn
    b.memfcn();
    // 2. calls Derived::memfcn
    d.memfcn(10);
    // 3. error(if no using declaration)
    d.memfcn();
    // 4.
    d.Base::memfcn();

    Base *bptr = &d;

    // OK: call Base::fcn()
    bptr -> fcn();
    // error
    bptr -> fcn(5);

}