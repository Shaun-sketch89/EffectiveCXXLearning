//
// Created by 姚轩 on 2024/4/2.
//
#include "health_calc_func.h"
#include <string>
using std::string;

HealthCalcFunc defaultHealthCalc;
// game character hierarchy
class GameCharacter{
public:
    explicit GameCharacter(HealthCalcFunc *phcf = &defaultHealthCalc, string selfI = "I am GameCharacter");
    string getSelfIntro() const;
    int healthValue() const;
private:
    HealthCalcFunc *pHealthCalc;
    string selfIntro;
};

class EvilBadGuy: public GameCharacter{
public:
    explicit EvilBadGuy(HealthCalcFunc *phcf = &defaultHealthCalc, string selfI = "I am EvilBadGuy");
};