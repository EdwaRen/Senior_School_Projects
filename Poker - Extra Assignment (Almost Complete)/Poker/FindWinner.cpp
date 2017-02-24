//
//  FindWinner.cpp
//  Poker
//
//  Created by - on 2016/10/29.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include "FindWinner.hpp"
#include <iostream>

using namespace std;

int numWinner = 0;
int leftOvers = 0;


void resetAllCards( int allCardCheck[]) {
    for (int x = 0; x<=8 ; x++ ) {
        allCardCheck[x] = -5;
    }
}
void createAllCard( int allCardCheck[], int dealedcards[][8], int playerCards[][3]) {
    
    for (int x = 1; x <= 7 ;x++) {
        allCardCheck[x] = dealedcards[x][0];
        if (x ==6) {
            allCardCheck[x] = playerCards[1][0];
        } else if (x ==7) {
            allCardCheck[x] = playerCards[2][0];
        }
        if (allCardCheck[x] == 0) {
            allCardCheck[8] = 13;
        }
        
    }
}
void createAllCardPairs( int allCardCheck[], int dealedcards[][8], int playerCards[][3]) {
    
    for (int x = 1; x <= 7 ;x++) {
        allCardCheck[x] = dealedcards[x][0];
        if (x ==6) {
            allCardCheck[x] = playerCards[1][0];
        } else if (x ==7) {
            allCardCheck[x] = playerCards[2][0];
        }
        if (allCardCheck[x] == 0) {
            allCardCheck[x] = 13;
        }
    }
}

void orderCardsAscending (int allCardCheck[]) {
    int temp;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(allCardCheck[j] > allCardCheck[i])
            {
                temp = allCardCheck[i];
                allCardCheck[i] = allCardCheck[j];
                allCardCheck[j] = temp;
            }
        }
    }
    
}


bool checkFold(int playerInGame[]) {
    int foldCount = 0;
    int notFolded = 0;
    
    for (int x = 0; x<=4 ; ++x) {
        if ((playerInGame[x] == 0) || (playerInGame[x] == 2)) {
            foldCount++;
        } else if (playerInGame[x] == 1) {
            notFolded = x;
        }
    }
    if (foldCount == 4) {
        if (notFolded != 0) {
            cout << "Computer "<< notFolded << " has won the round. "<< endl;
            return true;
        } else {
            cout << "You have won the round" << endl;
            return true;
        }
    } else {
        return false;
    }
    
}



int checkStraight(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6]) {
    //Sort cards numerically
    int playerHandRank = 0;
    int allCardCheck[9];
    resetAllCards(allCardCheck);
    createAllCard(allCardCheck, dealedcards, playerCards);
    orderCardsAscending(allCardCheck);
    for (int x = 0; x<=8 ; x++) {
        //cout << allCardCheck[x] << " ";
    }
    //cout << "|" << endl;
    
    for (int x = 0; x <=4 ; x++ ) {
        if ((allCardCheck[x] + 1 == allCardCheck[x+1] )&&(allCardCheck[x+1] +1 == allCardCheck[x+2]) && (allCardCheck[x+2] +1 == allCardCheck[x+3]) && (allCardCheck[x+3] +1 == allCardCheck[x+4])) {
            playerHandRank = 4;
            cout << "Straight" << endl;
            highestUsedCard[4][playerNum] = allCardCheck[x+4];
        }
    }
    
    //cout << "|" << endl;
    return playerHandRank;
    
    
}

int checkStraightFlush(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6]) {
    //Sort cards numerically
    int playerHandRank = 0;
    int allCardCheck[9];
    int allCardCheckSuit[9];
    
    resetAllCards(allCardCheck);
    //First Allcardcheck for card face values
    createAllCard(allCardCheck, dealedcards, playerCards);
    orderCardsAscending(allCardCheck);

    //Second allCardCheck is for the suitvalue
    
    for (int x = 1; x <= 7 ;x++) {
        allCardCheckSuit[x] = dealedcards[0][x];
        if (x ==6) {
            allCardCheckSuit[x] = playerCards[0][1];
        } else if (x ==7) {
            allCardCheckSuit[x] = playerCards[0][2];
        }
        if (allCardCheckSuit[x] == 0) {
            allCardCheckSuit[x] = 13;
        }
    }
    
    int temp2;
    
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(allCardCheckSuit[j] > allCardCheckSuit[i])
            {
                temp2 = allCardCheckSuit[i];
                allCardCheckSuit[i] = allCardCheckSuit[j];
                allCardCheckSuit[j] = temp2;
            }
        }
    }
    
    for (int i = 1; i <= 8 ; i++) {
    }
    
    for (int x = 0; x <=4 ; x++ ) {
        if ((allCardCheck[x] + 1 == allCardCheck[x+1] )&&(allCardCheck[x+1] +1 == allCardCheck[x+2]) && (allCardCheck[x+2] +1 == allCardCheck[x+3]) && (allCardCheck[x+3] +1 == allCardCheck[x+4])) {
            
            int i = x;
            
                if ((allCardCheckSuit[i]  == allCardCheckSuit[i+1] )&&(allCardCheckSuit[i+1] == allCardCheckSuit[i+2]) && (allCardCheckSuit[i+2] == allCardCheckSuit[i+3]) && (allCardCheckSuit[i+3] == allCardCheckSuit[i+4])) {
                    playerHandRank = 8;
                    cout << "Flush and Straight" << endl;
                    highestUsedCard[8][playerNum] = allCardCheck[x+4];
                }
            
        }
    }
    return playerHandRank;
}

