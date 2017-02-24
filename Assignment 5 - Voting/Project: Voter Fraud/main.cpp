//
//  main.cpp
//  Assignment 5 - Voting
//
//  Created by - on 2016/10/19.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
//#include "stdafx.h"
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>
//#include <boost/lexical_cast.hpp>
#include <string>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << "Input a string of votes, only capitalized characters A-F will be counted, anything else would be considered spoiled.";
    cout << "   Ex: AASDFSDDARESFGAFDRTFGVAHWSTYFRDFXCGWRDAFSCGQRTWDAFSGRT"<< endl;
    
    string voteRaw = "Derp";
    int aCount =0;
    int bCount =0;
    int cCount =0;
    int dCount =0;
    int eCount =0;
    int fCount =0;
    int sCount =0;

    
    cin >>voteRaw;
    
    //This program will officially crash when the inputted string exceeds 100000 characters
    char voteArr[100000];
    
    strncpy(voteArr, voteRaw.c_str(), sizeof(voteArr));
    voteArr[sizeof(voteArr) - 1] = 0;
    
    
    for (int x = 0; x< voteRaw.length();x++) {
        //voteArr[x] = voteRaw.substr(x, 1);
        if (voteArr[x] == 'A'){
            aCount++;
        } else if (voteArr[x] == 'B'){
            bCount++;
        } else if (voteArr[x] == 'C'){
            cCount++;
        } else if (voteArr[x] == 'D'){
            dCount++;
        } else if (voteArr[x] == 'E'){
            eCount++;
        } else if (voteArr[x] == 'F'){
            fCount++;
        } else {
            sCount++;
        }
    }
    //Results
    cout << "" << endl;
    cout << "Candidate          Number of Votes" << endl;
    cout << "A                  " << aCount << endl;
    cout << "B                  " << bCount << endl;
    cout << "C                  " << cCount << endl;
    cout << "D                  " << dCount << endl;
    cout << "E                  " << eCount << endl;
    cout << "F                  " << fCount << endl;
    cout << "Total Votes        " << aCount + bCount + cCount + dCount + eCount + fCount << endl;
    cout << "Spoiled Votes      " << sCount << endl;


   
    
    /*
    copy(voteArr,
         voteArr + sizeof(voteArr) / sizeof(voteArr[0]),
         ostream_iterator<short>(cout, "\n"));
*/
    return 0;
}
