
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

        }

        else if ((command == "resign" || chessGame.getHasWon() )&& !inSetupMode) {
            break; // Exit the program if someone wins or resigns 
        }
        else if (command == "setup") {
            if (inSetupMode) {
                cout << "Already in setup mode.\n";
            } 
            else {
                cout << "Entered setup mode.\n";
                inSetupMode = true;
                //delete board default config
                for (int i = 0; i < currBoard.size(); i++) {
                    for (int j = 0; j < currBoard[i].size(); j++) {
                            delete currBoard[i][j]; //delete piece
                            Empty* e = new Empty(2, " ");
                            currBoard[i][j] = e; 
                                }
                            }

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