int checkFlush(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6]) {
    int playerHandRank = 0;
    int allCardCheck[9];
    resetAllCards(allCardCheck);

    for (int x = 1; x <= 7 ;x++) {
        allCardCheck[x] = dealedcards[0][x];
        if (x ==6) {
            allCardCheck[x] = playerCards[0][1];
        } else if (x ==7) {
            allCardCheck[x] = playerCards[0][2];
        }
        if (allCardCheck[x] == 0) {
            allCardCheck[x] = 13;
        }
    }
    
    int temp;
    
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(allCardCheck[j] > allCardCheck[i])
            {
                temp = allCardCheck[i];
                allCardCheck[i] = allCardCheck[j];
                allCardCheck[j] = temp;
            }
        }
    }
    
    /*
    allCardCheck[2] = 1;
    allCardCheck[3] = 1;
    allCardCheck[4] = 1;
    allCardCheck[5] = 1;
    allCardCheck[6] = 1;
    */
    for (int x = 0; x <=4 ; x++ ) {
        if ((allCardCheck[x]  == allCardCheck[x+1] )&&(allCardCheck[x+1] == allCardCheck[x+2]) && (allCardCheck[x+2] == allCardCheck[x+3]) && (allCardCheck[x+3] == allCardCheck[x+4])) {
            playerHandRank = 5;
            cout << "Flush" << endl;
            if (playerCards[1][0] > playerCards[2][0]) {
                highestUsedCard[5][playerNum] = playerCards[1][0];
            } else {
                highestUsedCard[5][playerNum] = playerCards[2][0];
            }
        }
        
    }
    
    return playerHandRank;
    
}

int checkHouse(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6], int highestUsedCard2[][6]) {
    int playerHandRank = 0;
    int allCardCheck[9];
    resetAllCards(allCardCheck);
    createAllCard(allCardCheck, dealedcards, playerCards);
    orderCardsAscending(allCardCheck);
    
    for (int x = 1; x<=6;x++) {
        
        if ((allCardCheck[x] == allCardCheck[x+1]) && (allCardCheck[x+1]== allCardCheck[x+2]) && (allCardCheck[x] != -5)) {
            
            for (int i = 1; i <= 7 ; i++) {
                if ((allCardCheck[i] != allCardCheck[x] )  && (allCardCheck[i] != -5)) {
                    if (allCardCheck[i] == allCardCheck[i+1]) {
                        cout << "Full House!" << endl;
                        for (int y = 0; y<=8; y++) {
                            //cout << allCardCheck[y]<< endl;
                        }
                        playerHandRank = 6;
                        highestUsedCard[6][playerNum] = allCardCheck[x];
                        highestUsedCard2[6][playerNum] = allCardCheck[i];
                    }
                }
            }
            
        }
        
    }
    
    return playerHandRank;

}

int twoPairs(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6], int highestUsedCard2[][6]) {
    
    int playerHandRank = 0;
    int allCardCheck[9];
    
    resetAllCards(allCardCheck);
    createAllCardPairs(allCardCheck, dealedcards, playerCards);
    orderCardsAscending(allCardCheck);
    
    for (int x = 1; x<=7;x++) {
        
        if ((allCardCheck[x] == allCardCheck[x+1]) && (allCardCheck[x] != -5)) {
            
            for (int i = 1; i <= 7 ; i++) {
                if ((allCardCheck[i] != allCardCheck[x] )  && (allCardCheck[i] != -5) && (allCardCheck[x] != -5)) {
                    if ((allCardCheck[i] == allCardCheck[i+1]) && (allCardCheck[i] != -5)) {
                        playerHandRank = 2;
                        cout << "Two Pairs!" << endl;
                        if (allCardCheck[x] > allCardCheck[i]) {
                            highestUsedCard[2][playerNum] = allCardCheck[x];
                            highestUsedCard2[2][playerNum] = allCardCheck[i];
                        } else {
                            highestUsedCard[2][playerNum] = allCardCheck[i];
                            highestUsedCard2[2][playerNum] = allCardCheck[x];

                        }
                    }
                }
            }
            
        }
        //cout << allCardCheck[x] << endl;
        
    }
    //cout << allCardCheck[7] << endl;

    return playerHandRank;
    
}

