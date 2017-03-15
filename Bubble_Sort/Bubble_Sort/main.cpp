//
//  main.cpp
//  Bubble_Sort
//
//  Created by - on 2016/12/23.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;


void bubbleSort_Smallest(int arr[], int length) {
    bool sorted = false;
    for(int i = length-1; i > 0 && !sorted; i--) {
        sorted = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[j+1])
            {
                sorted = false;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void shakerSort(double arrr[], int length) {
    
    bool stopProcessing = false;
    
    do {
        
        bool swapped = false;
        for (int i = 0; i < length-1; i++) {
            if (arrr[i] > arrr[i+1] ) {
                double test;
                test = arrr[i];
                arrr[i] = arrr[i+1];
                arrr[i+1] = test;
                swapped = true;
            }
        }
        //cout << "Wtf I hate my life--" << swapped << "--Trueorfalse";
        cout << endl;
        for (int i = 0; i <9 ; i++) {
            cout <<arrr[i] << " ";
        }
        if (swapped == false) {
            stopProcessing = true;
        }
        swapped = false;
        for (int i = length-1; i >0; i--) {
            if (arrr[i] < arrr[i-1]) {
                double test;
                test = arrr[i];
                arrr[i] = arrr[i-1];
                arrr[i-1] = test;
                swapped = true;
            }
        }
        if (swapped == false) {
            stopProcessing = true;
        }
        cout << endl;
        
    } while (stopProcessing == false);
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    srand(static_cast<uint32_t>(time(0)));
    
    int arr[6];
    arr[0] = 3;
    
    for (int i = 1; i<6; i++) {
        arr[i] = rand()%12;
    }
    
    bubbleSort_Smallest(arr, 6);
    
    for (int i = 0; i <6 ; i++) {
        cout <<arr[i] << " ";
    }
    
    cout << endl;
    cout << "\nQuestion 3:" << endl;
    //Q3
    double arrr[9];
    for (int i = 0; i<9; i++) {
        arrr[i] = rand()%12;
        arrr[i] = round(arrr[i]*100);
        arrr[i] = arrr[i]/100;
    }
    for (int i = 0; i <9 ; i++) {
        cout <<arrr[i] << " ";
    }
    cout << endl;
    shakerSort(arrr, 9);
    for (int i = 0; i <9 ; i++) {
        cout <<arrr[i] << " ";
    }
    
    cout <<endl;
    
    return 0;
}





