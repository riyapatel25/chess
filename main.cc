#include <iostream>
using namespace std;
#include "./piece/piece.h"
#include "board.h"
#include <vector>


int main() {

    Board chessGame = Board("human", "human", true, "");
    bool inSetupMode = false;

    std::string command;
    while (true) {
        
        std::getline(std::cin, command);

        if (command == "exit") {
            break; // Exit the program
        } else if (command == "setup") {
            if (inSetupMode) {
                std::cout << "Already in setup mode.\n";
            } else {
                inSetupMode = true;
                chessGame.enterSetupMode();
                std::cout << "Entered setup mode.\n";
            }
        } else if (command == "done") {
            if (!inSetupMode) {
                std::cout << "Not in setup mode.\n";
            } else if (chessGame.isConfigurationValid() == false) {
                std::cout << "Invalid setup. Please verify the board.\n";
            } else {
                inSetupMode = false;
                std::cout << "Exited setup mode.\n";
            }
        } else if (command.substr(0, 5) == "game ") {
            if (inSetupMode) {
                std::cout << "Cannot start a game in setup mode.\n";
            } else {
                // Extract white-player and black-player from the command
                std::string whitePlayer = command.substr(5);
                std::string blackPlayer;
                size_t spacePos = whitePlayer.find(' ');
                if (spacePos != std::string::npos) {
                    blackPlayer = whitePlayer.substr(spacePos + 1);
                    whitePlayer = whitePlayer.substr(0, spacePos);
                } else {
                    std::cout << "Invalid command. Usage: game white-player black-player\n";
                    continue;
                }

                // Start a new game with the specified players
                // chessGame.startNewGame(whitePlayer, blackPlayer);
            }
        } else if (inSetupMode) {
            chessGame.processSetupCommand(command);
        } else {
            chessGame.play('a', 'b', 'c', 'd');
        }
    }

    return 0;

// cout << "Chess!" << endl;


//     Board myBoard = Board("human", "human", true, "");

//     // Get the pieces on the board
//     vector<vector<Piece*>> pieces = myBoard.currBoard;

//     // Display the board
//     for (int row = 7; row >= 0; row--) {
//         for (int col = 0; col < 8; col++) {
//             if (pieces[row][col]) {
//                 cout << pieces[row][col]->getSymbol() << " ";
//             } else {
//                 cout << "__ ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;

}

