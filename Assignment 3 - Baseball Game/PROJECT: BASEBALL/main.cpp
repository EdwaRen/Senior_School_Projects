//
//  main.cpp
//  PROJECT: BASEBALL
//
//  Created by - on 2016/10/11.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
//#include "stdafx.h"
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>
//#include <boost/lexical_cast.hpp>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "add.hpp"



int getGameMode(string x) {
    
    
    if (x == "MANUAL") {
        //cout<< "You have selected MANUAL game mode" << endl;
        cout<< "" << endl;
        return 1;
    } else if (x == "AUTO") {
        //cout << "You have selected AUTO game mode" << endl;
        cout<< "" << endl;
        return 2;
    } else {
        cout << "You have not typed an entry from the list above. Proceeding with AUTO mode with or without your consent"<< endl;
        cout<< "" << endl;
        return 2;
    }
}

string getTeamName(int x) {
    char teamNameT[256];
    //string teamName = "0";
    
    //string teamName = "dasfs";
    //string teamName2 = "adssf";

    cout << "Please enter the name for Team " << x <<  endl;
    cin.getline(teamNameT, 256);
    string teamName = string(teamNameT);


    cout << "Name received" << endl;
    return teamName;
}

int getBat(int team, int inning) {
    
    
    return 0;
}

int getRun(string input, int outs) {
    
    double result = 0;
    
    if (input == "Single") {
        result = 1;
    } else if (input=="Double") {
        result = 2;
    } else if (input == "Triple") {
        result = 3;
    } else if (input == "Home") {
        result = 4;
    } else if (input == "Out") {
        result = 0;
        //cout << "You still have " << 3-outs << " outs left" << endl;
    } else {
        cout << "You have not entered a valid run. Please enter EXACTLY one of the following: Single, Double, Triple, Home or Out" << endl;
    }
    
    return result;
}

int getRun2(string name) {
    
    cout << "Please enter EXACTLY the result of the hit (Single, Double, Triple, Home or Out) for team" << name <<  endl;
    char runValueStrT[256] = "0";
    int runInt = 0;
  
    cin.getline(runValueStrT, 256);
    string runValueStr = string(runValueStrT);

    runInt =  getRun(runValueStr, 0);
    return runInt;
}
int automicialIntelligence(string luck) {
    int output = 0;
    //srand(time(0));

    output = rand() % 5;
    cout << output << endl;

    if ((luck == "1" || luck == "2" || luck == "3") && output == 0) {
        output = rand() % 5;
        if ((luck == "2" || luck == "3") && output == 0) {
            output = rand() % 5;
            if (luck == "3" && output == 0) {
                output = rand() % 5;
            }
        }
        
    } else if (luck == "0") {
        if (output == 4 || output == 3) {
            output = 1;
        }
    }
    
    return output;
}

int play(string name, bool manual, string luck) {
    bool playerBase[] = {false, false, false, false, false, false, false, false, false};
    int inningScore = 0;
    int outCount = 0;
    int runInt = 0;

    do {
        if (manual == true) {
            runInt = getRun2(name);
        } else if (manual == false) {
            runInt = automicialIntelligence(luck);

        }
        
        int count = 0;
        int closestOpenPos = -1;
        if (runInt != 0) {
            if (playerBase[runInt] == true) {
                
                while (playerBase[runInt+count] == true) {
                    if (playerBase[runInt+count]==true) {
                        count++;
                    }
                    
                }
                
                playerBase[runInt+count] = true;
            } else {
                playerBase[runInt] = true;
            }
            
            for (int x = 0;x< runInt;x=x+1) {
                if (playerBase[x] == true) {
                    for( int x = 8; x --> 0; ) {
                        if (playerBase[x] == false && x > runInt+count) {
                            closestOpenPos = x;
                        }
                    }
                    if (closestOpenPos != -1) {
                        
                        playerBase[closestOpenPos] = true;
                    }
                    playerBase[x] = false;
                }
            }
        }
        
        for (int x= 4; x<= 8; x= x+1) {
            if (playerBase[x] == true) {
                cout << "Scored!" << endl;
                inningScore = inningScore + 1;
                playerBase[x] = false;
            }
        }
        
        if (runInt == 0) {
            outCount = outCount+1;
        }
        for (int x = 0; x <= 3; x = x + 1) {
            if (playerBase[x] == true) {
                cout << "Base " << x << " occupied" << endl;
            } else  {
                cout << "Base " << x << " clear" << endl;
            }
        }
        
        
        cout << "The current inning score is " << inningScore << ". You have " << outCount << " outs. "<<  endl;
        
        
    } while (outCount <3);
    
    return inningScore;
}

