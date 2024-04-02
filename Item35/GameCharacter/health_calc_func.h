//
// Created by 姚轩 on 2024/4/2.
//
#include <iostream>
using std::cout;
using std::endl;

class GameCharacter;

// health-calculation hierarchy
class HealthCalcFunc{
public:
    virtual int calc(const GameCharacter& gc) const;
};

class SlowHealthLoser: public HealthCalcFunc{
public:
    virtual int calc(const GameCharacter& gc) const;
};

class FastHealthLoser: public HealthCalcFunc{
public:
    virtual int calc(const GameCharacter& gc) const;
};