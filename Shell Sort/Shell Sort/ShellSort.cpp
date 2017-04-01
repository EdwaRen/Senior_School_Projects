//
//  main.cpp
//  Shell Sort
//
//  Created by - on 2017/01/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>

#include <math.h>
#include <time.h>

using namespace std;
int shellSort(int arr[], int l, int k);

int findlargest(int arr[], int k) {
    int result = -999999999;
    
    for (int x = 0; x < k; x++) {
        
        if (arr[x] > result && arr[x] < k) {
            result = arr[x];
        }
    }
    
    return (result-1);
}

void randomizeArray(int arr[], int l) {
    int count = 0;
    for (int x =0; x < l; x++) {
        arr[x] = rand()%999;
        count++;
        //cout << arr[x] << " ";
        if (count == 10) {
            //cout << endl;
            count = 0;
        }
    }
    //cout << endl;
}

int main(int argc, const char * argv[]) {
    
    srand(static_cast<uint32_t>(time(0)));
    int count = 0;
    int arr[500];
    for (int x =0; x < 500; x++) {
        arr[x] = rand()%999;
        count++;
        cout << arr[x] << " ";
        if (count == 10) {
            cout << endl;
            count = 0;
        }
    }
    
    shellSort(arr, 500, 3);
    count = 0;
    for (int x =0; x < 500; x++) {
        count++;
        cout << arr[x] << " ";
        if (count == 10) {
            cout << endl;
            count = 0;
        }
    }
    
    
    

    
    
    
    
    //Question 6:
    double secondCount1 = 0;
    double secondCount2 = 0;
    double secondCount3 = 0;

    for (int x = 0; x< 100; x++) {
        randomizeArray(arr, 500);

        clock_t start = clock();
        shellSort(arr, 500, 3);
        clock_t stop = clock();
        double elapsed = double(stop - start) / CLOCKS_PER_SEC;

        //cout << secondsNew << endl;
        for (int x =0; x < 500; x++) {
            //cout << arr[x] << " ";
        }
        secondCount1 = secondCount1 + elapsed;
        //cout << "\n" << elapsed << endl;
    }
    cout<< "Average time for K division value of 3: " <<secondCount1/100.0<<endl;
    
    for (int x = 0; x< 100; x++) {
        randomizeArray(arr, 500);
        
        clock_t start = clock();
        shellSort(arr, 500, 4);
        clock_t stop = clock();
        double elapsed = double(stop - start) / CLOCKS_PER_SEC;
        
        //cout << secondsNew << endl;
        for (int x =0; x < 500; x++) {
            //cout << arr[x] << " ";
        }
        secondCount2 = secondCount2 + elapsed;
        //cout << "\n" << elapsed << endl;
    }
    cout<< "Average time for K division value of 4: " <<secondCount2/100.0<<endl;
    
    for (int x = 0; x< 100; x++) {
        randomizeArray(arr, 500);
        
        clock_t start = clock();
        shellSort(arr, 500, 5);
        clock_t stop = clock();
        double elapsed = double(stop - start) / CLOCKS_PER_SEC;
        
        //cout << secondsNew << endl;
        for (int x =0; x < 500; x++) {
            //cout << arr[x] << " ";
        }
        secondCount3 = secondCount3 + elapsed;
        //cout << "\n" << elapsed << endl;
    }
    cout<< "Average time for K division value of 5: " <<secondCount3/100.0<<endl;


    
    /*
    for (int x = 0; x< 2; x++) {
        randomizeArray(arr, 500);

        clock_t t5,t6;
        t5=clock();
        shellSort(arr, 500, 4);
        t6=clock();
        float diffNew2 ((float)t6-(float)t5);
        float secondsNew2 = diff / CLOCKS_PER_SEC;
        //cout << secondsNew << endl;
        secondCount2 = secondCount2 + secondsNew2;
    }
    cout<< "Average time for K division value of 4: " <<secondCount2<<endl;
    /*
    
    /*
    for (int x = 0; x< 2; x++) {
        randomizeArray(arr, 500);
        clock_t t3,t4;
        t3=clock();
        shellSort(arr, 500, 3);
        t4=clock();
        float diffNew ((float)t4-(float)t3);
        float secondsNew = diff / CLOCKS_PER_SEC;
        //cout << secondsNew << endl;
        secondCount3 = secondCount3 + secondsNew;
    }
    cout<< "Average time for K division value of 5: " <<secondCount3<<endl;
    */
    
    
    
    return 0;
}

int shellSort(int arr[], int l, int k) {
    
    int maxInterval = findlargest(arr, l);
    //cout << "MaxInterval: "<<maxInterval << endl;
    
    int numOfIntervals = ((l-1)/maxInterval)+1;
    
    int maxSorts = ((l-1)/maxInterval)+1;
    
    int i, temp, flag = 1, numLength = l;
    int d = maxInterval;
    while( flag || (d > 1))      // boolean flag (true when not equal to 0)
    {
        flag = 0;           // reset flag to 0 to check for future swaps
        
        for (i = 0; i < maxInterval; i++)
        {
            
            for(int x = 1; x< numOfIntervals; x++) {
                if (i + x*d < l) {
                    if (arr[i + x*d] > arr[i + (x-1)*d])
                    {
                        temp = arr[i + x*d];      // swap positions i+d and i
                        arr[i + x*d] = arr[i+(x-1)*d];
                        arr[i+(x-1)*d] = temp;
                        flag = 1;
                        //cout << "Swap made |" << arr[i+x*d] << ":" << i+(x-1)*d <<" " << arr[i+(x-1)*d] <<  ":" << i + x*d << "| "; // tells swap has occurred
                    }
                }
            }
        }
        d = ((d-1)/k);
        if (d <= 0) {
            d = 1;
        }
        //cout << d << endl;
        
        //cout << "\nMaxInterval: " << d << endl;
        /*
        for (int x =0; x < 500; x++) {
            cout << arr[x] << " ";
        }
        */
        
        //cout << endl;
    }
    return 0;
}

