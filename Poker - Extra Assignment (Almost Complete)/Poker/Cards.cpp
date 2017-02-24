//
//  Cards.cpp
//  Poker
//
//  Created by - on 2016/10/29.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include "Cards.hpp"
#include <string>
using namespace std;

string facesStr[15] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "X", "J", "Q", "K"};




void asciiCard(int numFaceValue, int suitvalue, string cardLine[])
{
    
    if ((numFaceValue != -5) && (suitvalue!= -5)) {
        string facevalue = facesStr[numFaceValue];
        
        
        char32_t heart;
        string line1;
        //line1 = &"Sad" [ facevalue] + "dsa";
        cardLine[0] += "_____  ";
        cardLine[1] += "|" + facevalue + "   | ";
        cardLine[5] += "`----` ";
        
        if (suitvalue == 3) {
            cardLine[2] += "|(\\/)| ";
            cardLine[3] += "| \\/ | ";
            cardLine[4] += "|   " + facevalue + "| ";
        } else if (suitvalue == 0) {
            //spades
            cardLine[2] += "| /\\ | ";
            cardLine[3] += "|(__)| ";
            cardLine[4] += "| /\\" + facevalue + "| ";
        } else if (suitvalue == 1) {
            //spades
            cardLine[2] += "| /\\ | ";
            cardLine[3] += "| \\/ | ";
            cardLine[4] += "|   " + facevalue + "| ";
        } else if (suitvalue == 2) {
            //spades
            cardLine[2] += "| &  | ";
            cardLine[3] += "|&|& | ";
            cardLine[4] += "| | " + facevalue + "| ";
        } else {
            
            cout << suitvalue << ": " << facevalue << "<-- THis thing (suitvalue) got messed up (suit:face) " << endl;
        }
    } else {
        cardLine[0] += "_____  ";
        cardLine[1] += "|----| ";
        cardLine[2] += "|----| ";
        cardLine[3] += "|FOLD| ";
        cardLine[4] += "|----| ";
        cardLine[5] += "`----` ";
    }
    
    
}

void asciiBlankCard(string cardLine[]) {
    
    cardLine[0] += "_____  ";
    cardLine[1] += "|\\--/| ";
    cardLine[2] += "|}\\/{| ";
    cardLine[3] += "|}/\\{| ";
    cardLine[4] += "|/--\\| ";
    cardLine[5] += "`----` ";
    
}

void asciiCardSeparation(string cardLine[]) {
    
    cardLine[0] += "    ";
    cardLine[1] += "    ";
    cardLine[2] += "    ";
    cardLine[3] += "    ";
    cardLine[4] += "    ";
    cardLine[5] += "    ";

}

void asciiMoneyBags(string cardLine[], int totalRoundBets[], int turnNum) {
    string totalMoney = to_string(totalRoundBets[5]);
    
    cardLine[0] += "  \\`\\/\\/\\/`/  ";
    cardLine[1] += "   )======(   ";
    cardLine[2] += " .'        '. ";
    cardLine[4] += "\\            /";
    cardLine[5] += " '----------' ";
     /*
      cardLine[0] += "  \\`\\/\\/\\/`/";
      cardLine[1] += "   )======(";
      cardLine[2] += " .'   $$   '.";
      cardLine[3] += "/            \
      cardLine[4] += "\\            /";
      cardLine[5] += " '----------'";
      */
    
    if (turnNum == 1) {
        cardLine[3] += "/    $       \\";
    } else if (turnNum == 2) {
        cardLine[3] += "/    $$      \\";
    } else if (turnNum == 3) {
        cardLine[3] += "/    $$$     \\";
    } else if (turnNum == 4) {
        cardLine[3] += "/    $$$$    \\";
    }

    
    
}

void asciiPlayerBets(string cardLine[], int totalRoundBets[]) {
    string totalMoney[6];

    for (int x = 0; x<=5 ; x++) {
        totalMoney[x] = to_string(totalRoundBets[x]);
    }
    cardLine[0] += "Your Total Bet: $" + totalMoney[0];
    cardLine[1] += "Computer 1's Total Bet: $" + totalMoney[1];
    cardLine[2] += "Computer 2's Total Bet: $" + totalMoney[2];
    cardLine[3] += "Computer 3's Total Bet: $" + totalMoney[3];
    cardLine[4] += "Computer 4's Total Bet: $" + totalMoney[4];
    cardLine[5] += "Pot: $" + totalMoney[5];




    
}

void intToString(int playerCredits[]) {
    
}

