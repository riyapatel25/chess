
#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include <string>
#include "score.h"
#include "player.h"
using namespace std;
class Piece;

class Board {
    private:
    void setupBoard(bool defaultOrInput); //helper for constructor 
    Score* currScore;
    bool turn; //keeps track of who's turn -> white (true), black (false)
    Player* player1; //white player
    Player* player2; //black player
    

    protected:
    vector<vector<Piece*>> currBoard; 

	public:
	~Board(); //destrcutor
    Board(string type1, string type2, bool isDefault, string setupString); //Board Constructor
    void play(char letterStart, char numberStart, char letterEnd, char numberEnd); //function to make a move
    bool isConfigurationValid(); //check is board is setup correctly -> helper for constructor
    vector<vector<Piece*>> getCurrBoard() const;
    bool isCheckmate(bool turn);
    bool getTurn();
    void setPiece(int row, int col);
    void setTurn(bool turn);
    bool isTaken(int row, int col);
    void displayErrorHandling(string message);
    void initPlayers(string type1, string type2);
    pair<int, int> getCoords(pair<char, char>& coords);
    friend ostream& operator<<(ostream& os, const Board& chessBoard);
    void enterSetupMode();
    void processSetupCommand(string input);
    int whiteWins;
    int blackWins;


};
#endif