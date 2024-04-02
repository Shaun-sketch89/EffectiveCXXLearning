//
// Created by 姚轩 on 2024/4/1.
//

/*
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class GameCharacter;

// health-calculation hierarchy
class HealthCalcFunc{
public:
    virtual int calc(const GameCharacter& gc) const{
        // maybe use attributes of gc to calc health value
        cout << gc.getSelfIntro() << endl;
        cout << "basic health-calculation algorithm" << endl;
    }
};

class SlowHealthLoser: public HealthCalcFunc{
public:
    virtual int calc(const GameCharacter& gc) const{
        // maybe use attributes of gc to calc health value
        cout << gc.getSelfIntro() << endl;
        cout << "slow loser health-calculation algorithm" << endl;
    }
};

class FastHealthLoser: public HealthCalcFunc{
public:
    virtual int calc(const GameCharacter& gc) const{
        // maybe use attributes of gc to calc health value
        cout << gc.getSelfIntro() << endl;
        cout << "fast loser health-calculation algorithm" << endl;
    }
};

HealthCalcFunc defaultHealthCalc;
// game character hierarchy
class GameCharacter{
public:
    explicit GameCharacter(HealthCalcFunc *phcf = &defaultHealthCalc, string selfI = "I am GameCharacter")
    : pHealthCalc(phcf), selfIntro(selfI)
    {}
    string getSelfIntro() const{
        return selfIntro;
    }
    int healthValue() const{
        return pHealthCalc->calc(*this);
    }
private:
    HealthCalcFunc *pHealthCalc;
    string selfIntro;
};

class EvilBadGuy: public GameCharacter{
public:
    explicit EvilBadGuy(HealthCalcFunc *phcf = &defaultHealthCalc, string selfI = "I am EvilBadGuy")
    : GameCharacter(phcf, selfI)
    {}
};
*/

#include "game_character.h"

int main(){
    SlowHealthLoser slowHealthLoser;
    FastHealthLoser fastHealthLoser;
    EvilBadGuy ebg1(&slowHealthLoser);
    EvilBadGuy ebg2(&fastHealthLoser, "I am EBG2");
    ebg1.healthValue();
    ebg2.healthValue();
}