void printTable(int playerCards[][3], int dealedCards[][8], int comp1Cards[][3], int comp2Cards[][3], int comp3Cards[][3], int comp4Cards[][3], int playerCredits[], int playerBets[], int turnNum, int totalRoundBets[]) {
    string cardLine[6];
    string cardLine2[6];
    string cardLine3[6];
    
    for (int x = 0; x<=5 ; x++) {
        cardLine[x] = "";
        cardLine2[x] = "";
        cardLine3[x] = "";

    }
    
    string spaces = "       ";
    //Two blank cards for every opponent
    cout << "\nComputer 1:" << spaces << "Computer 2:" << spaces << "Computer 3:" << spaces << "Computer 4:" << endl;
    /*
    for (int x = 1; x<=4; x++) {
        asciiBlankCard(cardLine);
        asciiBlankCard(cardLine);
        asciiCardSeparation(cardLine);
    }
    */
    asciiCard(comp1Cards[1][0], comp1Cards[0][1], cardLine);
    asciiCard(comp1Cards[2][0], comp1Cards[0][2], cardLine);
    asciiCardSeparation(cardLine);

    asciiCard(comp2Cards[1][0], comp2Cards[0][1], cardLine);
    asciiCard(comp2Cards[2][0], comp2Cards[0][2], cardLine);
    asciiCardSeparation(cardLine);

    asciiCard(comp3Cards[1][0], comp3Cards[0][1], cardLine);
    asciiCard(comp3Cards[2][0], comp3Cards[0][2], cardLine);
    asciiCardSeparation(cardLine);

    asciiCard(comp4Cards[1][0], comp4Cards[0][1], cardLine);
    asciiCard(comp4Cards[2][0], comp4Cards[0][2], cardLine);


    
    
    for (int x = 0; x<=5 ; x++) {
        cout << cardLine[x] << endl;
    }
    
    string playerCredString[5];
    for (int x = 0; x<=4; x++) {
        playerCredString[x] += "Chips: $";
        playerCredString[x] += to_string(playerCredits[x]);
    }
    
    printf("%-18s%-18s%-18s%-18s\n", playerCredString[1].c_str(), playerCredString[2].c_str(), playerCredString[3].c_str(), playerCredString[4].c_str());

    
    
    //Transition phrases
    cout << "\n\nDealed Cards"  << endl;
    
    
    //5 blank cards for the undealed cards
        if (turnNum == 1) {
            asciiBlankCard(cardLine2);
            asciiBlankCard(cardLine2);
            asciiBlankCard(cardLine2);
            asciiBlankCard(cardLine2);
            asciiBlankCard(cardLine2);
        } else if (turnNum ==2 ) {
            asciiCard(dealedCards[1][0], dealedCards[0][1], cardLine2);
            asciiCard(dealedCards[2][0], dealedCards[0][2], cardLine2);
            asciiCard(dealedCards[3][0], dealedCards[0][3], cardLine2);
            asciiBlankCard(cardLine2);
            asciiBlankCard(cardLine2);
        } else if (turnNum ==3 ) {
            asciiCard(dealedCards[1][0], dealedCards[0][1], cardLine2);
            asciiCard(dealedCards[2][0], dealedCards[0][2], cardLine2);
            asciiCard(dealedCards[3][0], dealedCards[0][3], cardLine2);
            asciiCard(dealedCards[4][0], dealedCards[0][4], cardLine2);
            asciiBlankCard(cardLine2);
        } else if (turnNum ==4 ) {
            asciiCard(dealedCards[1][0], dealedCards[0][1], cardLine2);
            asciiCard(dealedCards[2][0], dealedCards[0][2], cardLine2);
            asciiCard(dealedCards[3][0], dealedCards[0][3], cardLine2);
            asciiCard(dealedCards[4][0], dealedCards[0][4], cardLine2);
            asciiCard(dealedCards[5][0], dealedCards[0][5], cardLine2);
        }
    
    asciiCardSeparation(cardLine2);
    asciiCardSeparation(cardLine2);
    asciiCardSeparation(cardLine2);
    asciiMoneyBags(cardLine2, totalRoundBets, turnNum);
    asciiCardSeparation(cardLine2);
    asciiPlayerBets(cardLine2, totalRoundBets);    
    
    for (int x = 0; x<=5 ; x++) {
        cout << cardLine2[x] << endl;
    }
    

    
    //Your two dealt cards
    cout << "\n\nYour Cards" << endl;
    asciiCard(playerCards[1][0], playerCards[0][1], cardLine3);
    asciiCard(playerCards[2][0], playerCards[0][2], cardLine3);

    for (int x = 0; x<=5 ; x++) {
        cout << cardLine3[x] << endl;
    }
    printf("%-18s\n", playerCredString[0].c_str());
    

}

