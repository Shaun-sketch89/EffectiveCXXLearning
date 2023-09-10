/*
若一个类中有pure virtual function，那么这个类会变成abstract class（无法被初始化，比如无法创造一个该类型的实例）
当有情况你需要一个abstract class，但是这个类没有任何的pure virtual function，怎么办呢？
由于一般abstract class是作为一个base class使用，而多态的base class应该有一个virtual destructor,
所以可以写一个pure virtual destructor
*/
#include <iostream>

class AWOV{
public:
    virtual ~AWOV() = 0;
};
// destructor工作的方式是：derived class的destructor首先调用，然后基类的destructor再被调用。编译器会生成一个对基类析构函数的调用
AWOV::~AWOV() {
    std::cout << "I am a base class pure virtual destructor" << std::endl;
}

class DerivedAWOV: public AWOV{
public:
    ~DerivedAWOV(){
        std::cout << "I am a derived class destructor" << std::endl;
    }
};

int main(){
    DerivedAWOV derivedAWOV;
    return 0;
}