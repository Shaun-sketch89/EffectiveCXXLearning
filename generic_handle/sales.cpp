#include <iostream>
#include "basket.h"

int main(){
    Basket basket;
	// 参与折扣的书籍1
    Bulk_item bulk("0-201-82470-1", 50, 5, 0.85);
	// 买了10本
    for(std::size_t i = 0; i != 10; ++i){
        basket.add_item(bulk);
    }

	// 参与折扣的书籍2
    Bulk_item bulk2("5-501-82470-1", 80, 5, 0.75);
	// 买了5本
    for(std::size_t i = 0; i != 5; ++i){
        basket.add_item(bulk2);
    }

	// 不参与折扣的书籍1
    Item_base bulk3("10-501-82470-1", 100);
	// 买了10本
    for (std::size_t i = 0; i != 10; ++i) {
        basket.add_item(bulk3);
    }
    std::cout << basket.total() << std::endl;
    return 0;
}