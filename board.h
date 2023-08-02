#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
#include <string>
#include "score.h"
#include "player.h"
using namespace std;

class Piece;
class Player;

struct PieceInfo {
    char command; // Either '+' or '-'
    char pieceType; // Piece type character
    char letter; // Letter for position (e.g., 'e')
    char number; // Number for position (e.g., '1')
};

class Board {
private:
    Score* currScore;
    Player* player1; // White player
    Player* player2; // Black player

protected:
    pair<bool, int> winInfo;
    vector<vector<Piece*>> currBoard; 

public:
    ~Board(); // Destructor
    string play1;
    string play2;
    bool turn; // Keeps track of who's turn -> white (true), black (false)
    bool stalemate;
    Board(); // Board Constructor
    void playHuman(char letterStart, char numberStart, char letterEnd, char numberEnd); // Function to make a move
    void playComputer();
    bool isConfigurationValid(); // Check if the board is set up correctly -> Helper for constructor
    bool isCheckmate(bool turn);
    bool getTurn();
    pair<bool, int> getHasWon();
    void setPiece(int row, int col);
    void setTurn(bool turn);
    bool isTaken(int row, int col);
    void displayErrorHandling(string message);
    void initPlayers(string type1, string type2);
    pair<int, int> getCoords(pair<char, char>& coords);
    friend ostream& operator<<(ostream& os, const Board& chessBoard);
    int processSetupCommand(string input, vector<PieceInfo>& storePieceInfo);
    void setupBoard(); // Helper for constructor 
    void clearBoard();
    void gameEnded(double score, int whichPlayerWon);
    void playHelper(int row, int col, int newRow, int newCol);
    pair<double, double> finalWins();
    string getPieceType(int row, int col);
};

#endif