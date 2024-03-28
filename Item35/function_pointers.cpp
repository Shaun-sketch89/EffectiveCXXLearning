//
// Created by 姚轩 on 2024/3/28.
//
#include <iostream>
using std::cout;
using std::endl;

// forward declaration
class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc){
    cout << "defualt health calc\n" << endl;
    return 0;
}
int loseHealthQuickly(const GameCharacter& gc){
    cout << "lose health quickly calc\n" << endl;
    return 0;
}
int loseHealthSlowly(const GameCharacter& gc){
    cout << "lose health slowly calc\n" << endl;
    return 0;
}

class GameCharacter{
public:
    typedef int (*HealthCalcFunc)(const GameCharacter&);
    explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc)
    :healthFunc(hcf)
    {}
    int healthValue() const{
        return healthFunc(*this);
    }

private:
    HealthCalcFunc healthFunc;
};

class EvilBadGuy: public GameCharacter{
public:
    explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc)
    // note here we initialize base class
    :GameCharacter(hcf)
            {}
};

int main(){
    // note here: more flexible than virtual function because
    // 1. Different instances of the same character type can have different health calculation functions
    // 2. Health calculation functions for a particular character may be changed at runtime.
    EvilBadGuy ebg1(loseHealthQuickly);
    EvilBadGuy ebg2(loseHealthSlowly);
    ebg1.healthValue();
    ebg2.healthValue();
}