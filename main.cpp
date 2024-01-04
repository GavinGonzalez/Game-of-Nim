/****************************************************************
File: main.cpp
Description: A mathematical game of strategy with a number of variants
Author: Gavin Gonzalez
Class: CSCI-110-70
Date: 11/5/23
I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string mode = "";
    int numStones = 0;
    int roll = 0;  // if 1 computer's turn if 0 players turn
    
    bool firstRoll = true;
    
    bool presentTurn = false; //false if computer true if player
    
    string stoneTake = ""; // the number of stones the user will take a given time
    
    srand(time(0));
    
    cout<<"*************** THE GAME OF NIM ***************" << endl;
    cout << "Rules of the game:" << endl;
    cout << "* Each player can remove 1, 2, or 3 stones from the pile." << endl;
    cout << "* The player who makes the last move loses." << endl;
    cout << endl;
    //----need to do input validation for the game mode
    cout << "Choose mode:" << endl;
    cout << "Easy Mode (e) or Hard Mode (h): ";

    
    //input validation for the mode ---- I'm not sure if you wanted us to do this, but I did it anyways
    bool isCleared = false;
    while(isCleared == false) {
       
        cin >> mode;
        
        
        if(isalpha(mode[0]) != 0 && ((mode[0] == 'e' || mode[0] == 'E') || (mode[0] == 'h' || mode[0] == 'H'))) {
            isCleared = true;
        } 
       
    }
    
    if(mode == "e") {
        cout << "You have chosen the easy mode." << endl;
    } else if(mode == "h") {
        cout << "You have chosen the hard mode." << endl;
    }
    cout << endl;
    
    //generating pile
    numStones = (random()%11)+(21-10);
    
    cout << "The initial number of stones is " << numStones << endl;
    cout << "Now a roll of the die to determine who plays first..." << endl;
    
    roll = (random())%2;
    bool turn = false;
    
    if(roll) {
        turn = true;
    }
    
    
    while(numStones > 0) {
        
    
        //if computer's turn
        if(turn) {
            if(firstRoll) {
                cout << "The computer plays first." << endl;
                cout << endl;
                firstRoll = false;
            }
           cout << "The computer is choosing a move..." << endl;
           
         
           //demterming how many stones the computer will take based on the mode
           int stonesTaken = 0;
           
           //if on easy mode
           if(mode == "e") {
                
               //if the number oif stones left is less than three
               if(numStones < 3) {
                   stonesTaken = (random()%numStones)+1;
               } else {
                   stonesTaken = (random()%4)+1;
               }
               
                 
                if(stonesTaken == 1) {
                  cout << "The computer removed 1 stone from the pile" << endl;
                } else{
                    cout << "The computer removed " << stonesTaken << " stones from the pile" << endl;
                } 
               
           } else { //if on hard mode
          
                //If the number of stones is a multiple of four plus 1, computer has no winning strategy
               if((numStones-1)%4 == 0) {
                   
                  stonesTaken = 1;
                   
               } else {
                   
                    for(int i = 1; i <= 3; i++) {
                        if(((numStones-i)-1)%4 == 0) {
                            stonesTaken = i;
                        }
                    }
                   
               }
               
               cout << "-- taking enough stones to leave a multiple of four plus one --" << endl;
                   
                if(stonesTaken == 1) {
                  cout << "  removed 1 stone from the pile" << endl;
                } else{
                    cout << "  removed " << stonesTaken << " stones from the pile" << endl;
                }
                
           }
           
           
           numStones -= stonesTaken;
           turn = false;
           
           //if the computer lost the game
           
           
         //if payers turn
        } else {
        
            if(firstRoll) {
                cout << "You play first." << endl;
                firstRoll = false;
            }
            
            bool isCleared = false;
            int numTaken = 0; //it's the number of stones taken casted as an int
            
            
            
            bool presentPlayer = true;
          
            
            
            
            
            cout << "It is your turn. Enter the number of stones you would like to remove: ";
            
            /*Checking if the input is a number and if the number is less than the 
            number of stones in the pile*/
            
            while(isCleared == false) {
            
                
                cin >> stoneTake;
                //checking if every character in the string is a digit
                
                if(isdigit(stoneTake[0]) != 0 && stoneTake.size() == 1) {
                      
                    //creating an integer out of the char
                    numTaken = (int(stoneTake[0])-48);
        
               
                    /*checking if the number of stones inputed is less than the number in the pile
                    and if the inputed number is 1, 2, 3
                    */
                    if(numTaken <= numStones && numTaken > 0 && (numTaken == 1 || numTaken == 2 || numTaken == 3)) {
                        isCleared = true;
                            
                            
                    } else {
                        cout << stoneTake << " is not a invalid move. Enter either 1, 2, or 3 for the number of stones: ";
                        numTaken = 0;
                    }
                    
                } else {
                    cout << stoneTake << " is a invalid move. Enter either 1, 2, or 3 for the number of stones: ";
                
                    numTaken = 0;
                }
                
               
            
            }  // end of chekcing while loop-------------------
            
            numStones -= numTaken;
            
            if(numTaken == 1) {
                   cout << "You have removed 1 stone from the pile" << endl;
            } else{
                   cout << "You have removed " << numTaken << " stones from the pile" << endl;
            }
            
            
            turn = true;
            
            
        }
        
        //printing out how many stones are left
        if(numStones == 1) {
            cout << "The pile now has 1 stone left" << endl;
        } else{
            cout << "The pile now has " << numStones << " stones left." << endl;
        }
        cout << endl;
            
        
        //if the there are no more stones left
        if (numStones == 0) {
            //if it was the players turn he has lost
            if(turn) {
                cout << "Sorry, you lost the game :<" << endl << endl;
                
            }else { //if it was the computers turn he has won
                cout << "Congratulations, you won! :>" << endl << endl;
            }
            
            cout<<"*************** Thank you for playing ***************" << endl << endl << endl;
            cout << "Press any key to continue . . . " << endl;
        }
    
    }

    return 0;
}





