//
// Created by 姚轩 on 2023/9/16.
//
#include <iostream>

class Transaction{
public:
    explicit Transaction(const std::string& logInfo);
    void logTransaction(const std::string& logInfo) const;
};

Transaction::Transaction(const std::string &logInfo) {
    logTransaction(logInfo);
}

void Transaction::logTransaction(const std::string &logInfo) const {
    std::cout << logInfo << std::endl;
}

class BuyTransaction: public Transaction{
public:
    BuyTransaction(const std::string& param)
    : Transaction(createLogString(param)){}

private:
    // static member function: createLogString called before member variable initialized
    // through using static, compiler will complain if createLogString use member variable accidentally
    // if not static, when createLogString use member variable, it will cause undefined behaviour
    static std::string createLogString(const std::string& param){
        return param;
    }
};

int main(){
    BuyTransaction buyTransaction("log buyer transaction");
    return 0;
}