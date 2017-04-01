//
//  main.cpp
//  QuickSort
//
//  Created by - on 2017/01/19.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void quickSort(int arr[], int low, int high);

int main(int argc, const char * argv[]) {
    // insert code here...
    srand(static_cast<uint16_t>(time(0)));

    int arr[100];
    
    for (int x = 0; x<100; x++) {
        arr[x] = rand()%250;
        cout << arr[x] << " ";
    }
    cout << endl;
    quickSort(arr, 0, 100);
    cout << endl;
    for (int x = 0; x<100; x++) {
        cout << arr[x] << " ";
    }
    
    return 0;
}

void quickSort(int arr[], int low, int high) {
    
    
    int left = low;
    int right = high;
    
    bool moving_Left = true;
    bool moving_Right = false;
    
    if (low < high) {
        bool currentDirection = moving_Left;
        int left = low;
        int right = high;
        int pivot = arr[low];
        
        while (left < right) {
            
            if (currentDirection == moving_Left) {
                
                while (left < right && arr[right] >= pivot) {
                    right--;
                }
                
                arr[left] = arr[right];
                currentDirection = moving_Right;
                
            }
            if (currentDirection == moving_Right) {
                
                while (left < right && arr[left] <= pivot) {
                    left++;
                }
                arr[right] = arr[left];
                currentDirection = moving_Left;
                
            }
        }
        
        
        arr[right] = pivot;
        quickSort(arr, low, left-1);
        quickSort(arr, right+1, high);
        
    }
    
}
