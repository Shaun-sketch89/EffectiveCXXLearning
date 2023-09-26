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

void lock(Mutex *pm){
    pm -> lock();
}

// this function will be used as "deleter" of shared_ptr
// in this scnerio, when resource-managing class out of block, we will not destroy Mutex but call mutex->unlock()
void unlock(Mutex *pm){
    pm -> unlock();
}

int main(){
    Mutex m;
    {
        // a shared_ptr will be enough, we do not need class Lock to manage resource like what book says ??
        std::shared_ptr<Mutex> mp1(&m, unlock);
        std::cout << mp1.use_count() << std::endl;
        std::shared_ptr<Mutex> mp2(mp1);
        std::cout << mp1.use_count() << " " << mp2.use_count() << std::endl;
    }
    std::cout << "out of block where Lock exists" << std::endl;
    return 0;
}