int pairs(int playerCards[][3], int dealedcards[][8], int playerNum, int highestUsedCard[][6], int highestUsedCard2[][6]) {
    int playerHandRank = 0;
    int allCardCheck[9];
    resetAllCards(allCardCheck);
    createAllCardPairs(allCardCheck, dealedcards, playerCards);
    orderCardsAscending(allCardCheck);

    
    for (int x = 1; x<=7;x++) {
        
        if ((allCardCheck[x] == allCardCheck[x+1]) && (allCardCheck[x+1] == allCardCheck[x+2]) && (allCardCheck[x+2] == allCardCheck[x+3])  && (x!=6) && (x!=7) && (allCardCheck[x] !=-5)) {
            cout << "Four in a Row" << endl;
            if (7 > playerHandRank) {
                playerHandRank = 7;
                highestUsedCard[7][playerNum] = allCardCheck[x];
                if (playerCards[1][0] >= playerCards[2][0]) {
                    highestUsedCard2[7][playerNum] = playerCards[1][0];
                } else {
                    highestUsedCard2[7][playerNum] = playerCards[2][0];
                }
            }
            
        } else if ((allCardCheck[x] == allCardCheck[x+1]) && (allCardCheck[x+1] == allCardCheck[x+2])  && (x!=7) && (allCardCheck[x] !=-5)) {
            cout << "Three in a Row" << endl;
         

            if (3>playerHandRank) {
                playerHandRank = 3;
                highestUsedCard[3][playerNum] = allCardCheck[x];
                if (playerCards[1][0] >= playerCards[2][0]) {
                    highestUsedCard2[3][playerNum] = playerCards[1][0];
                } else {
                    highestUsedCard2[3][playerNum] = playerCards[2][0];
                }
            }
        } else if ((allCardCheck[x] == allCardCheck[x+1]) && (allCardCheck[x] != -5) ) {
            cout << "Pair" << endl;
            for (int y = 0; y<=8; y++) {
            }
            
            if (1>playerHandRank) {
                playerHandRank = 1;
                highestUsedCard[1][playerNum] = allCardCheck[x];
                if (playerCards[1][0] >= playerCards[2][0]) {
                    highestUsedCard2[1][playerNum] = playerCards[1][0];
                } else {
                    highestUsedCard2[1][playerNum] = playerCards[2][0];
                }
            }
        }
    }
    return playerHandRank;
}

void checkHighCard(int playerCards[][3], int dealedcards[][8], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3], int winnersNew[]) {
    
    int playerWinNum = 0;
    int array[] = {playerCards[1][0],playerCards[2][0],comp1Cards[1][0],comp1Cards[2][0],comp2Cards[1][0],comp2Cards[2][0],comp3Cards[1][0],comp3Cards[2][0],comp4Cards[1][0],comp4Cards[2][0]};
    int temp = 0;
    
    for(int i=0;i<10;i++)
    {
        if (array[i] == 0) {
            array[i] = 13;
        }
        if(array[i]>temp) {
            temp=array[i];
            
            if ((i==0) || (i == 1)) {
                playerWinNum = 0;
            } else if ((i==2) || (i == 3)) {
                playerWinNum = 1;
            } else if ((i==4) || (i == 5)) {
                playerWinNum = 2;
            } else if ((i==6) || (i == 7)) {
                playerWinNum = 3;
            } else if ((i==8) || (i == 9)) {
                playerWinNum = 4;
            }
            
        }
    }
    
    winnersNew[0] = playerWinNum;
    int count = 1;
    for(int i=0;i<10;i++)
    {
        if (array[i] == 0) {
            array[i] = 13;
        }
        if((array[i]>=temp) && (i/2 != winnersNew[0])) {
            winnersNew[count] = i/2;
            count ++;
            
        }
    }
    
    
    
    
  
    
}

void winnersPot(int winnersNew[], int playerCredits[], int totalRoundBets[]) {

    int moneyPerEach;
    int numWinners = 0;
    
    for (int x = 0;x<=4;x++) {
        if ((winnersNew[x] >= 0 ) && (winnersNew[x] <= 5)) {
            numWinners++;
        }

    }
    
    moneyPerEach = totalRoundBets[5] / numWinners;
    
    for (int x = 0;x<=4;x++) {
        if ((winnersNew[x] >= 0 ) && (winnersNew[x] <= 5)) {
            playerCredits[winnersNew[x]] += moneyPerEach;
        }
    }
    
    leftOvers = totalRoundBets[5] - (moneyPerEach * numWinners);
    //cout << "LeftOvers: " << leftOvers << endl;
    
}


