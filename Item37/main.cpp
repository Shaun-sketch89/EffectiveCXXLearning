//
// Created by 姚轩 on 2024/4/26.
//
#include <iostream>

class Shape{
public:
    enum ShapeColor {Red, Green, Blue};
    virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle: public Shape{
public:
    virtual void draw(ShapeColor color) const;
};

// this way you must provide a parameter when draw is called because there is not a default parameter which is different from base class
/*
void Rectangle::draw(Shape::ShapeColor color) const {
    std::cout << "rectangle draw behaviour" << std::endl;
    std::cout << color << std::endl;
}
 */


// this will compile, but not good because of code duplication
// if base class's virtual function's default value changed, then it results in redefinition of inherited default parameter

void Rectangle::draw(Shape::ShapeColor color = Red) const {
    std::cout << color << std::endl;
}


int main(){
    Shape *ps = new Rectangle;
    ps->draw();
    return 0;
}