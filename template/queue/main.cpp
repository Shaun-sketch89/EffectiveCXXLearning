#include <iostream>
#include "queue.h"

int main() {
    Queue<int> qi;
    short s = 42;
    int i = 42;
    qi.push(s);
    qi.push(i);
    std::cout << qi.front() << std::endl;
    qi.pop();
    std::cout << qi.front() << std::endl;
    return 0;
}
