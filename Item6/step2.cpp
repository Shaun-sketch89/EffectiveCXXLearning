/*
step1中报错发生在连接的时候，我们进一步修改程序，使得报错可以更早发生在编译阶段
 */

class UnCopyable{
protected:
    UnCopyable(){}
    ~UnCopyable(){}
private:
    UnCopyable(const UnCopyable&);
    UnCopyable& operator=(const UnCopyable&);
};

class HomeForSale: private UnCopyable{
public:
    HomeForSale(int price)
    :priceForSale(price)
    {}
    friend void copyHomeForSaleObject(const HomeForSale& src, HomeForSale& dst);
private:
    //HomeForSale(const HomeForSale&);
    //HomeForSale& operator=(const HomeForSale&);
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
