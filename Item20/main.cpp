//
// Created by 姚轩 on 2023/10/31.

// Item20: Things to Remember
// 1. Prefer pass-by-reference-to-const over pass-by-value. It’s typically more efficient and it avoids the slicing problem.
// 2. The rule doesn’t apply to built-in types and STL iterator and function object types. For them, pass-by-value is usually appropriate.
#include <iostream>

class Window{
public:
    Window(std::string n): wname(n) {}
    Window(const Window& w): wname(w.wname) {}
    std::string name() const;
    virtual void display() const;

private:
    std::string wname;
};

class WindowWithScrollBars: public Window{
public:
    WindowWithScrollBars(std::string n): Window(n) {}
    WindowWithScrollBars(const WindowWithScrollBars& w): Window(w) {}
    virtual void display() const;
};

std::string Window::name() const {
    return wname;
}

void Window::display() const {
    std::cout << "BaseWindow display" << std::endl;
}

void WindowWithScrollBars::display() const {
    std::cout << "WindowWithScrollBars display" << std::endl;
}

// pass-by-reference-to-const
void printNameAndDisplay(const Window& w){
    std::cout << w.name() << std::endl;
    w.display();
}

int main(){
    WindowWithScrollBars w("WindowWithScrollBars");
    printNameAndDisplay(w);
}