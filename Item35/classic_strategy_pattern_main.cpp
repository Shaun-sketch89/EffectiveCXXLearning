//
// Created by 姚轩 on 2024/4/1.
//
#include "health_calc_func.h"
#include "game_character.h"

int main(){
    SlowHealthLoser slowHealthLoser;
    FastHealthLoser fastHealthLoser;
    EvilBadGuy ebg1(&slowHealthLoser);
    EvilBadGuy ebg2(&fastHealthLoser, "I am EBG2");
    ebg1.healthValue();
    ebg2.healthValue();
}