#include <iostream>
#include "basket.h"

int main(){
    Basket basket;
    Bulk_item bulk("0-201-82470-1", 50, 5, 0.85);
    for(std::size_t i = 0; i != 10; ++i){
        basket.add_item(bulk);
    }
    Bulk_item bulk2("5-501-82470-1", 50, 5, 0.85);
    for(std::size_t i = 0; i != 5; ++i){
        basket.add_item(bulk2);
    }
    std::cout << basket.total() << std::endl;
    return 0;
}