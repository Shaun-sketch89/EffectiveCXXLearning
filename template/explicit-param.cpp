/*
我们希望定义名为 sum、接受两个不同类型实参的函数模
板，希望返回类型足够大，可以包含按任意次序传递的任意两个类型的两个值的
和，怎样才能做到？应如何指定 sum 的返回类型？

// T or U as the returntype?
template <class T, class U> ??? sum(T, U);
*/

// 解决这一问题的一个办法，可能是强制 sum 的调用者将较小的类型强制转换为希望作为结果使用的类型
template<class T, class U>
T sum(T a, U b) {
    return a + b;
}

// 第二个办法，再引入一个返回值模版形参
template<class T1, class T2, class T3>
T1 sum2(T2 a, T3 b) {
    return a + b;
}

// poor design: Users must explicitly specify all three template parameters
template <class T1, class T2, class T3>
T3 alternative_sum(T2, T1);

int main(){
    int i; short s;
    sum(static_cast<int>(s), i);

    long lng;
    sum2<long>(lng, i);
    sum2<long>(i, lng);
    return 0;
}