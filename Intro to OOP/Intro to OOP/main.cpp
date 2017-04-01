//
//  main.cpp
//  Intro to OOP
//
//  Created by - on 2017/01/26.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


struct Dog {
    
    string name;
    int age;
    
    
    
};


void initDog(Dog &d, string name, int age );

int main(int argc, const char * argv[]) {
    
    Dog d;
    d.name = "Spike";
    d.age = 2;
    
    cout << d.name << " " << d.age;
    
    initDog(d, "John. A Simspon", 345876);
    cout << d.name << " " << d.age;
    
    return 0;
}


void initDog(Dog &d, string name, int age) {
    
    d.name = name;
    d.age = age;
    
}
