//
//  main.cpp
//  Passing Arrays To Functions
//
//  Created by - on 2016/11/14.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
void modifyArray (int[], int);
void modifyElement(int);

 int sumNum = 0;



void printArray(int array[], int arraySize) {
    //Example 2a and 5b;
    cout << "Printing array: ";
    for (int x = 0; x< arraySize;x++) {
        cout << " " << array[x];
    }
    cout << endl;
}

void print_array_rec(int a[], int length){
    //Example 2b
    if (length == 0)
        cout << "\t";
    else
        print_array_rec( a, length-1);
    
    cout << a[length ] << "\t";
    
}

void twoPower (int twosArray[], int length) {
    //Example 3
    if (length == 0) {
        cout << "\t";

    }else {
        //twosArray[length] *= 2;

        twoPower(twosArray, length-1);
        //twosArray[length] *= 2;

    }
    
    twosArray[length+1] = twosArray[length]*2;

    cout << twosArray[length ] << "\t";
    
}

void sum(int array[], int length) {
    //Example 4a and 5d
    int sum = 0;
    for (int x = 0; x< length; x++) {
        sum += array[x];
    }
    cout << "The sum is: " << sum << endl;
    
}

int sum_array_rec (int a[], int length){
    //Example 4b
    if (length == 0)
        return a[0];
    else {
        return a[length-1]+sum_array_rec( a, length-1);
    }
}

void init_array(int array[], int arrayLength) {
    for (int x= 0; x<arrayLength;x++) {
        int randNum = 0;
        randNum = rand()%50 +1;
        array[x] = randNum;
        
    }
    
}
void printArrayRecursive(int array[], int length) {
    //Example 2a and 5b;
    if (length == 0) {
        cout << "Fresh, Recursively Printed Arrays: ";
    } else {
        printArrayRecursive(array, length-1);
    }
    cout << array[length] << " ";
}

void sumRecursive(int array[], int length) {
    //Example 5e
    
    
    
    if (length == 0) {
        cout << "";
        
    }else {
        
        sumRecursive(array, length-1);
        
    }
    
    sumNum = sumNum + array[length];
    
}

void findLargest( int array[], int arraySize) {
    //Example 5f
    
    int largest = 0;
    
    for (int x = 0; x< arraySize;x++) {
        if (array[x] > largest) {
            largest = array[x];
        }
    }
    
    cout << "The largest value in this array is:  " << largest << endl;
    
}

int findLargestRecurisve( int array[], int length) {
    //Example 5g
    int largest = 0;
    
    if (length == 0) {
        cout << "";
        largest = array[0];
    } else {
        largest =findLargestRecurisve(array, length - 1);
        if (array[length] >= largest){
            largest = array[length];
        }
    }
    
    return largest;
    
}

void findBirthdayChance(int array[], int arrayLength) {
    //Example 6 pt1
    cout << "The chances given x students is shown here (students: chance): " << endl;
    for (double  x = 1.0; x<=26.0; x++) {
        double chance = 1.0;
        int count = x;
        for (double i = 1.0; i<=26; i++) {
            
            if (i <= (x-1)) {
                chance = chance * ((365.0-i)/365.0);
            }
            
        }
        ostringstream outPutText;
        
        chance = 1 - chance;
        outPutText << "" << x << ":" << chance*100.0 <<"% ";
        string outText = outPutText.str();
        printf("%-18s", outText.c_str());
        
    }
    
    cout << endl;
}

double findBDayRecursive(int length) {
    //Example 6 pt2
    double chance;

    if (length == 1) {
        
        ostringstream outPutText;
        outPutText << "" << 1 << ":" << 0 <<"% ";
        string outText = outPutText.str();

        printf("%-18s", outText.c_str());

        chance = 1 * ((365.0-length)/365.0);
        //chance = 1-chance;
        
    } else {
        chance = ((365.0-length)/365.0) * findBDayRecursive(length -1);
        ///cout << "My chance: "<<chance<< " "<< (365.0-length)/365.0<< " "<<  endl;
    }
    ostringstream outPutText;
    double newChance = chance;
    newChance = 1.0-newChance;
    outPutText << "" << length+1 << ":" << newChance*100.0 <<"% ";
    string outText = outPutText.str();
    printf("%-18s", outText.c_str());
    return chance;
    
}

