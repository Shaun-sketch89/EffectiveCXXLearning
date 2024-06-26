//
// Created by 姚轩 on 2024/4/2.
//
#include "health_calc_func.h"
#include "game_character.h"

HealthCalcFunc defaultHealthCalc;

GameCharacter::GameCharacter(HealthCalcFunc *phcf, std::string selfI)
        : pHealthCalc(phcf), selfIntro(selfI)
        {}

string GameCharacter::getSelfIntro() const {
    return selfIntro;
}

int GameCharacter::healthValue() const {
    return pHealthCalc->calc(*this);
}

EvilBadGuy::EvilBadGuy(HealthCalcFunc *phcf, std::string selfI)
        : GameCharacter(phcf, selfI)
        {}