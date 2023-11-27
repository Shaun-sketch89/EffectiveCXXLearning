//
// Created by 姚轩 on 2023/11/27.
//
#include <iostream>

class Point{
    friend std::ostream& operator<<(std::ostream&, const Point&);
public:
    Point(int x, int y): x_val(x), y_val(y){}
    Point(const Point& p): x_val(p.x_val), y_val(p.y_val) {}
    void setX(int newVal){
        x_val = newVal;
    }
    void setY(int newVal){
        y_val = newVal;
    }
private:
    int x_val;
    int y_val;
};

// overload Point ostream
std::ostream& operator<<(std::ostream& out, const Point& point){
    out << point.x_val << "," << point.y_val;
    return out;
}

class Rectangle{
public:
    Rectangle(const Point& ul, const Point& lr): ulhc(ul), lrhc(lr){}
    // return values must be declared const reference
    const Point& upperLeft() const {return ulhc;}
    const Point& lowerRight() const {return lrhc;}
private:
    Point ulhc;
    Point lrhc;
};

int main(){
    Point coord1(0,0);
    Point coord2(100,100);
    const Rectangle rec(coord1, coord2);
    // this won't compile, because rec.upperLeft() returns a const and setX() is non-const method
    rec.upperLeft().setX(50);
    std::cout << rec.upperLeft() << std::endl;
}