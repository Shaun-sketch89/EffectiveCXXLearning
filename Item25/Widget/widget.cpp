#include "widget.h"

WidgetImpl::WidgetImpl(std::vector<double> pv) :v(pv) {}

double WidgetImpl::sumDataImpl() {
    double res = 0.0;
    for (size_t i = 0; i < v.size(); i++){
        res += v[i];
    }
    return res;
}

Widget::Widget(WidgetImpl *p) :pImpl(p) {}

Widget::Widget(const Widget &rhs){
    *pImpl = *(rhs.pImpl);
}

Widget& Widget::operator=(const Widget &rhs) {
    *pImpl = *(rhs.pImpl);
    return *this;
}

void Widget::swap(Widget &other) {
    using std::swap;
    swap(pImpl, other.pImpl);
}

void Widget::showInfo() {
    std::cout << "sum: " << pImpl->sumDataImpl() << std::endl;
}