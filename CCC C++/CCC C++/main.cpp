//
//  main.cpp
//  CCC C++
//
//  Created by - on 2017/02/14.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//


#include <iostream>
#include <valarray>
using namespace std;

int main() {
    
    int n = 0;
    cin >> n;
    
    int A[100001];
    
    for (int i = 0; i < 100001; i++){
        A[i] = 0;
    }
    
    int i = 0;
    for (int x = 0; x < n; x++){
        int s =0;
        cin>> s;
        A[i] = s;
        if (s == 0){
            A[i-1] = 0;
            i--;
        } else{
            i++;
        }
        
        
        
    }

    int sum = 0;
    for (int i = 0; i < 100001; i++){
        sum+= A[i];
    }
    cout<<sum << endl;
    
}
