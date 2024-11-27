#include "queue.h"
#include <vector>
int main() {
    Queue<int> qi;
    short s = 42;
    int i = 42;
    qi.push(s);
    qi.push(i);
    std::cout << qi << std::endl;

    short arr[] = {1, 2, 3, 4, 5, 6, 7};
    Queue<int> qi2(arr, arr + 5);
    std::cout << qi2 << std::endl;
    std::vector<int> vec(arr, arr + 7);
    qi2.assign(vec.begin(), vec.end());
    std::cout << qi2 << std::endl;
    return 0;
}
