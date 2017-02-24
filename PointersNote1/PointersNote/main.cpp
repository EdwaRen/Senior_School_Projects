//
//  main.cpp
//  PointersNote
//
//  Created by - on 2016/10/31.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
using namespace std;


void cubeByPointer (int* num) {
    //FInds the cube of a integer
    *num = (*num)*(*num)*(*num);
    cout << "Cubed: " << *num << endl;
    
}

void increment10 (int * num) {
    //Adds 10 to a integer
    *num += 10;
    cout << "Incremented by 10: " << *num << endl;
    
}

void squareByPointer (int* num) {
    //Squares two numbers
    *num = (*num)*(*num);
    cout << "Squared: " << *num << endl;
    
}

void sumTwoInt (int* num1, int* num2) {
    //Sums two integers
    int sum;
    sum = *num1 + *num2;
    cout << "Two int sum: " << sum << endl;
}

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello World!\n";
    //Creates the neccessary pointers and addresses them
    int sideLength = 10;
    int *pnum;
    pnum = &sideLength;
    
    int toBeIncrement = 15;
    int* pincrement;
    pincrement = &toBeIncrement;
    
    cout << "\nQ1:" << endl;
    cubeByPointer(pnum);
    
    cout << "\nQ2:" << endl;
    increment10(pincrement);
    
    int toBeCubed = 10;
    int toBeSquared = 10;
    int* pCubeSq;
    pCubeSq = &toBeCubed;
    
    cout << "\nQ3:" << endl;
    cubeByPointer(pCubeSq);
    pCubeSq = &toBeSquared;
    squareByPointer(pCubeSq);
    
    cout << "\nQ4:" << endl;
    //Creates the neccessary pointers and addresses them
    int num1 = 10;
    int num2 = 10;
    int* toBeSummed1;
    int* toBeSummed2;
    toBeSummed1 = &num1;
    toBeSummed2 = &num2;
    pCubeSq = &toBeCubed;
    sumTwoInt(toBeSummed1, toBeSummed2);
    
    
    
    
    
    
}

