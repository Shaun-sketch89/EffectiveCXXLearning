//
// Created by 姚轩 on 2024/4/2.
//
#include "game_character.h"

int HealthCalcFunc::calc(const GameCharacter &gc) const {
    // maybe use attributes of gc to calc health value
    cout << gc.getSelfIntro() << endl;
    cout << "basic health-calculation algorithm" << endl;
    return 0;
}

int SlowHealthLoser::calc(const GameCharacter &gc) const {
    // maybe use attributes of gc to calc health value
    cout << gc.getSelfIntro() << endl;
    cout << "slow loser health-calculation algorithm" << endl;
    return 0;
}

int FastHealthLoser::calc(const GameCharacter &gc) const {
    // maybe use attributes of gc to calc health value
    cout << gc.getSelfIntro() << endl;
    cout << "fast loser health-calculation algorithm" << endl;
    return 0;
}