#include "widget.h"

WidgetImpl::WidgetImpl(std::vector<double> pv) :v(pv) {}

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