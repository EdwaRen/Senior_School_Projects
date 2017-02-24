//
//  FindWinner.hpp
//  Poker
//
//  Created by - on 2016/10/29.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//  

#ifndef FindWinner_hpp
#define FindWinner_hpp



#include <stdio.h>

extern int numWinner;
extern int leftOvers;

bool checkFold(int playerInGame[]);
int checkStraight(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6]);
int checkFlush(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6]);
int pairs(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6], int highestUsedCard2[][6]);
int twoPairs(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6], int highestUsedCard2[][6]);
int checkHouse(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6], int highestUsedCard2[][6]);
int checkStraightFlush(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6]);
void checkHighCard(int playerCards[][3], int dealedcards[][8], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3], int winners[]);
void winnersPot(int winnersNew[], int playerCredits[], int totalRoundBets[]);






#endif /* FindWinner_hpp */
