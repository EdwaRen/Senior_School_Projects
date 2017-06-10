//
//  The Odd Number.cpp
//  
//
//  Created by - on 2017/06/06.
//
//

#include "The Odd Number.hpp"


int a[1000000];
int a2[1000000];

int n = 0;
cin >> n;

for (x = 0; x < n; x++) {
    a2[a[x]]++;
}
for (x = 0; x < n; x++) {
    if a2[x]!= 0 {
        cout << a2[x]
    }
}
