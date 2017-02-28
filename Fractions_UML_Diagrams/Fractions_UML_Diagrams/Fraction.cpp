//
//  FractionClass.cpp
//  Fractions_UML_Diagrams
//
//  Created by - on 2017/02/02.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include "Fraction.h"
#include <sstream>      // std::stringstream
#include <string>


using namespace std;

Fraction::Fraction(const Fraction &f){

}

Fraction::Fraction(){
    //Fraction::numerator = 0;
    //Fraction::denominator = 0;
    
}

Fraction::Fraction(int num, int den) {
    Fraction::numerator = num;
    Fraction::denominator = den;

    
}

int Fraction::getNumerator() {
    int num;
    num = Fraction::numerator;
    return num;
}

int Fraction::getDenominator() {
    
    int denum;
    denum = Fraction::denominator;
    return denum;
    
}

void Fraction::setNumerator(int n) {
    Fraction::numerator = n;
}

void Fraction::setDenominator(int n) {
    Fraction::denominator = n;
}

string Fraction::toString() {
    
    stringstream text;
    text << Fraction::getNumerator() << "/" << Fraction::getDenominator();
    return text.str();
   
}

Fraction Fraction::add(Fraction f, Fraction g){
    
    int m = f.getDenominator();
    int n = g.getDenominator();
    cout << m << "," << n << endl;

    Fraction s = Fraction(0, 0);
    while(m!=n)
    {
        if(m < n)
        {
            m=m+f.getDenominator();
        }
        else
        {
            n=n+g.getDenominator();
        }
    }
    
    int a, b;
    cout << m << "," << n << endl;
    a = f.getNumerator()*(m/f.getDenominator());
    b = g.getNumerator()*(m/g.getDenominator());
    s.setNumerator(a+b);
    s.setDenominator(m);
    return s;
}

Fraction Fraction::subtract(Fraction f, Fraction g){
    
    int m = f.getDenominator();
    int n = g.getDenominator();
    Fraction s = Fraction(0, 0);

    while(m!=n)
    {
        if(m < n)
        {
            m=m+f.getDenominator();
        }
        else
        {
            n=n+g.getDenominator();
        }
    }
    
    int a, b;
    a = f.getNumerator()*(m/f.getDenominator());   //Numerator for f fraction
    b = g.getNumerator()*(m/g.getDenominator());    //Numerator for g fraction
    
    s.setNumerator(a-b);
    s.setDenominator(m);
    return s;
    
}

Fraction Fraction::multiply(Fraction f, Fraction g) {
    
    int m = f.getNumerator();
    int n = g.getNumerator();
    Fraction s = Fraction(0, 0);

    int a = f.getDenominator();
    int b = g.getDenominator();
    
    s.setNumerator(m*n);
    s.setDenominator(a*b);
    return s;
    
}

Fraction Fraction::divide(Fraction f, Fraction g) {
    
    int m = f.getNumerator();
    int n = g.getNumerator();
    Fraction s = Fraction(0, 0);

    int a = f.getDenominator();
    int b = g.getDenominator();

    s.setNumerator(m*b);
    s.setDenominator(n*a);
    return s;
    
    
}


