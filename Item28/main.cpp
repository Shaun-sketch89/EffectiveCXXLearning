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

// Store point data for Rectangle class
struct RectData{
    RectData(const Point &ul, const Point &lr): ulhc(ul), lrhc(lr) {}
    Point ulhc;
    Point lrhc;
};

class Rectangle{
public:
    Rectangle(Point ulhc, Point lrhc): pData(new RectData(ulhc, lrhc)){}
    Point& upperLeft() const {return pData->ulhc;}
    Point& lowerRight() const {return pData->lrhc;}
private:
    std::shared_ptr<RectData> pData;
};

int main(){
    Point coord1(0,0);
    Point coord2(100,100);
    const Rectangle rec(coord1, coord2);
    rec.upperLeft().setX(50);
    std::cout << rec.upperLeft() << std::endl;
}