//
//  main.cpp
//  Binary Searching and Sorting
//
//  Created by - on 2016/12/05.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

#include <sstream>
using namespace std;
int numElements[25];
int valueFind;

void createRndArray() {

    //cout << "Enter number of elements: ";
   
    //cin >> numElements;
    cout <<  "\nEnter lower limit: " ;
    int lowLim = 0;
    cin >> lowLim;
    cout << "Enter upper limit: ";
    int highLim = 0;
    cin >> highLim;
    cout << "Enter value to find: ";
    cin >> valueFind;
    if ((lowLim == -1) || (highLim == -1)) {
        cout << "\nThank you for playing (Exit Code -1)" << endl;
        exit(0);
    }

    if (highLim >= lowLim) {
        cout << "Randomly generated array: ";
        for (int x = 0; x< sizeof(numElements)/sizeof(numElements[0]); x++) {
            numElements[x] =  rand()%(highLim-lowLim +1) + lowLim;
            cout << numElements[x] << " ";
        }
    }
    else {
        cout <<"Check your lower and upper values again" << endl;
    }
    
    
    
}

int binarySearch(int arr[],int value, int low, int high) {
    
    while (low <= high) {
        cout << endl;

        for (int x = low; x<= high  ;x++) {
            cout << numElements[x] << " ";
        }
        
        int middle = (low+high+1)/2;
        
        if (arr[middle] > value) {
            high = middle-1;
        } else if (arr[middle] < value) {
            low = middle +1;
        } else if (arr[middle] == value) {
            cout << "Value has been found! " << middle << "," << low << "," << high << endl;
            return 1;
        }
       
    }
    cout << "Error Code -1, Value has not been found"<< endl;
    return 0;
    
    /*
    //low = 0;
    //high = sizeof(numElements)/sizeof(*numElements);
    int middle = 0;
    middle = (high+low+1)/2;
    cout << endl;
    for (int x = low; x<high;x++) {
        cout << numElements[x] << " ";
    }
   

    if (value < numElements[middle]) {
        //cout << "\nH-Low: " << low << " High: " << high << " Middle: " << middle << " MiddleEle: " << numElements[middle] << endl;

        if (middle == high) {
            cout<< "Instance where value is located cannot be found (ERROR: -1)" << endl;
        } else {
            binarySearch(value, middle, high);
        }
        
    } else if (value > numElements[middle]) {
        //cout << "\nL-Low: " << low << " High: " << high << " Middle: " << middle << " MiddleEle: " << numElements[middle] << endl;

        if ((value == numElements[middle-1]) && ((high-low) <4) ){
            //binarySearch(value, low, middle-1);
            cout << endl;
            for (int x = low; x<middle;x++) {
                cout << numElements[x] << " ";
            }
            cout << "\nValue is found at " << middle  <<": " << value << ": "<<numElements[middle-1]  << endl;
            
        } else if (middle == low+1) {
            cout<< "\nInstance where value is located cannot be found (ERROR: -1)" << endl;
        } else {
        binarySearch(value, low, middle);
        }
    } else if (value == numElements[middle]){
        if (low == high) {
            cout << "\nValue is found at " << middle +1 << endl;
        } else {
            binarySearch(value, middle, high);
        }
        //cout << "\nValue is found at " << middle +1 << endl;
    }
    
    */
    
    
}

int linearSearch(int myValue) {
    
    for (int x = 0; x<(sizeof(numElements)/sizeof(numElements[0])) ; x++){
        if (numElements[x] == myValue) {
              return x;
            break;
        }
    }
    
    return -1;
}

void sorter() {
    
    //int nums[] = {23,432,231,43,2,49,1,46,8,30,578,78,4,2,45,7,6,38,39,56,48,3};
    //Linear search and then sort the array FROM GREATEST TO LEAST
    for (int sortloop=0; sortloop<sizeof(numElements)/sizeof(*numElements);sortloop++){
        
        //Search the array for a MAX value
        
        int MaxIndex = sortloop; //assume the first spot holds the MAX value
        for (int j=sortloop; j<sizeof(numElements)/sizeof(*numElements); j++) {
            if (numElements[j] < numElements[MaxIndex]){ //check if next number is MAX
                MaxIndex = j; //num at i is more than current num at MaxIndex
            }
        } //end for loop that looks for MAX in array
        
        // by here we have the largest value in the array
        // store it in your array at the sorted loop spot (swap them)
        
        int temp = numElements[sortloop];
        numElements[sortloop]=numElements[MaxIndex];
        // replace MAX value in nums array with the value in the current MAX’s spot
        numElements[MaxIndex]= temp;
        //cout << nums[sortloop] << endl;
        
    } // end sort loop
    cout << "Sorted array: ";
    for (int x = 0; x<sizeof(numElements)/sizeof(*numElements); x++) {
        cout << numElements[x] << " ";
    }
}




int main(int argc, const char * argv[]) {
    
    srand((static_cast<uint16_t>(time(NULL))));
    
    do {
        
        cout << endl;
        cout << endl;
        cout << endl;
        createRndArray();
        cout << endl;
        
        
        int searchResult;
        searchResult = linearSearch( 5);
        if (searchResult == -1) {
            cout << "\nLinear: No results for this number were found in the array "<< endl;
        } else {
            cout << "\nLinear: The search number was found on the following item of the array: "<< searchResult +1 << endl;
        }
        
        cout << endl;
        //binarySearch(5, 0, sizeof(numElements)/sizeof(*numElements));
        
        sorter();
        cout << " " << endl;
        binarySearch(numElements, valueFind, 0, sizeof(numElements)/sizeof(*numElements));
    } while (1<2);
    
    

    
    
    
    return 0;
}
