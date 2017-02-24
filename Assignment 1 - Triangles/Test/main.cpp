//
//  main.cpp
//  Assignment 1 - Triangles
//
//  Created by - on 9/15/16.
//  Copyright © 2016 Eddie Of the Ren. All rights reserved.
//

#include <iostream>
//#include "stdafx.h"
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>

bool IsValid(int num1, int num2, int num3)
{
    bool result;
    
    if (num1 > (num2+ num3))
        result = false;
    else if (num2 > (num1+num3))
        result = false;
    else if (num3 > (num1+num2))
        result = false;
    else
        result = true;
    return (result);
}

int getTheta(int num1, int num2, int num3) {
    
    double theta = 0;
    theta = ((((num1)*(num1))+((num2)*(num2))-((num3)*(num3)))/(2*num1*num2));
    
    double num1s = num1 * num1;
    double num2s = num2 * num2;
    double num3s = num3 * num3;
    cout <<"num1 squared is  " <<num1s<< endl;
    cout <<"num2 squared is  " <<num2s<< endl;
    cout <<"num3 squared is  " <<num3s<< endl;

    double theta2 = num1s + num2s - num3s;
    double theta3 = theta2/(2*num1*num2);
    
    cout <<"Theta2 " <<theta2<< endl;
    cout <<"Theta3 " <<theta3<< endl;

    
    cout <<"num value is function " <<num1<< num2<< num3<< endl;
    cout <<"Theta value is function " <<theta<< endl;

    double angle = 0;
    angle = acos(theta3) * 180/3.141592653589793238463;
    
    return angle;
    
}

int main ()
{
    
    std::cout << "Welcome to Eddie's Triangle program!!!!!!!"<< endl;
    double perimeter = 0;
    int xLength = 1;
    int yLength = 0;
    int zLength = 0;
    
    bool restart = false;
    do {
        
        bool enterPressed = false;

        //Getting user to input the values for each of the three variables
        std::cout << "CALCULATION No.1 - PERIMETER"<< endl;
        std::cout << "Please enter the length of the first side of the triangle"<< endl;
        cin >> xLength;
        std::cout << "Please enter the length of the second side of the triangle (previous entry = "<< xLength<< ")" << endl;
        cin >> yLength;
        std::cout << "Please enter the length of the third side of the triangle (previous entry = "<< yLength<< ")"<< endl;
        cin >> zLength;
        std::cout << "You have entered a "<< xLength<< ", " << yLength << ", " << zLength<< ", " << endl;
        
        std::cout << "" << endl;
        
        //Calculating the perimeter
        perimeter = xLength+ yLength + zLength;
        
        //Check if these numbers can validly create a triangle
        bool result = false;
        result = IsValid(xLength,yLength,zLength);
        if (result == 0){
            cout << "The entries are invalid and cannot form a triangle, restarting"<< endl;
            restart = true;
            enterPressed = false;
        } else if (result == 1){
            std::cout << "The perimeter of the triangle is: "<< perimeter << endl;
            restart = false;
        }
        
        std::cout << "" << endl;
        
     
        
    } while (restart == true);
    
    cout << ""<<  endl;
    double semiPerimeter = 0;
    semiPerimeter = perimeter/2;
    cout << "Calculation No.2 - Semi-Perimeter" << endl;
    cout << " The semi-perimeter of the triangle is " << semiPerimeter<< endl;
    
    cout << ""<<  endl;
    double totalArea = 0;
    double s = semiPerimeter;
    totalArea = sqrt((s*(s-xLength)*(s-yLength)*(s-zLength)));
    cout << "Calculation No.3 - Area " << endl;
    cout << "The area of the triangle is " << totalArea << endl;
    
    cout << ""<<  endl;
    double radiusCircumsized = 0;
    double a = totalArea;
    radiusCircumsized = ((xLength * yLength * zLength)/(4*a));
    cout << "Calculation No.4 - Radius of Circumsized Circle " << endl;
    cout << "The radius of the circumsized circle is " << radiusCircumsized << endl;
    
    cout << ""<<  endl;
    double radiusInscribed = 0;
    radiusInscribed = ((2*a)/(perimeter));
    cout << "Calculation No.5 - Radius of Inscribed Circle " << endl;
    cout << "The radius of the inscribed circle is " << radiusInscribed << endl;
    
    
    double num1 = xLength;
    double num2 = yLength;
    double num3 = zLength;
    double angleX = 0;
    double angleY = 0;
    double angleZ = 0;
    double x1 = xLength;
    double y1 = yLength;
    double z1 = zLength;
    
    cout << ""<<  endl;
    double theta = 0;
    theta = ((((y1)*(y1))+((z1)*(z1))-((x1)*(x1)))/(2*z1*y1));
    angleX = acos(theta) * 180/3.141592653589793238463;
    
    theta = ((((x1)*(x1))+((z1)*(z1))-((y1)*(y1)))/(2*z1*x1));
    angleY = acos(theta) * 180/3.141592653589793238463;
    
    theta = ((((y1)*(y1))+((x1)*(x1))-((z1)*(z1)))/(2*x1*y1));
    angleZ = acos(theta) * 180/3.141592653589793238463;
   
    cout << "Calculation No.6 - Finding The Angles " << endl;
    cout << "AngleX = " << angleX << endl;
    cout << "AngleY = " << angleY << endl;
    cout << "AngleZ = " << angleZ << endl;
    
    return 0;
}



