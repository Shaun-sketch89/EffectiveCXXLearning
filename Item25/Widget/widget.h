#include <vector>

class WidgetImpl{
public:
    WidgetImpl(std::vector<double> pv);
private:
    std::vector<double> v;
};

class Widget{
public:
    Widget(WidgetImpl *p);
    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs);
    void swap(Widget& other);
private:
    WidgetImpl *pImpl;
};
