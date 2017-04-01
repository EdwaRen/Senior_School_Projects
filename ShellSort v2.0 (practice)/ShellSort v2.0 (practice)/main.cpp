//
//  main.cpp
//  ShellSort v2.0 (practice)
//
//  Created by - on 2017/01/20.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;
void shellSort(int arr[], int length, int k);
void quickSort (int arr[], int low, int high);
void insertion(int arr[], int length);
int findKValue(int arr[], int length);
void bubble(int arr[], int length);
void selection(int arr[], int length);
int binarySearch(int arr[], int value, int low, int high);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "test";

    srand(static_cast<uint16_t>(time(0)));
    
    
    cout << "test";
    int arr[100];
    
    for (int x = 0; x<50 ;x++) {
        arr[x] = rand()%80;
        cout << arr[x] << " ";
    }
    
    //shellSort(arr, 50, 39);
    quickSort(arr, 0, 49);
    //insertion(arr, 50);
    //bubble(arr, 50);
    //selection(arr, 50);
    
    cout << endl;
    for (int x = 0; x<50 ;x++) {
        cout << arr[x] << " ";
    }
    
    findKValue(arr, 50);
    
    int toFind = 25;
    binarySearch(arr, toFind, 0, 49);
    
    return 0;
}

int binarySearch(int arr[],int value, int low, int high) {
    bool found = false;
    
    while (low <=high) {
        
        int middle = (low+high+1)/2;
        
        if (arr[middle] > value) {
            high = middle-1;
        } else if (arr[middle] < value) {
            low = middle +1;
        } else if (arr[middle] == value) {
            cout << "Value ahs been found" << endl;
            return 1;
        }
        
    }
    cout <<"Error -1" << endl;
    return 0;
    
    /*
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

     */
    
}

int findKValue(int arr[], int length) {
    int k = 0 ;
    for (int x = 0; x<length; x++) {
        
        if (arr[x] > k && arr[x] < length) {
            k = arr[x];
        }
        
    }
    cout << "K-value is: " << k << endl;
    return k;
    
}

/*
void selection(int arr[], int length) {
    
    
    for (int x = length -1; x >0; x--) {
        int posMax = 0;

        int j = x;
        for (int j = 0; j <=x ; j++) {
            if (arr[j] > arr[posMax]) {
                posMax = j;
            }
        }
        int temp = arr[x];
        arr[x] = arr[posMax];
        arr[posMax] = temp;
        
    }
    
}

void bubble(int arr[], int length) {
    
    bool sorted = true;
    for (int x = length; x > 0 && sorted == true; x--) {
        
        sorted = false;
        for (int i = 1; i < x; i++) {
            if ( arr[i] < arr[i-1]) {
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                sorted = true;
            }
            
        }
        
    }
    
    
}
*/

void insertion(int arr[], int length) {
    
    for (int x = 0; x < length ; x++) {
        
        int j = x;
        while (j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

}

void selection(int arr[], int length) {
    
    int posMax = 0;
    for (int x = length-1; x>0;x--) {
        posMax = 0;
        for (int j = 1; j <= x; j++) {
            if (arr[j] > arr[posMax]) {
                posMax = j;
            }
        }
        int temp = arr[x];
        arr[x] = arr[posMax];
        arr[posMax] = temp;
        
    }
}

void bubble(int arr[], int length) {
    
    bool sorted = true;
    for (int x = length; x >0 && sorted == true ;x--) {
        sorted = false;
        for (int j = 1; j < x; j++) {
            
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                sorted = true;
            }
            
        }
    }
}

void shellSort(int arr[], int length, int k) {
    
    bool sorted = true;
    
    while (sorted == true || k>1) {
        sorted = false;
        for (int x = 0; x < length - k; x++) {
            int count = 0;
            while (x-count*k >=0 && arr[x-count*k] > arr[x+k-count*k]) {
                sorted = true;
                int temp = arr[x-count*k];
                arr[x-count*k] = arr[x+k-count*k];
                arr[x+k-count*k] = temp;
                count++;
            }
        }
        k = (k-1)/3;
        if (k<=0) {
            k = 1;
        }
        
    }
    
    
}

void quickSort(int arr[], int low, int high) {
    bool movingLeft = true;
    bool movingRight = false;
    
    if (low < high){
        int left = low;
        int right = high;
        int pivot = arr[low];
        bool currentDirection = movingLeft;
        
        while (left < right) {
            
            if (currentDirection == movingLeft) {
                while (left<right && arr[right] >= pivot) {
                    right--;
                }
                arr[left] = arr[right];
                currentDirection = movingRight;
            }
            
            if (currentDirection == movingRight) {
                while (left<right && arr[left] <= pivot) {
                    left++;
                }
                arr[right] = arr[left];
                currentDirection = movingLeft;
                
            }
        }
        
        arr[left] = pivot;
        quickSort(arr, low, left-1);
        quickSort(arr, right+1, high);
        
    }
    
    
}


/*
void insertion(int arr[], int length) {
    
    
    for (int x = 0; x < length; x++) {
        int j = x;
        while (j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
            
        }
        
    }
    
    
}

void insertion2(int arr[], int length) {
    bool sorted = false;
    
    for (int x = 1; x < length; x++) {
        
        int j = x;
        while (j>0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        
    }
    
}



void quickSort (int arr[], int low, int high){
    bool moving_left = true;
    bool moving_right = false;
    //bool currentDireciton = moving_left;
    
    if (low < high) {
        int pivot = arr[low];
        int left = low;
        int right = high;
        bool currentDireciton = moving_left;

        
        while (left < right) {
            
            if (currentDireciton == moving_left) {
                
                while (left < right && arr[right] >= pivot) {
                    right--;
                }
                arr[left] = arr[right];
                currentDireciton = moving_right;
            }
            
            if (currentDireciton == moving_right) {
                
                while (left < right && arr[left] <= pivot) {
                    left++;
                }
                arr[right] = arr[left];
                currentDireciton = moving_left;
            }
            
        }
        
        arr[left] = pivot;
        quickSort(arr, low, left-1);
        quickSort(arr, right+1, high);
    }
}






void shellSort (int arr[],int length,  int k) {
    bool sorted = true;
    while (sorted == true || k>1) {
        sorted = false;
        for (int x = 0; x < length - k; x++) {
            int count = 0;
            while (x - count*k >=0 && arr[x-count*k] > arr[x+k-count*k]) {
                sorted = true;
                int temp = arr[x-count*k];
                arr[x-count*k] = arr[x+k-count*k];
                arr[x+k-count*k] = temp;
                count++;
            }
            
        }
        k = (k-1)/3;
        if (k <=0) {
            k =1;
        }
        
        
        
    }
    
 
}
*/




