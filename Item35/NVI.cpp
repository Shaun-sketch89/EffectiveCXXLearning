//
// Created by 姚轩 on 2024/3/28.
//
#include <iostream>
using std::cout;
using std::endl;

class GameCharacter{
public:
    // non-virtual interface(NVI) which is a particular manifestation of the more general design pattern called Template Method
    int healthValue() const{
        cout << "do before stuff\n";
        int retVal = doHealthValue();
        cout << "do after stuff\n";
        return retVal;
    }
private:
    // put virtual function to private
    virtual int doHealthValue() const{
        cout << "Game Character" << endl;
        return 0;
    }
};

class GameCharacterA: public GameCharacter{
private:
    // it's not strictly necessary that the virtual functions be private
    virtual int doHealthValue() const{
        cout << "Game Character A" << endl;
        return 0;
    }
};

int main(){
    GameCharacter *gptr = new GameCharacterA();
    gptr -> healthValue();
}