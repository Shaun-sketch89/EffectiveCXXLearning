//
// Created by 姚轩 on 2023/10/25.
//
#include <iostream>
#include <cstddef>

// 需要被资源管理的类
class Screen {
public:
    Screen(int w=0, int h=0): width(w), height(h) {}
    int getResolution(){
        return width * height;
    }
private:
    int width;
    int height;
};

// 管理使用计数，只能被ScreenPtr访问
class ScrPtr {
    friend class ScreenPtr;
    Screen *sp;
    size_t use;
    ScrPtr(Screen *p): sp(p), use(1) {}
    ~ScrPtr() {delete sp;}
};

// 资源管理类，拷贝行为参考共享指针
class ScreenPtr{
public:
    ScreenPtr(Screen *p): ptr(new ScrPtr(p)) {}
    ScreenPtr(const ScreenPtr& orig): ptr(orig.ptr) {++ptr->use;}
    ScreenPtr& operator=(const ScreenPtr& orig){
        ptr = orig.ptr;
        ++ptr->use;
        return *this;
    }
    ~ScreenPtr() { if(--ptr->use == 0) delete ptr;}
    // 成员访问操作符实现const与非const两个版本
    Screen& operator*() {return *ptr->sp;}
    Screen* operator->() {return ptr->sp;}
    const Screen& operator*() const {return *ptr->sp;}
    const Screen* operator->() const {return ptr->sp;}
    // 返回使用计数
    int use_count(){
        return ptr->use;
    }
private:
    ScrPtr *ptr;
};

int main(){
    ScreenPtr ps(new Screen(1920, 1720));
    // 使用ScreenPtr重载的解引用操作符和箭头操作符，通过资源管理类来访问被管理类的成员
    std::cout << (*ps).getResolution() << std::endl;
    std::cout << ps->getResolution() << std::endl;
    {
        // 注意当资源管理类本身发生拷贝时发生了什么
        // 资源管理类的赋值拷贝
        ScreenPtr ps2 = ps;
        // 资源管理类的构造拷贝
        ScreenPtr ps3(ps2);
        std::cout << ps2.use_count() << std::endl;
    }
    std::cout << ps.use_count() << std::endl;
}