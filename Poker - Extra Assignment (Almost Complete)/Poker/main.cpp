//
//  main.cpp
//  Poker
//
//  Created by - on 2016/10/28.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>	// library used to re-seed the rand() function
#include <iomanip>
#include "Cards.hpp"
#include "FindWinner.hpp"
#include <string>
#include <sstream>
#include <stdio.h>
#include <math.h>



char static suits[4][10] = {"Spades", "Diamonds", "Clubs",
    "Hearts"};
void killPlayers(int playerDead[], int playerInGame[], int playerCredits[], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3]);

char static faces[14][10] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "X", "J", "Q", "K"};
//string static facesStr[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "X", "J", "Q", "K"};

using namespace std;

// FUNCTION PROTOTYPES:

// function protoype that prints the contents of the array
void Print2DArray(int a[][14], int rows, int cols);

// function prototype that initializes all the elements of
// the array to zero.
void Init2DArray(int a[][14], int rows, int cols);

// FUNCTION: Print2DArray

void resetBets(int playerBets[], int totalRoundBets[], int leftOvers) {
    
    
    for (int x = 0; x <=4;++x) {
        totalRoundBets[x] += playerBets[x];
        if (playerBets[x] == -5) {
            totalRoundBets[x] += 5;
        }
        playerBets[x] = -5;
    }
    totalRoundBets[5] = totalRoundBets[0] + totalRoundBets[1] + totalRoundBets[2] + totalRoundBets[3] + totalRoundBets[4] + 250 + leftOvers;
    //cout << "Pot: " << totalRoundBets[5]<< endl;
   // cout << "LeftOvers: " << leftOvers << endl;
    
}

void printCards(string cardline[]) {
    for (int x = 0; x<=5 ; ++x) {
        cout << cardline[x] << endl;
       

    }
}


// FUNCTION: Init2DArray

void Init2DArray(int a[][14], int rows, int cols)
{
    for(int i=0; i < rows; i++){
        for(int k=0; k < cols; k++){
            a[i][k]=0;
        }
    }
    return;
    
} // end Init2DArray

int dealCards(int card_deck[][14], string name,  int playerCards[][3]) {
    int suitvalue;
    int facevalue;
    int numcards = 0;
    
    
    int usedCount=0;
    while (numcards < 2 ) {
        suitvalue = rand() % 4;
        facevalue = rand() % 12;
        
       
        
        if(card_deck[suitvalue][facevalue]==1){
            numcards--;
            usedCount++;
            //cout << "Match detected" << suits[suitvalue] << faces[facevalue] << endl;
            if (usedCount > 40) {
                cout << "All cards used up" << endl;
                break;
            }
        } else if(card_deck[suitvalue][facevalue]!=1){
            //cout << name << " card is a " << faces[facevalue];
            //cout << " of " << suits[suitvalue] << endl;
            card_deck[suitvalue][facevalue]=1;
            usedCount = 0;
            playerCards[numcards+1][0] = facevalue;
            playerCards[0][numcards+1] = suitvalue;
        }
        numcards++;
    }

    return 0;
}



void givePot(int playerCredits[], int totalRoundBets[]) {
    
    int count = 0;
    
    for (int x = 0; x<=4 ; x++) {
        if (playerCredits>0) {
            playerCredits[x] += -50;
            count ++;
        }
        
    }
    
    totalRoundBets[5] = count*50 + leftOvers;
    //cout << "leftOvers 2: " << leftOvers << endl;

}

int largestBet(int playerBets[]) {
    int bigbet = playerBets[0];

    for (int x = 1; x<=4; x = x +1) {
        if (playerBets[x] > bigbet) {
            bigbet = playerBets[x];
        }
    }
    return bigbet;
}

