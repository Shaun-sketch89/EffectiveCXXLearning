//
// Created by 姚轩 on 2024/4/2.
//
#include "game_character.h"

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