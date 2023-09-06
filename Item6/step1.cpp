/*
我们不希望client无意识的对对象进行拷贝或者赋值
 1。我们声明copy constructor以及copy assignment constructor，这样编译器就不会自动生成
 2。我们将copy constructor以及copy assignment constructor放在private中，这样在外部用户无法调用
 3。还有一种特殊情况，在成员函数或者友元中仍然可以拷贝对象。因此我们对copy constructor以及copy assignment constructor只声明不定义。

这个程序在编译过程不会出错，但是在连接过程会报错，防止了用户无意识的拷贝对象
 */

class HomeForSale{
public:
    HomeForSale(int price)
    :priceForSale(price)
    {}
    friend void copyHomeForSaleObject(const HomeForSale& src, HomeForSale& dst);
private:
    HomeForSale(const HomeForSale&);
    HomeForSale& operator=(const HomeForSale&);
    int priceForSale;
};

void copyHomeForSaleObject(const HomeForSale& src, HomeForSale& dst){
    dst = src;
}


int main() {
    HomeForSale src(500);
    HomeForSale dst(600);

    copyHomeForSaleObject(src, dst);

    return 0;
}