void checkInGame ( int playerInGame[], int playerBets[], int playerCredits[], int playerCards[][3], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3]) {
    
    
    
    for (int x = 0; x <=4 ; ++x) {
        if (playerCredits[x] <= 0) {
            playerInGame[x] = 0;
        }
        if ((playerBets[x] >= largestBet(playerBets)) && playerInGame[x] != 2){
            playerInGame[x] = 1 ;
            cout << "Computer " << x << " (" << playerCredits[x] << ") has called" << endl;
        } else {
            playerInGame[x] = 0;
            if (playerBets[x] == -5) {
                playerCredits[x] = playerCredits[x] - 5;
            }
            if (x != 0) {
                cout << "Computer " << x << " (" << playerCredits[x] << ") has folded" << endl;
            } else {
                cout << "You have folded " << endl;
            }
        }
        //cout << x << " game status " << playerInGame[x]<< endl;
    }
    
    
    if (playerInGame[0] != 1) {
        playerCards[1][0] = -5;
        playerCards[2][0] = -5;
        playerCards[0][1] = -5;
        playerCards[0][2] = -5;
        
    }
    if (playerInGame[1] != 1) {
        comp1Cards[1][0] = -5;
        comp1Cards[2][0] = -5;
        comp1Cards[0][1] = -5;
        comp1Cards[0][2] = -5;
    }
    if (playerInGame[2] != 1) {
        comp2Cards[1][0] = -5;
        comp2Cards[2][0] = -5;
        comp2Cards[0][1] = -5;
        comp2Cards[0][2] = -5;
    }
    if (playerInGame[3] != 1) {
        comp3Cards[1][0] = -5;
        comp3Cards[2][0] = -5;
        comp3Cards[0][1] = -5;
        comp3Cards[0][2] = -5;
    }
    if (playerInGame[4] != 1) {
        comp4Cards[1][0] = -5;
        comp4Cards[2][0] = -5;
        comp4Cards[0][1] = -5;
        comp4Cards[0][2] = -5;
    }
            
            
}

int compBet(int* playerCredit, int playerCardVal1, int playerCardVal2, int playerBets[]) {
    int bet;
    //cout << largestBet(playerBets) << endl;
    if ((largestBet(playerBets) > 0) && (largestBet(playerBets) <= 200)) {
        //cout << "hi" << endl;
        if (rand()%100 < 90) {
            bet = largestBet(playerBets);
        } else {
            bet = -5;
        }
    } else if ((largestBet(playerBets) > 200)) {
        if (((playerCardVal2>10) && (playerCardVal1>10)) && rand()%100 < 90) {
            bet = largestBet(playerBets);
        } else {
            bet = -5;
        }
    } else {
        if ((playerCardVal1 >= 10) && (playerCardVal2 >= 10)) {
            bet = rand() % 50 + 100;
        } else {
            bet = rand() % 50;
        }
        if (*playerCredit > bet) {
            //*playerCredit = *playerCredit - bet;
            return bet;
        } else {
            *playerCredit = 0;
            bet = *playerCredit;
            return *playerCredit;
        }
    }
    
    
    
    return bet;
}

bool is_number(const std::string& s)
{
    return( strspn( s.c_str(), "-.0123456789" ) == s.size() );
}

