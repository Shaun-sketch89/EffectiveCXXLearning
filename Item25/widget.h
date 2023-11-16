#include <vector>
#include <iostream>

namespace WidgetStuff {
    template<typename T>
    class WidgetImpl {
    public:
        WidgetImpl(std::vector <T> pv) : v(pv) {}

        T sumDataImpl() {
            T res = 0;
            for (size_t i = 0; i < v.size(); i++) {
                res += v[i];
            }
            return res;
        }

    private:
        std::vector <T> v;
    };

    template<typename T>
    class Widget {
    public:
        Widget(WidgetImpl<T> *p) : pImpl(p) {}

        Widget(const Widget<T> &rhs) {
            *pImpl = *(rhs.pImpl);
        }

        Widget<T> &operator=(const Widget<T> &rhs) {
            *pImpl = *(rhs.pImpl);
            return *this;
        }

        void swap(Widget<T> &other) {
            // if we don't use "using std::swap", it will call member function itself!
            // or we can directly use std::swap
            using std::swap;
            swap(pImpl, other.pImpl);
        }

        void showInfo() {
            std::cout << "sum: " << pImpl->sumDataImpl() << std::endl;
        }

    private:
        WidgetImpl<T> *pImpl;
    };

    template<typename T>
    void swap(Widget<T> &a, Widget<T> &b) {
        std::cout << "specialized swap call" << std::endl;
        a.swap(b);
    }
}