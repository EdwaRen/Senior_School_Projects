//
//  main.cpp
//  TestReview
//
//  Created by - on 2017/01/20.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

int doubleArr( double arr[], int length) {
    double previous =0.5;
    if (length == 0) {
        arr[0] = 0.5;
    } else {
        previous = doubleArr(arr, length-1);
    }
    arr[length] = previous * 2.0;
    return arr[length];
}

int sum_array_rec (double a[], int length){
    if (length == 0) {
        return a[0];
    } else {
        return a[length-1]+sum_array_rec( a, length-1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    srand(static_cast<uint32_t>(time(0)));
    double arr[10];
    for (int x = 0; x<10;x++) {
        arr[x] = x +1;
        cout << arr[x] << " ";
    }
    cout << endl;
    
    //doubleArr(arr, 10);
        for (int x = 0; x<10;x++) {
        cout << arr[x] << " ";
    }
    cout << endl;
    
    
    cout << sum_array_rec(arr, 10);
    
    cout << endl;

    
    return 0;
}