void betCredit(int playerCredits[], int playerBets[], int* betStartPlayerPoint, int cards1[][3], int cards2[][3], int cards3[][3], int cards4[][3], int playerinGame[], int playerDead[]) {
    
    
    killPlayers(playerDead, playerinGame, playerCredits, cards1, cards2, cards3, cards4);
    
    
    if (*betStartPlayerPoint == 0) {

        bool endbet = false;
        
        if (playerinGame[0] == 1) {
            
            bool reBet = false;
            string playerEntry = "a";
            while (reBet == false) {
                
                cout << "\nIt is currently your turn to bet. Enter a negative number to fold, otherwise please bet a value from 0 to " << playerCredits[0]<< endl;
                
                
                cin >> playerEntry;
                
                if (is_number(playerEntry)) {
                    //cout << playerEntry << endl;
                    //cout << playerBets[0] << endl;
                    playerBets[0] = stoi(playerEntry);
                    if (playerBets[0] <= playerCredits[0]) {
                        reBet = true;
                    } else {
                        cout << "You have not entered a valid number. Please try again."<< endl;
                        playerBets[0] = -5;
                    }
                } else {
                    cout << "You have not entered a valid number. Please try again."<< endl;
                    
                }
                                
            }
        }
        
        int countLoop =0;
        while (endbet == false) {
            /*
            int* player1Cred = &playerCredits[1];
            int* player2Cred = &playerCredits[2];
            int* player3Cred = &playerCredits[3];
            int* player4Cred = &playerCredits[4];
            
            playerBets[1] = compBet(player1Cred, cards1[1][0], cards1[2][0], playerBets);
            playerBets[2] = compBet(player2Cred, cards2[1][0], cards2[2][0], playerBets);
            playerBets[3] = compBet(player3Cred, cards3[1][0], cards3[2][0], playerBets);
            playerBets[4] = compBet(player4Cred, cards4[1][0], cards4[2][0], playerBets);
            */
            for (int x = 0; x <=4; ++x) {
                if ((playerBets >= 0) && (x!=0) && (playerinGame[x] == 1 && (playerinGame != 0))) {
                    int* player1Cred = &playerCredits[x];
                    int newcompBet;
                    if (x == 1) {
                         newcompBet = compBet(player1Cred, cards1[1][0], cards1[2][0], playerBets);
                    } else if (x == 2) {
                         newcompBet = compBet(player1Cred, cards2[1][0], cards2[2][0], playerBets);
                    } else if (x == 3) {
                        newcompBet = compBet(player1Cred, cards3[1][0], cards3[2][0], playerBets);
                    } else if (x == 4) {
                         newcompBet = compBet(player1Cred, cards4[1][0], cards4[2][0], playerBets);
                    }
                    
                    if (newcompBet < playerBets[x]) {
                        playerCredits[x] = playerCredits[x] - playerBets[x];
                    } else {
                        playerBets[x] = newcompBet;
                        playerCredits[x] = playerCredits[x] - playerBets[x];
                    }
                }
                if (playerBets[x] <0) {
                    playerinGame[x] = 2;
                }
            }
            
            //cout << "comp1-4 Bet" << playerBets[1] << " "<< playerBets[2] << " " << playerBets[3] << " " << playerBets[4] << endl;
            
            if (playerBets[0] < largestBet(playerBets) && (countLoop <1) && (playerinGame[0] ==1 )) {
                int bet2;
                cout << "You have betted " << playerBets[0] << ". The current highest bet is " << largestBet(playerBets) << ". Do you wish to call or raise? Enter how much you would like to add. If your total entry is below the current bet, you will fold" << endl;
                
                bool reBet = false;
                string playerEntry = "a";
                while (reBet == false) {
                    
                    cout << "You have betted " << playerBets[0] << ". The current highest bet is " << largestBet(playerBets) << ". Do you wish to call or raise? Enter how much you would like to add. If your total entry is below the current bet, you will fold" << endl;

                    cin >> playerEntry;
                    
                    if (is_number(playerEntry)) {
                        //cout << playerEntry << endl;
                        //cout << playerBets[0] << endl;
                        bet2 = stoi(playerEntry);
                        reBet = true;
                    } else {
                        cout << "You have not entered a valid number. Please try again."<< endl;
                        
                    }
                    
                }

                
                
                playerBets[0] = playerBets[0] + bet2;
            } else {
                endbet = true;
            }
            countLoop++;
        }
        playerCredits[0] = playerCredits[0] - playerBets[0];
        //playerCredits[1] = playerCredits[1] - playerBets[1];
        //playerCredits[2] = playerCredits[2] - playerBets[2];
        //playerCredits[3] = playerCredits[3] - playerBets[3];
        //playerCredits[4] = playerCredits[4] - playerBets[4];


    }
    
    //return 0;
}

int dealGameCards(int card_deck[][14], int dealedCards[][8], int NumCardstoDeal, int numcards) {
    
    int suitvalue;
    int facevalue;
    //int numcards = 0;
    
    while (numcards <  NumCardstoDeal ) {
        suitvalue = rand() % 4;
        facevalue = rand() % 13;
        
        
        
        if(card_deck[suitvalue][facevalue]==1){
        } else {
            dealedCards[numcards+1][0] = facevalue;
            dealedCards[0][numcards+1] = suitvalue;
            numcards++;
            card_deck[suitvalue][facevalue] = 1;
        }
        
    }
    
    return 0;
}

int findHighestArr(int array[], int arrayLength, bool placeHolderOrValue) {
    int temp = 0;
    
    
    for(int i=0;i<=arrayLength;i++)
    {
        if(array[i]>temp) {
            if (placeHolderOrValue == false ) {
                temp=array[i];
                //cout << "Array value and which: " << array[i] << " " << i << endl;
                //cout << "HIghest array atm: " << temp << endl;
            }
          
        }
        
        
    }
   
    
    //cout << "Find highest array" << temp << endl;
    return temp;
}

