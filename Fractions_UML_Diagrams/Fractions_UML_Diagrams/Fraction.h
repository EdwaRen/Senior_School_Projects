//
//  Header.h
//  Fractions_UML_Diagrams
//
//  Created by - on 2017/02/02.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#ifndef Fraction_h
#define Fraction_h

using namespace std;

class Fraction{
private:int numerator;
private:int denominator;
public:
   
    
    Fraction();
    Fraction(int num, int den);
    Fraction(Fraction const &f);

    int numOfFractions;
    int getNumerator();
    int getDenominator();
    void setNumerator(int n);
    void setDenominator(int n);
    string toString();
    
    void add(Fraction f);
    void subtract(Fraction f);
    void multiply(Fraction f);
    void divide(Fraction f);
    Fraction add(Fraction f, Fraction g);
    Fraction subtract(Fraction f, Fraction g);
    Fraction multiply(Fraction f, Fraction g);
    Fraction divide(Fraction f, Fraction g);
    

    
    
    bool happy;
    void speak();
    void makeHappy();
    void makeSad();
    

    
};


#endif /* Header_h */
