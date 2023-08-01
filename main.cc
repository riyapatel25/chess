
#include <iostream>
#include <string>
#include "piece.h"
#include "board.h"
#include <vector>
#include <sstream>
#include "window.h"


using namespace std;


int main() {
    Board chessGame = Board();
    cout << "Board constructed, start entering commands!" << endl;
    bool inSetupMode = false;
    bool hasGameBegun = false;
    vector<PieceInfo> storePieceInfo; //for setup mode
    Xwindow window = Xwindow(800,800);
    string command;
    while (true) {
    window.draw_board(chessGame);

        
        getline(cin, command);
            if (cin.eof()) {
            cout << "End of input. Exiting the program." << endl;
            cout << "FinalScore:" <<endl;
             pair<double, double> fw = chessGame.finalWins();
            cout << "White: " << fw.first << endl;
            cout << "Black: " << fw.second << endl;
            break;
        }
    
        else if(chessGame.getHasWon().first && !inSetupMode){
            //if in stalemate
            if(chessGame.stalemate){
                cout << "Stalemate!" << endl;
                chessGame.gameEnded(0.5,2);
                inSetupMode = false;
                hasGameBegun = false;
 
            }
            else{
            //if 1 -> white won
            if(chessGame.getHasWon().second  == 1){
                cout << "Checkmate! White wins!" << endl;
                chessGame.gameEnded(1,1);
                inSetupMode = false;
                hasGameBegun = false;
 
            }
            //if 0 -> black won
            else if(chessGame.getHasWon().second  == 0){
                cout << "Checkmate! Black wins!" << endl;
                chessGame.gameEnded(1,0);
                inSetupMode = false;
                hasGameBegun = false;
              

            }
            else{
                cout << "Not valid win!" << endl;
            }
            }
            
        }
        else if(inSetupMode){
            if(command == "setup"){
                 cout << "Already in setup mode.\n";
            }
            else {
                    int check = chessGame.processSetupCommand(command, storePieceInfo);
                    if(check == 1){
                        inSetupMode = false;
                    }
                    cout << chessGame;
            }

        }

        else if (command == "resign" && !inSetupMode) {
            //white resigned
            if(chessGame.turn){
                cout << "Black wins!" << endl;
                chessGame.gameEnded(1,0);
                hasGameBegun = false;
            }
            //black resigned
            else{
                cout << "White wins!" << endl;
                chessGame.gameEnded(1,1);
                hasGameBegun = false;

            }
        }
        else if (command == "setup") {

             if(hasGameBegun){
                    cout << "Game has already begun, cannot enter setup mode!" << endl;
                }
                else{
                cout << "Entered setup mode.\n";
                inSetupMode = true;
                chessGame.clearBoard();
                }

        }
        else if (command.substr(0, 4) == "game") {
           
            if (inSetupMode) {
                cout << "Cannot start a game in setup mode.\n";
            } 
            else if (hasGameBegun) {
                cout << "Game has already started.\n";
            }
            else {
                vector<string> commands; 
                stringstream ss(command);
                string word;
                while (ss >> word) {
                        commands.push_back(word);
                    }
                if(commands.size() == 3){
                    hasGameBegun = true;
                    chessGame.initPlayers(commands[1], commands[2]);
                    cout << "Begin Game!" << endl;
                    cout << chessGame;
                } else {
                    hasGameBegun = false;
                    cout << "Invalid game initialization!" <<endl;
                }

            }
        }
        else if (hasGameBegun) {
            if(chessGame.play1 == "human" && chessGame.play2 == "human"){
            // Process the move command and extract starting and ending coordinates
            if (command.substr(0, 4) == "move" && command.length() == 10) {
                string moveParams = command.substr(5);
                char letterStart, letterEnd;
                char numberStart, numberEnd;
                if (moveParams.length() < 4 || moveParams.length() > 5) {
                    cout << "Invalid move command format.\n";
                    continue;
                }

                letterStart = moveParams[0];
                numberStart = moveParams[1];
                letterEnd = moveParams[3];
                numberEnd = moveParams[4];

                // Call the playHuman() function with the extracted coordinates
                chessGame.playHuman(letterStart, numberStart, letterEnd, numberEnd);
                cout << chessGame;
    
            }
            else {
                cout << "Invalid move command for human vs human.\n";
            }
            }

            else if(chessGame.play1 == "computer" && chessGame.play2 == "computer"){
                if(command == "move") {
                    chessGame.playComputer();
                    cout << chessGame;
                    
                }
                else {
                cout << "Invalid move command for computer vs computer.\n";
                }


            }
             else if(chessGame.play1 == "human" && chessGame.play2 == "computer"){
             // if white turn -> human
             if(chessGame.turn){
                    // Process the move command and extract starting and ending coordinates
                   
                     if (command.substr(0, 4) == "move" && command.length() == 10) {
                        string moveParams = command.substr(5);
                        char letterStart, letterEnd;
                        char numberStart, numberEnd;
                        if (moveParams.length() < 4 || moveParams.length() > 5) {
                            cout << "Invalid move command format for human.\n";
                            continue;
                        }
                        letterStart = moveParams[0];
                        numberStart = moveParams[1];
                        letterEnd = moveParams[3];
                        numberEnd = moveParams[4];

                        // Call the playHuman() function with the extracted coordinates
                        chessGame.playHuman(letterStart, numberStart, letterEnd, numberEnd);
                        cout << chessGame;
                    }
                    else {
                        cout << "Invalid move command for human.\n";
                    }
             }
             //if black turn -> computer
             else{

                if(command == "move") {
                    chessGame.playComputer();
                    cout << chessGame;
                    
                }
                else {
                cout << "Invalid move command for computer.\n";
                }

             }

            }

             else if(chessGame.play1 == "computer" && chessGame.play2 == "human"){
             // if black turn -> human
             if(!chessGame.turn){
                    // Process the move command and extract starting and ending coordinates
                     if (command.substr(0, 4) == "move" && command.length() == 10) {
                        string moveParams = command.substr(5);
                        char letterStart, letterEnd;
                        char numberStart, numberEnd;
                        if (moveParams.length() < 4 || moveParams.length() > 5) {
                            cout << "Invalid move command format for human.\n";
                            continue;
                        }
                        letterStart = moveParams[0];
                        numberStart = moveParams[1];
                        letterEnd = moveParams[3];
                        numberEnd = moveParams[4];

                        // Call the playHuman() function with the extracted coordinates
                        chessGame.playHuman(letterStart, numberStart, letterEnd, numberEnd);
                        cout << chessGame;
                    }
                    else {
                        cout << "Invalid move command for human.\n";
                    }
             }
             //if white turn -> computer
             else{

                if(command == "move") {
                    chessGame.playComputer();
                    cout << chessGame;
                    
                }
                else {
                cout << "Invalid move command for computer.\n";
                }

             }

            }
            else{
                cout << "Not implemented yet" << endl;
            }


        }
        else {
            cout << "Invalid command, try again!" <<endl;
        }
    }

    return 1;
}

