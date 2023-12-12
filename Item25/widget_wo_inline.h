#include <vector>
#include <iostream>

namespace WidgetStuff {
    template<typename T>
    class WidgetImpl {
    public:
        WidgetImpl(std::vector<T>);

        T sumDataImpl();

    private:
        std::vector <T> v;
    };

    // no inline
    template<typename T>
    WidgetImpl<T>::WidgetImpl(std::vector<T> pv): v(pv) {}

    // no inline
    template<typename T>
    T WidgetImpl<T>::sumDataImpl() {
        T res = 0;
        for (size_t i = 0; i < v.size(); i++) {
            res += v[i];
        }
        return res;
    }

    template<typename T>
    class Widget {
    public:
        Widget(WidgetImpl<T>*);
        Widget(const Widget<T>&);
        Widget<T> &operator=(const Widget<T>&);
        void swap(Widget<T>&);
        void showInfo();

    private:
        WidgetImpl<T> *pImpl;
    };

    // no inline
    template<typename T>
    Widget<T>::Widget(WidgetImpl<T> *p) : pImpl(p) {}

    // no inline
    template<typename T>
    Widget<T>::Widget(const Widget<T> &rhs) {
        *pImpl = *(rhs.pImpl);
    }

    // no inline
    template<typename T>
    Widget<T>& Widget<T>::operator=(const Widget<T> &rhs) {
        *pImpl = *(rhs.pImpl);
        return *this;
    }

    // no inline
    template<typename T>
    void Widget<T>::swap(Widget<T> &other) {
        // if we don't use "using std::swap", it will call member function itself!
        // or we can directly use std::swap
        using std::swap;
        swap(pImpl, other.pImpl);
    }

    // no inline
    template<typename T>
    void Widget<T>::showInfo() {
        std::cout << "sum: " << pImpl->sumDataImpl() << std::endl;
    }


    // swap
    template<typename T>
    void swap(Widget<T> &a, Widget<T> &b) {
        std::cout << "specialized swap call" << std::endl;
        a.swap(b);
    }
}