int main()
{
    
    srand(static_cast<uint32_t>(time(0)));
    int element[5];
    for (int index =0; index <= 4; index++) {
        element[index] = index;
    }
    cout << "Effects of passing entire array call by reference\n\n";
    cout << "\nExample 1" << endl;
    cout << "Value of the original array is \n";
    for (int x = 0; x <= 4; x++)
        cout << element[x] << " ";
    cout << endl;
    int ArraySize;
    
    cout << "\nNew values of the array" << endl;
    ArraySize =  ((sizeof(element))/(sizeof(*element)));

    modifyArray (element, ArraySize);
    
    
    cout << endl << endl;
    
    cout << "Effects of passing array element call-by-value\n";
    cout << "The value of element[3] is " << element[3] << endl;
    modifyElement(element[3]);
    cout << "The value of element[3] is " << element[3] << endl;
    
    cout << "\nExample 2a "<< endl;
    printArray(element, ArraySize);
    
    cout << "\nExample 2b" << endl;
    cout << "Printing array recursively: ";
    print_array_rec(element, (sizeof(element)/sizeof(*element)-1));
    
    cout << endl;
    
    element[0] = 1;
    
    cout << "\nExample 3" << endl;
    cout << "Creating twos array: ";
    twoPower(element, (sizeof(element)/sizeof(*element)-2));
    cout << endl;
    
    cout << "\nExample 4a" << endl;
    sum(element, (sizeof(element)/sizeof(*element)-1));
    
    cout << "\nExample 4b" << endl;
    cout << "The sum is: " << sum_array_rec(element, (sizeof(element)/sizeof(*element)-1)) -1<< endl;
    
    //cout <<"\nExample 5a " << endl;
    int newArray[10];
    init_array(newArray, (sizeof(newArray)/sizeof(*newArray)));
    
    cout <<"\nExample 5b (Prints array)" << endl;
    printArray(newArray, (sizeof(newArray)/sizeof(*newArray)));
    
    cout <<"\nExample 5c (Prints array recursively) " << endl;
    printArrayRecursive(newArray,(sizeof(newArray)/sizeof(*newArray)-1));
    cout << endl;
    
    cout <<"\nExample 5d (Sums array)" << endl;
    sum(newArray, (sizeof(newArray)/sizeof(*newArray)));
    
    cout <<"\nExample 5e (Sums array recursively)" << endl;
    cout << "The sum is: ";
    sumRecursive(newArray, (sizeof(newArray)/sizeof(*newArray)-1));
    cout << sumNum << endl;
    
    cout <<"\nExample 5f (Largest)" << endl;
    findLargest(newArray, (sizeof(newArray)/sizeof(*newArray)));
    
    cout <<"\nExample 5g (Largest recursively)" << endl;
    cout << "The largest value ofund recursively is: " << findLargestRecurisve(newArray, (sizeof(newArray)/sizeof(*newArray)-1))<< endl;
    
    cout << "\nExample 6" << endl;
    findBirthdayChance(newArray,(sizeof(newArray)/sizeof(*newArray)) );
    
    cout <<"\nExample 6 Recursive" << endl;
    cout << "The chances given x students is shown here (students: chance): " << endl;
    findBDayRecursive(25);
    
    cout << endl;
    return 0;
    
    
    

    
    
}




void modifyArray(int element[5], int ArraySize){
    //Example 1
    
    for (int x = 0; x< ArraySize;x++) {
        element[x] *=2;
        cout << element[x] << " ";
    }
    
    
}
void modifyElement(int a)
{
    //Example 1
    a*=2;
    cout << "The doubled value is " << a <<endl;
}
