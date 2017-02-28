//
//  main.cpp
//  UML_Diagrams
//
//  Created by - on 2017/01/31.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class fraction {
    
    private: int numerator = 0;
    private: int denominator;
    
    void FractionValue();
    void FractionValue(int num, int denum);
    
    public: int getNumerator();
    public: int getDenominator();
    void setNumerator(int n);
    void setDenominator(int n);
    public: string toString();
                          
    
                          
    
    
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
