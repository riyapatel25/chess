
#include <iostream>
#include <string>
#include "piece.h"
#include "board.h"
#include <vector>
#include <sstream>
using namespace std;


int main() {
    Board chessGame = Board();
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
                } else {
                    hasGameBegun = false;
                    cout << "Invalid game initialization!" <<endl;
                }

            }
        }
        else if (hasGameBegun) {
            if(chessGame.play1 == "human" && chessGame.play2 == "human"){
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
            else{
                cout << "Human VS Comp AND Comp VS Human not implemented yet" << endl;
            }


        }
        else {
            cout << "Invalid command, try again!" <<endl;
        }
    }

    return 1;
}

