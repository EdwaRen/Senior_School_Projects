//
//  main.cpp
//  Fractions_UML_Diagrams
//
//  Created by - on 2017/02/02.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include "Fraction.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout<<"Welcome to Eddie's UML Program. Simple arithmetic functions are performed in part 1" << endl;
   
    cout<<endl;
    
    Fraction myFraction;
    
    
    Fraction myFrac;
    
    myFrac = Fraction(10, 35);

    
    myFrac = Fraction(10, 35);
    cout << "Original Fraction: 10 / 35" << endl << endl;
    cout << "getNumerator() =  "<<myFrac.getNumerator() << endl;
    cout << "getDenominator() = "<<myFrac.getDenominator() << endl;
    
    cout <<"\nNow give me a numerator and denominator:" << endl;
    int numerator, denominator;
    cin>> numerator;
    cin>> denominator;
    
    
    myFrac.setNumerator(numerator);
    myFrac.setDenominator(denominator);
    cout << "setNumerator() called"<< endl;
    cout << "setDenominator() called"<< endl;

    
    cout << "getNumerator() =  "<<myFrac.getNumerator() << endl;
    cout << "getDenominator() = "<<myFrac.getDenominator() << endl;
    cout << "toString function() = " << myFrac.toString() << endl;
    
    
    //Advanced UML Diagrams
    cout <<"\n\nWelcome to part 2 of Eddie's program. We will be performing advanced arithmetic. Please provide two pairs of numerators and denominators for two fractions"<<endl;
    Fraction f;
    Fraction s;
    
    int x[4];
    cin>>x[0];
    cin>>x[1];
    cin>>x[2];
    cin>>x[3];
    f.setNumerator(x[0]);
    f.setDenominator(x[1]);
    s.setNumerator(x[2]);
    s.setDenominator(x[3]);
    cout << x[0] << endl;
    
    
    Fraction out;
    

    out = out.add(f, s);
    
    cout << "\nAdded fraction: "<< f.toString() << " and " << s.toString() << " to get: " << out.toString() << endl;
    
    out = out.subtract(s, f);
    cout << "\nSubtracted fraction : "<< s.toString() << " and " << f.toString()<< " to get:" << out.toString() << endl;
    
    out = out.multiply(s, f);
    cout << "\nMultiplied fraction : "<< s.toString() << " and " << f.toString()<< " to get:" << out.toString() << endl;
    
    out = out.divide(s, f);
    cout << "\nDivided fraction : "<< s.toString() << " and " << f.toString()<< " to get:" << out.toString() << endl;
    
    cout<<endl;
    
    
    //myFrac.makeHappy();
    //myFrac.speak();
    //std::cout << "Hello, World!\n";
    return 0;
}



