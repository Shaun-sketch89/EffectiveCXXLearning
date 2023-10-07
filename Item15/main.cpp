//
// Created by 姚轩 on 2023/10/7.
//
#include <string>
#include <iostream>

class Investment{
public:
    Investment(int amount, const std::string& time)
    :total_amount(amount), transaction_time(time)
    {}
    int getAmount(){
        return total_amount;
    }
    std::string getTime(){
        return transaction_time;
    }
private:
    int total_amount;
    std::string transaction_time;
};

int main(){
    // Investment investment(50, "2023-10-7 16:00:00");
    // shared_ptr manages heap-based resources, we dynamically construct a Investment obj
    std::shared_ptr<Investment> pInv(new Investment(50, "2023-10-7 16:00:00"));

    // shared_ptr overloads operator->
    std::cout << "investment amount: " << pInv->getAmount() << std::endl;

    std::cout << "investment object used " << pInv.use_count() << " times" << std::endl;
    std::shared_ptr<Investment> pInv2 = pInv;
    std::cout << "investment object used " << pInv.use_count() << " times" << std::endl;

    return 0;
}