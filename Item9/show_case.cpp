//
// Created by 姚轩 on 2023/9/10.
//
#include <iostream>

class Transaction{
public:
    Transaction(){
        init();
    };
    // try pure virtual or "normal" virtual, see what happened
    virtual void logTransaction() const;

protected:
    void init(){
        logTransaction();
    }
};

void Transaction::logTransaction() const {
    std::cout << "log base class transaction" << std::endl;
}

class BuyTransaction: public Transaction{
public:
/*
    BuyTransaction(){
        init();
    }
*/
    virtual void logTransaction() const;
};

void BuyTransaction::logTransaction() const {
    std::cout << "log buy derived class transaction" << std::endl;
}

class SellTransaction: public Transaction{
public:
    /*
    SellTransaction(){
        init();
    }
     */
    virtual void logTransaction() const;
};

void SellTransaction::logTransaction() const {
    std::cout << "log sell derived class transaction" << std::endl;
}

int main(){
    BuyTransaction buyTransaction;
    return 0;
}