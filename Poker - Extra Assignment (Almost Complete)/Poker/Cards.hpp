//
//  Cards.hpp
//  Poker
//
//  Created by - on 2016/10/29.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#ifndef Cards_hpp
#define Cards_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Cards.hpp"
#include <string>
using namespace std;

void asciiCard(int numFaceValue, int suitvalue, string cardLine[]);
void printTable(int playerCards[][3], int dealedCards[][8], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3], int playerCredits[], int playerBets[], int turnNum, int totalRoundBets[]);

extern string facesStr[15];


#endif /* Cards_hpp */
