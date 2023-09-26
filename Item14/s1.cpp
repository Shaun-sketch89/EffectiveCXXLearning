//
// Created by 姚轩 on 2023/9/26.
//
#include <iostream>

// a toy Mutex class whose lock() and unlock() only print some infomation
// one of resources need to be managed
class Mutex{
public:
    void lock(){
        std::cout << "lock Mutex" << std::endl;
    }
    void unlock(){
        std::cout << "unlock Mutex" << std::endl;
    }
};

// core of this strategy
// in this scnerio, we do not allow copy of Lock, we define copy constructor and copy assignment constructor private,
// to prevent Lock to be copied
class Uncopyable{
public:
    Uncopyable(){};
private:
    Uncopyable(const Uncopyable& rhs);
    Uncopyable& operator=(const Uncopyable& rhs);
};

// Lock used to manage lock and unlock operation of Mutex
class Lock: public Uncopyable{
public:
    explicit Lock(Mutex *pm)
    : Uncopyable(), mutexPtr(pm)
    {mutexPtr->lock();}
    ~Lock(){mutexPtr->unlock();}
private:
    Mutex *mutexPtr;
};

int main(){
    Mutex m;
    {
        Lock ml1(&m);
        // when client do this, program won't compile
        Lock ml2(ml1);
    }
    std::cout << "out of block where Lock exists" << std::endl;
    return 0;
}