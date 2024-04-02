//
// Created by 姚轩 on 2024/4/2.
//
#include "health_calc_func.h"
#include <string>
using std::string;

// note: Do not define variables in headers
// that's equivalent to defining them in every source file that includes the header
// and that's what's causing your linker error.
//HealthCalcFunc defaultHealthCalc;
// instead, using extern
extern HealthCalcFunc defaultHealthCalc;

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