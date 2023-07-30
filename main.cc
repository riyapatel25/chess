
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
        if (inSetupMode && command != "done") {
            chessGame.processSetupCommand(command, storePieceInfo, false);
        }
        else if (command == "resign" || chessGame.getHasWon()) {
            break; // Exit the program if someone wins or resigns 
        }
        else if (command == "setup") {
            if (inSetupMode) {
                cout << "Already in setup mode.\n";
            } 
            else {
                inSetupMode = true;
                cout << "Entered setup mode.\n";
                chessGame.processSetupCommand(command, storePieceInfo, false);
            }
        }
        else if (command == "done") {
            if (!inSetupMode) {
                cout << "Not in setup mode.\n";
            } 
            // else if (!chessGame.isConfigurationValid()) {
            //     cout << "Invalid setup. Please verify the board.\n";
            // } 
            else {
                inSetupMode = false;
                chessGame.processSetupCommand(command, storePieceInfo, true);
                cout << "Exited setup mode.\n";
                cout << chessGame;

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
                char promotionPiece = ' '; // Default: no promotion

                if (moveParams.length() < 4 || moveParams.length() > 5) {
                    cout << "Invalid move command format.\n";
                    continue;
                }

                letterStart = moveParams[0];
                numberStart = moveParams[1];
                letterEnd = moveParams[3];
                numberEnd = moveParams[4];

                // if (moveParams.length() == 7) {
                //     // Check if promotion piece is specified
                //     promotionPiece = moveParams[6];
                // }

                // Call the play() function with the extracted coordinates
                chessGame.play(letterStart, numberStart, letterEnd, numberEnd);
                cout << chessGame;
            }
            else {
                cout << "Invalid move command.\n";
            }
        }
        else {
            cout << "Invalid command, try again!";
        }
    }

    return 1;
}

