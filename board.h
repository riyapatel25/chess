
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
    vector<vector<Piece*>> currBoard; 
    protected:
    bool hasWon;
    Score* currScore;
    bool turn; //keeps track of who's turn -> white (true), black (false)
    Player* player1; //white player
    Player* player2; //black player

	public:
	// ~Board(); //destrcutor
    Board(string type1, string type2); //Board Constructor
    void play(char letterStart, char numberStart, char letterEnd, char numberEnd); //function to make a move
    bool isConfigurationValid(); //check is board is setup correctly -> helper for constructor
    vector<vector<Piece*>> getCurrBoard() const;
    bool isCheckmate(bool turn);
    bool getTurn();
    bool getHasWon();
    void setPiece(int row, int col);
    void setTurn(bool turn);
    bool isTaken(int row, int col);
    void displayErrorHandling(string message);
    void initPlayers(string type1, string type2);
    pair<int, int> getCoords(pair<char, char>& coords);
    friend ostream& operator<<(ostream& os, const Board& chessBoard);
    // void enterSetupMode();
    // void processSetupCommand(string input);
    // void processSetupCommand(string input,  vector<pair<char, pair<int, int>>>& storePieceInfo, bool isSetupComplete);
    void processSetupCommand(string input, vector<PieceInfo>& storePieceInfo, bool isSetupComplete);
    int whiteWins;
    int blackWins;
    void setupBoard(); //helper for constructor 

};
#endif