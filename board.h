
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
    protected:
    // bool hasWon;
    pair<bool, int> winInfo;
    
    Score* currScore;
    Player* player1; //white player
    Player* player2; //black player

	public:
	~Board(); //destrcutor
    vector<vector<Piece*>> currBoard; 
    bool turn; //keeps track of who's turn -> white (true), black (false)
    bool stalemate;
	// ~Board(); //destrcutor
    Board(); //Board Constructor
    void playHuman(char letterStart, char numberStart, char letterEnd, char numberEnd); //function to make a move
    void playComputer();
    bool isConfigurationValid(); //check is board is setup correctly -> helper for constructor
    vector<vector<Piece*>> getCurrBoard() const;
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
    void setupBoard(); //helper for constructor 
    void clearBoard();
    void gameEnded(double score, int whichPlayerWon);
    string play1;
    string play2;
    void playHelper(int row, int col, int newRow, int newCol);
    pair<double, double> finalWins();
    string getPieceType(int row, int col);

};
#endif