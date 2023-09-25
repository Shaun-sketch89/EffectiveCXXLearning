//
// Created by 姚轩 on 2023/9/24.
//
/*
对于数组
数组类型变量的三个要求：
 1. 数组长度固定不变
 2. 编译时需知道长度
 3. 数组只在定义它的语句块中存在
实际很多情况我们需要在运行时动态地分配数组，与数组变量不同的是：
 1. 数组变量通过类型、数组名和维数定义；而动态分配数组只需制定类型和数组长度，new表达式返回指向数组第一个元素的指针
 2. 编译时不必知道其长度，可以在运行时确定其长度）
 3. 动态分配的数组将一直存在，直到程序显示释放
 4. 动态分配的对象存放在free store或heap中。C中使用malloc和free；C++中使用new和delete。

动态分配数组时
 如果数组元素是类类型，将使用该类的默认构造函数初始化；如果是built-in type，则无初始化；若初始化，可以加一对空圆括号，初始化的默认值都是一样的，不像数组类型可以初始化为不同的值，例：
 int *pia = new int[10]()

new除了可以动态创建数组，也可用于创建单个对象（object）（只需指定类型，不需要命名，返回指向对象的指针）
*/

int get_size(){
    return 5;
}

int main(){
    int size = get_size();
    int test_arr[size];

    // bad
    //const int *pci_bad = new const int[100];

    // ok; const built-in type array must be initialized
    const int *pci_ok = new const int[size]();

    // if we forget [], compiler won't discover this problem so that it will cause memory leak
    delete [] pci_ok;

    return 0;
}