//
//  main.cpp
//  CCOTest
//
//  Created by - on 2017/02/07.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile("segments.in");
    ofstream outFile("segments.out");
    // Creates an ofstream object named myFile
    
    if (! inFile) // Always test file open
    {
        cout << "Error opening output file" << endl;
        return -1;
    }
    
    int i, n;
    inFile >> n;
    int L[n+1];
    int R[n+1];
    for (i=1; i<=n; i++) {
        inFile >> L[i] >> R[i];
        // cout << L[i] << " " << R[i] << endl;
    }
    int lcost, rcost, llcost;
    lcost =n-L[n];
    rcost =n-2*L[n]+R[n];
    for (i=n-1; i>=1; i--) {
        llcost =1+R[i]-L[i] +min(abs(L[i+1]-R[i])+lcost, abs(R[i+1]-R[i])+rcost);
        rcost =1+R[i]-L[i] +min(abs(L[i+1]-L[i])+lcost, abs(R[i+1]-L[i])+rcost);
        lcost =llcost;
    }
    // cout << "Final answer" << endl;
    cout << min(L[1]-1+lcost,R[1]-1+rcost) << endl;
    return 0;
}