int winMessage(string team, int score1, int score2) {
    
    cout << "The game has handed! The championship of the 2016 CPU Tournament goes to.... Team: " << team << " who won with a final score of "<< score1 << " to " << score2<< endl;
    cout << "" << endl;
    cout << "   Thank you for your time spent testing out my program and have a wonderful day (after marking everything) !" << endl;
    return 0;
}




int main(int argc, const char * argv[]) {
    
    cout << addThis(46, 6, 13245) << "\n";
    srand( static_cast<unsigned int>(time(NULL)));

    char gameMode[256] = "";
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << "You have been unfortunately selected by the OCDSB to spend this hour marking programs. Here is project #3425: Baseball.Eddie v3.1.4 Beta Relese"<< endl;
    cout << "" << endl;
    cout << "Please select your baseball game mode" << endl;
    cout << "   Type MANUAL to manually enter the results of each inning (ie SINGLE, DOUBLE, HOME etc)" << endl;
    cout << "   Type AUTO to randomly generate results for each inning" << endl;
    
    cin.getline(gameMode, 256);

    
    if (getGameMode(gameMode) == 1) {
        
        switch ((2)) {
            case 1:
                cout << 1 << endl;
            case 2:
                cout << 1 << endl;
            case 3:
                cout << 1 << endl;
            case 4:
                cout << 1 << endl;
                
            default:
                break;
        }
        
        int fart;
        
        fart = fart++;
        cout << fart << endl;
        cout << "You have selected MANUAL" <<endl;
        int innings = 1;
        int inningMax = 3;
        string team1Name = "";
        string team2Name = "";
        team1Name = getTeamName(1);
        team2Name = getTeamName(2);
        string changing1TeamName = "das";
        string changing2TeamName = "das";
        int inning1TeamScore = 0;
        int inning2TeamScore = 0;
        
        int team1Score = 0;
        int team2Score = 0;
        
        
        do {
            
            if (innings%2 == 1) {
                changing1TeamName = team1Name;
                changing2TeamName = team2Name;
                cout << "Welcome to the start of inning "<< innings << ". It is currently team: "<< changing1TeamName<< "'s turn to have the first bat until 3 outs."<< endl;
            } else {
                changing1TeamName = team2Name;
                changing2TeamName = team1Name;
                cout << "Welcome to the start of inning "<< innings << ". It is currently team: "<< changing2TeamName<< "'s turn to have the first bat until 3 outs."<< endl;

            }
            
            inning1TeamScore = play(changing1TeamName, true, "-1");
            
            cout << "" << endl;
            cout <<"    It is now the second team's turn, "<< changing2TeamName<< " to bat!"<< endl;
            cout << "" << endl;
            
            inning2TeamScore = play(changing2TeamName, true, "-1");

            if (innings%2 == 1) {
                team1Score = team1Score + inning1TeamScore;
                team2Score = team2Score + inning2TeamScore;
            } else {
                team1Score = team1Score + inning2TeamScore;
                team2Score = team2Score + inning1TeamScore;
            }
           
            cout << "The current total score is " <<  endl;
            cout << "   Team: " << team1Name << ": " << team1Score << endl;
            cout << "   Team: " << team2Name << ": " << team2Score << endl;
            innings = innings + 1;
            
            if (team1Score == team2Score) {
                cout << "The teams are currently tied, an extra tie-breaker inning has been added!"<< endl;
                inningMax = inningMax +1;
                
            }
        } while (innings <= inningMax);
        
        if (team1Score > team2Score) {
            winMessage(team1Name, team1Score, team2Score);
        } else if (team2Score > team1Score) {
            winMessage(team2Name, team2Score, team1Score);
        }
    }
    
    else if (getGameMode(gameMode) == 2){
        cout << "You have selected AUTO. In this game mode, you have the additional option to decide each team's skill level. A higher entry will virtually guarantee a win for that team" <<endl;
        
        
        
        cout<< ""<< endl;
        
        
        int innings(1);
        int inningMax{3};
        string team1Name = "";
        string team2Name = "";
        team1Name = getTeamName(1);
        team2Name = getTeamName(2);
        string changing1TeamName = "das";
        string changing2TeamName = "das";
        string changing1Luck = "-1";
        string changing2Luck = "-1";
        int inning1TeamScore = 0;
        int inning2TeamScore = 0;
        
        int team1Score = 0;
        int team2Score = 0;
        cout << "In this game mode, you have the additional option to decide each team's skill level. Enter values from 0-3 with 0 being incompotent fools to 3 being a team of genetically specialized godly baseball players. A null/invalid input is equal to a value of 1" <<endl;
     
        char luck1Temp[256] = "HUEHUEHUE";
        char luck2Temp[256] = "HUEHUEHUE";
       
        
        cout << "   Please enter "<< team1Name << "'s skill."<<endl;
        cin.getline(luck1Temp, 256);

        cout << "   Please enter "<< team2Name << "'s skill." << endl;
        cin.getline(luck2Temp, 256);
        
        string luck1 = string(luck1Temp);
        string luck2 = string(luck2Temp);
        
        if (luck1 != "1" && luck1!= "2" && luck1 != "3" && luck1!="0") {
            cout << "You have entered an invalid skill level, it has been reset to 1" << endl;
            luck1 = "1";
        }
        if (luck2 != "1" && luck2!= "2" && luck2 != "3" && luck2!="0") {
            cout << "You have entered an invalid skill level" << endl;
            luck2 = "1";
        }
        
        do {
            
            if (innings%2 == 1) {
                changing1TeamName = team1Name;
                changing2TeamName = team2Name;
                changing1Luck = luck1;
                changing2Luck = luck2;
                
            } else {
                changing1TeamName = team2Name;
                changing2TeamName = team1Name;
                changing2Luck = luck1;
                changing1Luck = luck2;
            }
            cout << "Welcome to the start of inning "<< innings << ". It is currently "<< changing1TeamName<< "'s turn to have the first bat until 3 outs."<< endl;

            
            inning1TeamScore = play(changing1TeamName, false, changing1Luck);
            
            cout << "" << endl;
            cout <<"    It is now the second team's turn, "<< changing2TeamName<< " to bat!"<< endl;
            cout << "" << endl;
            
            inning2TeamScore = play(changing2TeamName, false, changing2Luck);
            
            if (innings%2 == 1) {
                team1Score = team1Score + inning1TeamScore;
                team2Score = team2Score + inning2TeamScore;
            } else {
                team1Score = team1Score + inning2TeamScore;
                team2Score = team2Score + inning1TeamScore;
            }
            
            cout << "The current total score is " <<  endl;
            cout << "   " << team1Name << ": " << team1Score << endl;
            cout << "   " << team2Name << ": " << team2Score << endl;
            innings = innings + 1;
            
            if (team1Score == team2Score) {
                cout << "The teams are currently tied, an extra tie-breaker inning has been added!"<< endl;
                inningMax = inningMax +1;
            }
            
        } while (innings <= inningMax);
        
        if (team1Score > team2Score) {
            winMessage(team1Name, team1Score, team2Score);
        } else if (team2Score > team1Score) {
            winMessage(team2Name, team2Score, team1Score);
        }
    }
    
    
    
    
    return 0;
}
