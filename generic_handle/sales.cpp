#include <iostream>
#include "basket.h"

int main(){
    Basket basket;
	// �����ۿ۵��鼮1
    Bulk_item bulk("0-201-82470-1", 50, 5, 0.85);
	// ����10��
    for(std::size_t i = 0; i != 10; ++i){
        basket.add_item(bulk);
    }

	// �����ۿ۵��鼮2
    Bulk_item bulk2("5-501-82470-1", 80, 5, 0.75);
	// ����5��
    for(std::size_t i = 0; i != 5; ++i){
        basket.add_item(bulk2);
    }

	// �������ۿ۵��鼮1
    Item_base bulk3("10-501-82470-1", 100);
	// ����10��
    for (std::size_t i = 0; i != 10; ++i) {
        basket.add_item(bulk3);
    }
    std::cout << basket.total() << std::endl;
    return 0;
}