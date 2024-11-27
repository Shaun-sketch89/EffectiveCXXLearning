#include "queue.h"

int main() {
    Queue<int> qi;
    short s = 42;
    int i = 42;
    qi.push(s);
    qi.push(i);
    std::cout << qi << std::endl;
    return 0;
}
