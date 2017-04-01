//
//  main.cpp
//  CCO_Segments
//
//  Created by - on 2017/02/07.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int nLine;
    
    cin >> nLine;
    
    int array1[100000];
    //array1 = new int[nLine];
    
    int array2[100000];
    //array2 = new int[nLine];
    
    int lastPoint = 1;
    int totalDistance = 0;
    
    for (int x = 0 ; x< nLine ; x++) {
        cin>> array1[x];
        cin>> array2[x];
       
    }
    
    for (int x = 0 ; x< nLine ; x++) {
        
        if ((array1[x] < lastPoint) && (array2[x] > lastPoint) && (x!= nLine-1)) {
            //This is the scenario where the level drop is in the middle of a line segment
            
            int node[5];
            for (int i = array1[x+1] ; i<array2[x+1]; i++) {
                //For the next line segment, which node is the most efficient to land on?

                int distanceLeft = abs(i-array1[x+1]);
                int distanceRight = abs(array2[x+1] - i);
                if (distanceLeft <= distanceRight) {
                    node[i] = distanceLeft;
                } else {
                    node[i] = distanceRight;
                }
            }
            //Compares whether it is better to go left or right when given the choice
            int rightSegmentLength = array2[x] - lastPoint;
            int leftSegmentLength = lastPoint - array1[x];
            //int segmentDifference = rightSegmentLength - leftSegmentLength;
            
            if (leftSegmentLength + node[array1[x]] >= rightSegmentLength + node[array2[x]]) {
                totalDistance += lastPoint - array1[x];
                totalDistance += array2[x] - array1[x]+1;
                //totalDistance += array2[x] - array2[x+1] + 1;
                lastPoint = array2[x];

            } else {
                totalDistance += array2[x] - lastPoint;
                totalDistance += array2[x] - array1[x]+1;

                lastPoint = array1[x];

            }
            
            //cout << "Counting both: ";

        } else if (array1[x] >= lastPoint) {
            //Must go right
            totalDistance += array2[x] - lastPoint +1;
            lastPoint = array2[x];
           // cout << "Counting right: ";
        } else if (array2[x] <= lastPoint) {
            //Must go left
            totalDistance += lastPoint - array1[x] + 1;
            lastPoint = array1[x];
            //cout << "Counting left: ";

        }
        
        if (x + 1 == nLine) {
            totalDistance += array2[x] - lastPoint;
            lastPoint = array2[x];
        }
        
        //cout << "The total distance in round " << x << " is: "<<totalDistance << endl;

        
    }
    
    cout <<totalDistance << endl;
    
    //delete[] array1;
    //delete[] array2;
    
   
    return 0;
}
