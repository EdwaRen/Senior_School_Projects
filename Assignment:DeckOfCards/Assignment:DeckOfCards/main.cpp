//
//  main.cpp
//  Assignment:DeckOfCards
//
//  Created by - on 2017/02/14.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include "Cards.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Card a;
    a = Card(4, 2);
    cout << "hello" << endl;
    cout << a.toString() << endl;
    
    DeckOfCards b;
    
    b.DeckConstruct(52);
    cout << "hello1" << endl;

    cout << b.DeckCardString(52)<< endl;

    
    b.shuffle(52);
    
    
    
    cout << "hello2" << endl;

    cout << b.DeckCardString(52);
    
    cout << "nextCards" << endl;

    Card c;
    cout << b.NextCard().toString() << endl;
    cout << b.NextCard().toString() << endl;
    cout << b.NextCard().toString() << endl;
    
    b.DeckDestruct();

    //Poker time
    cout << "\nPOKER ASSIGNMENT "<< endl;
    cout << "-------------------------"<< endl;
    cout << "RULEBOARD: There is no penalty for folding" << endl;
    cout << "RULEBOARD: Enter a value < 0 or more than your total money to end the game" << endl;
    cout << "RULEBOARD: All five cards are already dealt, just bet on the final match!" << endl;
    cout << "RULEBOARD: For ease of use (and easy testing) all the cards are displayed, including the dealer's" << endl;
    cout << "RULEBOARD: For two pairs and flush, high card only applies once. Ex: A flush with 2,3,4,5,K will tie a flush with 9,10,J,Q,K\n\n" << endl;






    cout << "Dealer: A little gambling is fun when you're with me" << endl;
    Dealer d;
    bool endGame = false;
    
    //cout << d.DealCards() << endl;
    //d.FindWinner();
    
    while (endGame == false) {
        cout << d.DealCards() << endl;
        d.myDeckObj.shuffle(52);
        
        d.BetMoney();
        if (d.getEndTriggered()  == true) {
            break;
        }
        if (d.getFold() == false) {
            d.FindWinner();
            d.Aftermath();
        } else {
            cout << "\nThere was a fold" << endl;
        }
        int m1 = d.getMoney1();
        int m2 = d.getMoney2();
        if (m1 <= 0) {
            cout << "You have been defeated" << endl;
            cout << "Dealer: Can't read my, can't read my, no one can read my POKER FACE" << endl;
            cout << "\nRestart? Y/N" << endl;
            char repeat;
            cin >> repeat;
            if (repeat == 'N') {
                d.ThisIsTheEnd();
                endGame = true;
            }
        } else if (m2 <= 0){
            cout << "\nCongratulations! You have won!" << endl;
            cout << "Dealer: You caught me bluffing" << endl;
            cout << "\nRestart? Y/N" << endl;
            char repeat;
            cin >> repeat;
            if (repeat == 'N') {
                d.ThisIsTheEnd();
                endGame = true;
            }
        } else {
            cout << "\nContinue? Y/N" << endl;
            char repeat;
            cin >> repeat;
            if (repeat == 'N') {
                d.ThisIsTheEnd();
                endGame = true;
            }
        }
        
    }
    
    return 0;
}
