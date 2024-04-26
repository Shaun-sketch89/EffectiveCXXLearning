//
// Created by 姚轩 on 2024/4/26.
// a better solution when a base class's virtual function is provided with a default parameter
//
#include <iostream>

class Shape{
public:
    enum ShapeColor {Red, Green, Blue};
    // non-virtual. Never redefine it.
    void draw(ShapeColor color = Red) const;
private:
    // pure virtual. Must be implemented
    virtual void doDraw(ShapeColor color) const = 0;
};

void Shape::draw(Shape::ShapeColor color) const {
    doDraw(color);
}

class Rectangle: public Shape{
private:
    virtual void doDraw(ShapeColor color) const;
};

void Rectangle::doDraw(Shape::ShapeColor color) const {
    std::cout << color << std::endl;
}

int main(){
    Shape *ps = new Rectangle;
    ps->draw();
    return 0;
}