string rankToText(int highestRanks ) {
    string returnText = "s";
    
    if (highestRanks == 0) {
        returnText = " High Card ";
    } else if (highestRanks == 1) {
        returnText = " Pair ";
    } else if (highestRanks == 2) {
        returnText = " Two Pairs ";
    } else if (highestRanks == 3) {
        returnText = " Three In A Row ";
    } else if (highestRanks == 4) {
        returnText = " Straight ";
    } else if (highestRanks == 5) {
        returnText = " Flush ";
    } else if (highestRanks == 6) {
        returnText = " Full House ";
    } else if (highestRanks == 7) {
        returnText = " Four In A Row ";
    } else if (highestRanks == 8) {
        returnText = " Straight Flush ";
    } else {
        returnText = "Error - var highestRanks did not return a valid rank!";
    }
    
    return returnText;
    
}

void checkAll(int playerCards[][3], int dealedCards[][8], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3], int winners[], int highestRanks[], int highestUsedCard[][6], int winnersNew[], int playerInGame[], int highestUsedCard2[][6]) {
   /*
    int highestRanks[5];
    int highestUsedCard[5][6];
    for (int x = 0; x<=4 ; x++) {
        for (int y = 0; y<=5 ; y++) {
            highestUsedCard[x][y] = -5;
        }
    }
    */
    {
        int handCards[6];
        
        handCards[0] = checkStraight(playerCards, dealedCards, 0, highestUsedCard);
        handCards[1] = checkFlush(playerCards, dealedCards, 0, highestUsedCard);
        handCards[2] = checkHouse(playerCards, dealedCards, 0, highestUsedCard, highestUsedCard2);
        handCards[3] = twoPairs(playerCards, dealedCards, 0, highestUsedCard, highestUsedCard2);
        handCards[4] = pairs(playerCards, dealedCards, 0, highestUsedCard, highestUsedCard2);
        handCards[5] = checkStraightFlush(playerCards, dealedCards, 0, highestUsedCard);
        highestRanks[0] = findHighestArr(handCards, 5, false);
    }
    {
        int handCards[6];
        handCards[0] = checkStraight(comp1Cards, dealedCards, 1, highestUsedCard);
        handCards[1] = checkFlush(comp1Cards, dealedCards, 1, highestUsedCard);
        handCards[2] = checkHouse(comp1Cards, dealedCards, 1, highestUsedCard, highestUsedCard2);
        handCards[3] = twoPairs(comp1Cards, dealedCards, 1, highestUsedCard, highestUsedCard2);
        handCards[4] = pairs(comp1Cards, dealedCards, 1, highestUsedCard, highestUsedCard2);
        handCards[5] = checkStraightFlush(comp1Cards, dealedCards, 1, highestUsedCard);

        highestRanks[1] = findHighestArr(handCards, 5, false);

    }
    
    {
        int handCards[6];
        handCards[0] = checkStraight(comp2Cards, dealedCards, 2, highestUsedCard);
        handCards[1] = checkFlush(comp2Cards, dealedCards, 2, highestUsedCard);
        handCards[2] = checkHouse(comp2Cards, dealedCards, 2, highestUsedCard, highestUsedCard2);
        handCards[3] = twoPairs(comp2Cards, dealedCards, 2, highestUsedCard, highestUsedCard2);
        handCards[4] = pairs(comp2Cards, dealedCards, 2, highestUsedCard, highestUsedCard2);
        handCards[5] = checkStraightFlush(comp2Cards, dealedCards, 2, highestUsedCard);

        highestRanks[2] = findHighestArr(handCards, 5, false);
    }
    {
        int handCards[6];
        handCards[0] = checkStraight(comp3Cards, dealedCards, 3, highestUsedCard);
        handCards[1] = checkFlush(comp3Cards, dealedCards, 3, highestUsedCard);
        handCards[2] = checkHouse(comp3Cards, dealedCards, 3, highestUsedCard, highestUsedCard2);
        handCards[3] = twoPairs(comp3Cards, dealedCards, 3, highestUsedCard, highestUsedCard2);
        handCards[4] = pairs(comp3Cards, dealedCards, 3, highestUsedCard, highestUsedCard2);
        handCards[5] = checkStraightFlush(comp3Cards, dealedCards, 3, highestUsedCard);

        highestRanks[3] = findHighestArr(handCards, 5, false);
    }
    {
        int handCards4[6];
        handCards4[0] = checkStraight(comp4Cards, dealedCards, 4, highestUsedCard);
        handCards4[1] = checkFlush(comp4Cards, dealedCards, 4, highestUsedCard);
        handCards4[2] = checkHouse(comp4Cards, dealedCards, 4, highestUsedCard, highestUsedCard2);
        handCards4[3] = twoPairs(comp4Cards, dealedCards, 4, highestUsedCard, highestUsedCard2);
        handCards4[4] = pairs(comp4Cards, dealedCards, 4, highestUsedCard, highestUsedCard2);
        handCards4[5] = checkStraightFlush(comp4Cards, dealedCards, 4, highestUsedCard);

        highestRanks[4] = findHighestArr(handCards4, 5, false);
    }
    
    
    
    int temp0 = 0;
    double temp1 = 0;
    //nt count = 0;
    
    if ((highestRanks[0] == highestRanks[1]) && (highestRanks[2] == highestRanks[1]) && (highestRanks[2] == highestRanks[3]) && (highestRanks[3] == highestRanks[4]) && (highestRanks[3] == 0)) {
        checkHighCard(playerCards, dealedCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards, winnersNew);
        cout << "Checking High card" << endl;
    } else {
        
        for(int i=0;i<=4;i++)
        {
            if(highestRanks[i]>=temp0) {
                temp0=highestRanks[i];
                //cout << "HIghest rank" << highestRanks[i] << endl;
                //cout << "The winner" << winner << endl;
            }
        }
        for(int i=0;i<=4;i++)
        {
                if((highestUsedCard[highestRanks[i]][i] + highestUsedCard2[highestRanks[i]][i]/100.0 >=temp1) && (highestRanks[i] >= temp0)) {
                    temp1 = highestUsedCard[highestRanks[i]][i] + highestUsedCard2[highestRanks[i]][i]/100.0;
                    cout << "temp1: " << temp1 << " " << highestUsedCard2[highestRanks[i]][i] << " " << highestRanks[i] << " " << i <<endl;
                }
                if((highestUsedCard[highestRanks[i]][i]>=temp1) && (highestRanks[i] == temp0)) {
                    
                }
        
        }
        winnersNew[0] = -5;
        winnersNew[1] = -5;
        winnersNew[2] = -5;
        winnersNew[3] = -5;
        winnersNew[4] = -5;
        //highestUsedCard[highestRanks[0]][0] = 4;
/*
        cout << highestUsedCard[highestRanks[0]][0] << endl;
        cout << highestUsedCard[highestRanks[1]][1] << endl;

        cout << highestUsedCard[highestRanks[2]][2] << endl;
        cout << highestUsedCard[highestRanks[3]][3] << endl;
        cout << highestUsedCard[highestRanks[4]][4] << endl;

        cout << temp1 << endl;
        cout << temp0 << endl;
        cout << highestRanks[0] << endl;;
        cout << highestRanks[1] << endl;;

        cout << highestRanks[2] << endl;;
*/
        
        for(int i=0;i<=4;i++)
        {
            //for (int x = 0; x<=4 ; x++) {
                if(((highestUsedCard[highestRanks[i]][i] + highestUsedCard2[highestRanks[i]][i]/100.0 ) >=temp1) && (highestRanks[i] >= temp0)) {
                    //cout << "highest ranked card: " << highestUsedCard[highestRanks[i]][i] << " i " << highestRanks[i] << endl;
                    winnersNew[numWinner] = i;
                    numWinner++;
                    //cout << "winners " << winnersNew[0] << winnersNew[1] << winnersNew[2] << winnersNew[3] << winnersNew[4] << endl;
                }
           // }
        }
        
        cout << "Not Checking High Card" << endl;
    }
    string winText = "The winners of this round are:";
    for (int x = 0; x<=4 ; x++) {
        if ((winnersNew[x] == 0) || (winnersNew[x] == 1) || (winnersNew[x] == 2) || (winnersNew[x] == 3) || (winnersNew[x] == 4)) {
            if (playerInGame[winnersNew[x]] == 1) {
            winText += " player, ";
            winText += to_string(winnersNew[x]);
            }
        }
    }
    
    winText += ", with a";
    winText += rankToText(highestRanks[winnersNew[0]]);
    
    cout << winText << endl;
    //cout << "The winner of this round of poker is: Player " << winnersNew[0] << "! With a " << highestRanks[winnersNew[0]] << endl;
    //delete temp0;
    //delete temp1;
    //return 0;
}

