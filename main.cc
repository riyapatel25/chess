
#include <iostream>
#include <string>
#include "piece.h"
#include "board.h"
#include <vector>

using namespace std;


int main() {
    Board chessGame = Board("human", "human");
    cout << chessGame;
    bool inSetupMode = false;
    bool hasGameBegun = false;
    vector<PieceInfo> storePieceInfo; //for setup mode

    string command;
    while (true) {
        getline(cin, command);
        if(inSetupMode){
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

        else if ((command == "resign" || chessGame.getHasWon() )&& !inSetupMode) {
            break; // Exit the program if someone wins or resigns 
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
                hasGameBegun = true;
                cout << "Begin Game!" << endl;
            }
        }
        else if (hasGameBegun) {
            cout << "here is the move: " << command << endl;
            // Process the move command and extract starting and ending coordinates
            if (command.substr(0, 4) == "move") {
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

                // Call the play() function with the extracted coordinates
                chessGame.play(letterStart, numberStart, letterEnd, numberEnd);
                cout << chessGame;
            }
            else {
                cout << "Invalid move command.\n";
            }
        }
        else {
            cout << "Invalid command, try again!" <<endl;
        }
    }

    return 1;
}

