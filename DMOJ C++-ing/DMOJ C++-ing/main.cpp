//
//  main.cpp
//  DMOJ C++-ing
//
//  Created by - on 2017/06/08.
//  Copyright © 2017 Edward Ren-inc. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created" << endl;};
    Animal(const Animal& other): name(other.name) {cout << "ANimal created by copying" << endl;};
    void setName(string name) {this->name = name;};
    void speak() const { cout << "Name name is " << name << endl;};
    
    
    
    
};

int main(int argc, const char * argv[]) {
    Animal tiger;
    tiger.setName("Boby");
    tiger.speak();
    
    Animal human;
    human = Animal(tiger);
    human.speak();

    
    
    
    return 0;
}