bool checkGameEnd(int playerCredits[]) {
    int winner = 0;
    int outCount = 0;
    bool result = false;
    for (int x= 0; x<=3;x++) {
        if ((playerCredits[x] == playerCredits[x+1]) && (playerCredits[x] == 0)) {
            outCount++;
        }
        
    }
    if (outCount == 3) {
        result = true;
        for (int x = 0; x<=4;x++) {
            if (playerCredits[x] > 0) {
                winner = x;
                
            }
        }
        cout << "The game has ended and the winner is player "<< winner << endl;
    }

    return result;
    
}

void killPlayers(int playerDead[], int playerInGame[], int playerCredits[], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3]) {
    
    for (int x = 0; x<=4 ; x++) {
        
        if (playerCredits[x] <0) {
            playerDead[x] = true;
            cout <<"Zed's dead baby, Zed's dead" << endl;
        }
        
        if (playerDead[x] == true) {
            playerInGame[x] = 0;
            cout <<"Zed's also dead baby, Zed's also dead" << endl;
            
            if (x ==0) {
                
            } else if ( x==1) {
                comp1Cards[1][0] = -5;
                comp1Cards[2][0] = -5;
                comp1Cards[0][1] = -5;
                comp1Cards[0][2] = -5;
            } else if ( x==2) {
                comp2Cards[1][0] = -5;
                comp2Cards[2][0] = -5;
                comp2Cards[0][1] = -5;
                comp2Cards[0][2] = -5;
            } else if ( x==3) {
                comp3Cards[1][0] = -5;
                comp3Cards[2][0] = -5;
                comp3Cards[0][1] = -5;
                comp3Cards[0][2] = -5;
            } else if ( x==4) {
                comp4Cards[1][0] = -5;
                comp4Cards[2][0] = -5;
                comp4Cards[0][1] = -5;
                comp4Cards[0][2] = -5;
            }
        }
    }
}

