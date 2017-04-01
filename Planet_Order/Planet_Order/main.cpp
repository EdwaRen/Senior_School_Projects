//
//  main.cpp
//  Planet_Order
//
//  Created by - on 2016/12/19.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <string>

#include <ctime>

#include <sstream>

using namespace std;

string numPlanets[8];

void initializePlanets() {
    
    numPlanets[0] = "Mercury";
    numPlanets[1] = "Venus";
    numPlanets[2] = "Earth";
    numPlanets[3] = "Mars";
    numPlanets[4] = "Jupiter";
    numPlanets[5] = "Saturn";
    numPlanets[6] = "Uranus";
    numPlanets[7] = "Neptune";

}

void insertion_sort (string numPlanets[], int length){
    int charPlanets[8];
    charPlanets[0] = numPlanets[0].at(0);
    charPlanets[1] = numPlanets[1].at(0);
    charPlanets[2] = numPlanets[2].at(0);
    charPlanets[3] = numPlanets[3].at(0);
    charPlanets[4] = numPlanets[4].at(0);
    charPlanets[5] = numPlanets[5].at(0);
    charPlanets[6] = numPlanets[6].at(0);
    charPlanets[7] = numPlanets[7].at(0);
    cout << charPlanets[7] << endl;

    int current;
    string temp;
    for (int i = 1; i < length; i++){
        current = i;
        while ((current > 0) && ( static_cast<int>(numPlanets[current].at(0)) < static_cast<int>(numPlanets[current-1].at(0)))){
            temp = numPlanets[current];
            numPlanets[current] = numPlanets[current-1];
            numPlanets[current-1] = temp;
            current--;
        }
    }
    
    
}

int median(double items[], int numItem) {
    
    double median;
    
    if ((numItem%2) == 1) {
        median = items[numItem/2];
    } else {
        median = ((double)(items[(numItem/2)] + items[(numItem/2) -1]))/2.0;
    }
    //cout << "NumItem: " << numItem <<  " EvenOdd: " << (numItem/2) << " Nums: " << items[numItem/2] << ":" << items[(numItem/2)-1] << ":"<< items[3] << ":" << items[4]<< endl;
    cout  << "Median: " << median<<endl;
    return median;
}


void insertion(double arr[], int length) {
    
    int current, temp;
    for (int i = 1; i < length; i++){
        current = i;
        while ((current > 0) && (arr[current] > arr[current-1])){
            temp = arr[current];
            arr[current] = arr[current-1];
            arr[current-1] = temp;
            current--;
        }
    }
}


int main(int argc, const char * argv[]) {
    srand(static_cast<uint16_t>(time(0)));
    initializePlanets();
    insertion_sort(numPlanets, 8);
    cout << "Sorted Planets: " ;
    for (int x = 0; x<sizeof(numPlanets)/sizeof(*numPlanets); x++) {
        cout << numPlanets[x] << " ";
    }
    
    cout << endl;
    double numElements[7];
    for (int x = 0; x< sizeof(numElements)/sizeof(numElements[0]); x++) {
        numElements[x] =  rand()%15;
    }

    insertion(numElements, 7);
    for (int x = 0; x< sizeof(numElements)/sizeof(numElements[0]); x++) {
        cout << numElements[x] << " ";
    }
    
    cout << endl;
    median(numElements, 7);
    cout << endl;
    
    
    return 0;
}
