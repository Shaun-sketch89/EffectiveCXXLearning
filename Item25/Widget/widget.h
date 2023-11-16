#include <vector>
#include <iostream>

class WidgetImpl{
public:
    WidgetImpl(std::vector<double> pv);
    double sumDataImpl();
private:
    std::vector<double> v;
};

class Widget{
public:
    Widget(WidgetImpl *p);
    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs);
    void swap(Widget& other);
    void showInfo();
private:
    WidgetImpl *pImpl;
};
