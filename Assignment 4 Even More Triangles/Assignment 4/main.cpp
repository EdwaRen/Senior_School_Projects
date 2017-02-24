//
//  main.cpp
//  Assignment 4 - Even More Triangles!
//
//  Created by - on 2016/10/19.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
//#include "stdafx.h"
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>
//#include <boost/lexical_cast.hpp>
#include <string>
#include <cstdlib>

int getNum() {
    //User inputs a number and returns its value
    double inputNum = 0;
    cin >> inputNum;
    return inputNum;
}

bool thisIsTheEnd(double a, double b, double c) {
    //Checks if all three numbers are 0 and displays an approximate end message if true
    if (a == b && b == c && c == 0) {
        cout<< a << " " << b << " " << c <<" Program was terminated by user" << endl;
        cout << ""<< endl;
        
        exit(0);
        return true;
    } else {
        return false;
    }
}

bool checkValid (double x, double y, double z) {
    
    if ((x > y + z)||(y>x+z) || (z > x + y)){
        //Checks if one side of the triangle is greater than the other two combined
        cout<< x << " " << y << " " << z <<" Triangle cannot be formed" << endl;
        return false;
    } else if ((x <=0)|| (y <=0) || (z<=0) ) {
        //Checks if one side of the triangle is 0 or negative
        cout<< x << " " << y << " " << z <<" Triangle cannot be formed - Invalid Length entry" << endl;
        return false;
    }
    
    else {
        return true;
    }
    
}

string sideClass(double x, double y, double z) {
    //Classifies the triangles by their side lengths
    if ((x == y) && (y==z)) {
        return "Equilateral";
    } else if ((x != y) && (y != z) && (z != x)) {
        return "Scalene";
    } else {
        return "Isoceles";
    }
    
}

string angleClass(double x, double y, double z) {
    //Classifies triangles by their largest angles.
    double largest = 3122;
    double meh = 12342;
    double meh2 = 12342;
    
    //Finds the largest side of the triangle
    if ((x>y) && (x>z)) {
        largest = x;
        meh = y;
        meh2 = z;
    } else if ((y>x) && (y>z)) {
        largest = y;
        meh = x;
        meh2 = z;
    } else if ((z>x) && (z > y)) {
        largest = z;
        meh = x;
        meh2 = y;
    }
    
    //Uses the pythogorean theory to determine if the triangle is right, acute or obtuse
    if ((largest*largest) == (meh*meh) + (meh2*meh2)) {
        return "Right";
    } else if ((largest*largest) > (meh*meh) + (meh2*meh2)) {
        return "Obtuse";
    } else if ((largest*largest) < (meh*meh) + (meh2*meh2)) {
        return "Acute";
    } else {
        //Eddie is not always perfect
        return "Crap I screwed up";
    }
}

int main(int argc, const char * argv[]) {
    
    bool validity = false;
    double firstNum = 0;
    double secondNum = 0;
    double thirdNum = 0;
    string sClass = "Derp";
    string aClass = "Derpity Derp";
    
    do {
        //Continues asking for input as long as the input values are invalid. when 0 0 0 is entered the program ends
        cout << "Provide three side lengths, x, y and z. - 0 0 0 to terminate." << endl;
        
        firstNum = getNum();
        secondNum = getNum();
        thirdNum = getNum();
        
        thisIsTheEnd(firstNum, secondNum, thirdNum);
        validity = checkValid(firstNum, secondNum, thirdNum);
        
    } while (validity == false);
    //sClass and aClass are the angle and side lengths
    sClass = sideClass(firstNum, secondNum, thirdNum);
    aClass = angleClass(firstNum, secondNum, thirdNum);
    
    //Outputs the results of the calculations for side and angle classificaitons
    if (checkValid(firstNum, secondNum, thirdNum) == true) {
        cout<< "Length x: "<< firstNum << " Length Y: " << secondNum << " Length Z: " << thirdNum << " Triangle Possible " << sClass << " " << aClass << endl;
    }
    
    //Finds perimeter and outputs it
    double perimeter = firstNum + secondNum + thirdNum;
    cout << "The perimeter of the triangle is " << perimeter<< endl;
    
    //Finds semi-perimeter and outputs it
    double semiPerimeter = 0;
    semiPerimeter = perimeter/2;
    //cout << "Calculation No.2 - Semi-Perimeter" << endl;
    cout << "The semi-perimeter of the triangle is " << semiPerimeter<< endl;
    
    //Finds the total area and outputs it
    double totalArea = 0;
    double s = semiPerimeter;
    totalArea = sqrt((s*(s-firstNum)*(s-secondNum)*(s-thirdNum)));
    //cout << "Calculation No.3 - Area " << endl;
    cout << "The area of the triangle is " << totalArea << endl;
    
    //Finds the radius of the circumsized circle and outputs it
    double radiusCircumsized = 0;
    double a = totalArea;
    radiusCircumsized = ((firstNum * secondNum * thirdNum)/(4*a));
    //cout << "Calculation No.4 - Radius of Circumsized Circle " << endl;
    cout << "The radius of the circumsized circle is " << radiusCircumsized << endl;
    
    //FInds the radius of the inscribed circle and outputs it
    double radiusInscribed = 0;
    radiusInscribed = ((2*a)/(perimeter));
    // cout << "Calculation No.5 - Radius of Inscribed Circle " << endl;
    cout << "The radius of the inscribed circle is " << radiusInscribed << endl;
    
    
    double num1 = firstNum;
    double num2 = secondNum;
    double num3 = thirdNum;
    double angleX = 0;
    double angleY = 0;
    double angleZ = 0;
    double x1 = firstNum;
    double y1 = secondNum;
    double z1 = thirdNum;
    
    cout << ""<<  endl;
    double theta = 0;
    
    //Uses the cosine formula to find the angle of each side length
    theta = ((((y1)*(y1))+((z1)*(z1))-((x1)*(x1)))/(2*z1*y1));
    angleX = acos(theta) * 180/3.141592653589793238463;
    
    theta = ((((x1)*(x1))+((z1)*(z1))-((y1)*(y1)))/(2*z1*x1));
    angleY = acos(theta) * 180/3.141592653589793238463;
    
    theta = ((((y1)*(y1))+((x1)*(x1))-((z1)*(z1)))/(2*x1*y1));
    angleZ = acos(theta) * 180/3.141592653589793238463;
    
    //Outputs the angle calculations.
    cout << "Calculation No.6 - Finding The Angles " << endl;
    cout << "AngleX = " << angleX << endl;
    cout << "AngleY = " << angleY << endl;
    cout << "AngleZ = " << angleZ << endl;
    
    
    return 0;
}





























