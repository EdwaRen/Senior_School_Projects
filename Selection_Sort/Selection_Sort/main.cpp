//
//  main.cpp
//  Selection_Sort
//
//  Created by - on 2016/12/19.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//  Free and open source software licensed under GNU GPL v3.0.

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

#include <sstream>

using namespace std;


void selectSort_IgnoreFirstIfMax(int arr[], int n) {
    //pos_max will store the index of the largest element found in the unsorted
    int pos_max,temp, real_max = 0;
    bool firstTime = true;
    for (int i=n-1; i > 0; i--) { //i is the index of end of unsorted portion
        int count = 0;
        pos_max = 0; //assume first element is largest
        for (int j=1; j <= i; j++) {
            if (arr[j] < arr[pos_max]) {
                count++;
                //cout << "counted" << endl;
                pos_max=j; //if larger found, set new largest
            }
            if (arr[j] > arr[0]) {
                //cout << "counted" << endl;
                real_max=j; //if larger found, set new largest
            }
           
        }
        //swap element at i with largest element found in unsorted portion
        if (i == pos_max) {
        } else {
           
            cout << "uytrds: Realmax " << real_max<< endl;
            temp = arr[i];
            arr[i] = arr[pos_max];
            arr[pos_max] = temp;
        //}
        }
        firstTime = false;
    }
}

void selectSort_Smallest(int arr[], int n) {
    
    int pos_min, temp;
    
    for (int i = 0; i<n; i++) {
        pos_min = n-1;
        for (int j = n-1; j>=i; j--) {
            if (arr[j] < arr[pos_min]) {
                pos_min = j;
            }
        }
        cout << "Posmin" << pos_min << " i " << i << endl;
        temp = arr[i];
        arr[i] = arr[pos_min];
        arr[pos_min] = temp;
        
        /*
        for (int x = 0; x< n; x++) {
            cout << arr[x] << " ";
        }
        cout <<endl;
         */
    }
    
}

int main(int argc, const char * argv[]) {
    srand((static_cast<uint16_t>(time(NULL))));

    // insert code here...

    int numElements[6];
    numElements[0] = 5;
    numElements[1] = rand()%9;
    numElements[2] = rand()%9;
    numElements[3] = rand()%9;
    numElements[4] = rand()%9;
    numElements[5] = rand()%9;
    
    //Code that ignores first element if it is the max
    selectSort_IgnoreFirstIfMax(numElements, 6);
    for (int x = 0; x< sizeof(numElements)/sizeof(numElements[0]); x++) {
        cout << numElements[x] << " ";
    }
    cout <<endl;

    //Code that sorts by smallest first
    selectSort_Smallest(numElements, 6);
    for (int x = 0; x< sizeof(numElements)/sizeof(numElements[0]); x++) {
        cout << numElements[x] << " ";
    }
    
    return 0;
}
