//
//  main.cpp
//  Inheritance
//
//  Created by - on 2017/03/06.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
using namespace std;

class Shape
{
protected:
    string name;
    
public:
    Shape(string s);
    void setName(string s);
    string getName() const;
    virtual double getArea() const = 0;
    
};


Shape::Shape(string s) {
    name = s;
}
void Shape::setName(string s) {
    name = s;
}
string Shape::getName() const {
    return name;
}



class Circle: public Shape {
private:
    double radius;
public:
    Circle(string n, double r) : Shape(n) {
        radius = r;
    }
    void setRadius (double r) {
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
    virtual double getArea() const {
        return 3.1415926*radius * radius;
    }
    
};

class Rectangle: public Shape {
    
    double length, width;
    public :
    Rectangle(string n, double l, double w):Shape(n) {
        length = l; width = w;
    }
    void setLength (double l) {
        length = l;
    }
    void setWidth (double w) {
        width = w;
    }
    double getLength() const {
        return length;
    }
    double getWidth() const {
        return width;
    }
    virtual double getArea() const {
        return length * width;
    }
    
    
};


class Triangle : public Shape {
    
    double base, width;
    
    public :
    Triangle(string n, double b, double w) : Shape(n) {
        base = b; width = w;
    }
    double getArea() const {
        return 0.5*base*width;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    /*
    //Shape s("Foo");
    //cout << s.getName() << endl;
    Circle c("Circle", 3.1);
    c.setName("Circle TOO");
    cout << c.getName() << endl;
    cout << c.getRadius() << endl;
    cout << c.getArea() << endl;
    
    Rectangle r("Rectangle", 4.2, 2.5);
    cout << r.getName() << endl;
    cout << r.getWidth() << " " << r.getLength()<<endl;
    cout << r.getArea() << endl;
    
    Triangle t("Triangle", 4, 3);
    cout << t.getArea() << endl;
     
     */
    Shape* shapes[3] = {new Circle("Circle", 2.1),
        new Rectangle("Rectangle", 3.1, 1.2),
        new Triangle("Triangle", 8.1, 2.3)};
    
    for (int i = 0; i < 3; i++) {
        cout << "Shape " << i << " area= " << shapes[i]->getArea() << endl;
    }
    
    return 0;
}