int main()
{
    int playerDead[5] = {false, false, false, false, false};

    srand(static_cast<uint32_t>(time(0)));
    bool end = false;
    
    // array for the suits in the deck of cards:
    
    // array for the values in the deck of cards:
    
    int playerCredits[] = {2000, 1000, 1000, 1000, 1000};


    while (end == false) {
        int card_deck[4][14];		// This will be the master deck
        int playerCards[3][3];
        int comp1Cards[3][3];
        int comp2Cards[3][3];
        int comp3Cards[3][3];
        int comp4Cards[3][3];
        
        numWinner = 0;
        
        // initialize all elements to zero:
        Init2DArray(card_deck, 4, 14);
        dealCards(card_deck, "Your", playerCards);
        
        
        // Now the computer will be dealt a hand:
        dealCards(card_deck, "Computer 1's", comp1Cards);
        dealCards(card_deck, "Computer 2's", comp2Cards);
        dealCards(card_deck, "Computer 3's", comp3Cards);
        dealCards(card_deck, "Computer 4's", comp4Cards);
        int winnersNew[6];
        
        int betStartPlayer = 0;
        int* betStartPlayerPoint;
        betStartPlayerPoint = &betStartPlayer;
        int static playerBets[] = {0, 0, 0, 0, 0};
        int playerInGame[] = {1, 1, 1, 1, 1};
        int dealedCards[8][8];
        string cardLine[6];
        int winners[6];
        
        int highestRanks[5];
        int test[8][8];
        int highestUsedCard[9][6];
        int highestUsedCard2[9][6];
        int test2[8][8];
        int totalRoundBets[6];
        
        
        
        for (int x = 0; x<=7; x++) {
            dealedCards[x][0] = -5;
            dealedCards[0][x] = -5;
        }
        for (int x = 0; x<=4; x++) {
            totalRoundBets[x] = 0;
        }
        totalRoundBets[5] = leftOvers;

        killPlayers(playerDead, playerInGame, playerCredits, comp1Cards, comp2Cards, comp3Cards, comp4Cards);
        givePot(playerCredits, totalRoundBets);
        printTable(playerCards, dealedCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerCredits, playerBets,1, totalRoundBets);
        
        
        betCredit(playerCredits,playerBets, betStartPlayerPoint, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerInGame, playerDead);
        checkInGame(playerInGame, playerBets, playerCredits, playerCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards);
        resetBets(playerBets, totalRoundBets, leftOvers);
        
        checkFold(playerInGame);

        dealGameCards(card_deck, dealedCards, 3, 0);
        for (int x = 1; x<= 4; x++) {
            cout << dealedCards[x][0];
        }
        /*
        playerCards[1][0] = 9;
        playerCards[2][0] = 8;
        
        playerCards[0][1] = 1;
        playerCards[0][2] = 2;
        
        comp1Cards[1][0] = 2;
        comp1Cards[2][0] = 12;
        comp2Cards[1][0] = 0;
        comp2Cards[2][0] = 0;
        comp3Cards[1][0] = 10;
        comp3Cards[2][0] = 6;
        comp4Cards[1][0] = 7;
        comp4Cards[2][0] = 2;
        
        comp1Cards[0][1] = 3;
        comp1Cards[0][2] = 2;
        
        dealedCards[1][0] = 5;
        dealedCards[2][0] = 6;
        dealedCards[3][0] = 7;
        
        
        dealedCards[0][1] = 2;
        dealedCards[0][2] = 2;
        dealedCards[0][3] = 2;
         */
        
        
        printTable(playerCards, dealedCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerCredits, playerBets,2, totalRoundBets);
    
        
        //Second betting and fourth card
        betCredit(playerCredits,playerBets, betStartPlayerPoint, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerInGame, playerDead);
        checkInGame(playerInGame, playerBets, playerCredits, playerCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards);
        resetBets(playerBets, totalRoundBets, leftOvers);
        
        checkFold(playerInGame);

        dealGameCards(card_deck, dealedCards, 4, 3);
        for (int x = 1; x<= 4; x++) {
            cout << dealedCards[x][0];
        }
        
        
        
        printTable(playerCards, dealedCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerCredits, playerBets,3, totalRoundBets);
        
        winnersNew[0] = -5;
        winnersNew[1] = -5;
        winnersNew[2] = -5;
        winnersNew[3] = -5;
        winnersNew[4] = -5;
        winnersNew[5] = -5;
        
        
        

        //asciiCard(facesStr[dealedCards[4][0]], dealedCards[0][4], cardLine);
        //printCards(cardLine);

        
        //Third betting and fifth card reveal
        betCredit(playerCredits,playerBets, betStartPlayerPoint, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerInGame, playerDead);
        checkInGame(playerInGame, playerBets, playerCredits, playerCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards);
        resetBets(playerBets, totalRoundBets, leftOvers);
        checkFold(playerInGame);

        dealGameCards(card_deck, dealedCards, 5, 4);
       
        printTable(playerCards, dealedCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerCredits, playerBets,4, totalRoundBets);

        //asciiCard(facesStr[dealedCards[5][0]], dealedCards[0][5], cardLine);
        //printCards(cardLine);
        
        //Final bet
        betCredit(playerCredits,playerBets, betStartPlayerPoint, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerInGame, playerDead);
        checkInGame(playerInGame, playerBets, playerCredits, playerCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards);
        resetBets(playerBets, totalRoundBets, leftOvers);
        checkFold(playerInGame);
        
        for (int x = 0; x<=5; x++) {
            cout << totalRoundBets[x] << endl;
        }
        /*
         playerCards[1][0] = 10;
         playerCards[2][0] = 6;
         
         playerCards[0][1] = 1;
         playerCards[0][2] = 1;
         
         comp1Cards[1][0] = 2;
         comp1Cards[2][0] = 12;
         comp2Cards[1][0] = 0;
         comp2Cards[2][0] = 0;
         comp3Cards[1][0] = 10;
         comp3Cards[2][0] = 6;
         comp4Cards[1][0] = 7;
         comp4Cards[2][0] = 2;
         
         comp1Cards[0][1] = 3;
         comp1Cards[0][2] = 2;
         
         dealedCards[1][0] = 10;
         dealedCards[2][0] = 6;
         dealedCards[3][0] = 1;
         
         
         dealedCards[0][1] = 2;
         dealedCards[0][2] = 3;
         dealedCards[0][3] = 2;
        */
        
        printTable(playerCards, dealedCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards, playerCredits, playerBets,4, totalRoundBets);

        checkAll(playerCards, dealedCards, comp1Cards, comp2Cards, comp3Cards, comp4Cards, winners, highestRanks, highestUsedCard, winnersNew, playerInGame, highestUsedCard2);
        winnersPot(winnersNew, playerCredits, totalRoundBets);


        
        cout << "Round is over. Enter NEXT to continue to the next round!! " << endl;
        string next;
        cin >> next;
        
       
        
    }
    
    
    
    
    
    
    
    
    
    
}



















