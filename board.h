
#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <string>
#include "piece.h"

class Board {
    private:
    Board(type1: string, type2: string, isSetup: bool, setupString: string); //Board Constructor
    void setupBoard(defaultOrInput: bool); //helper for constructor 
    Score currScore;
    bool turn; //keeps track of who's turn -> white (true), black (false)
    Player player1; //white player
    Player player2; //black player

    protected:
    Board *currBoard; 

	public:
	~Board(); //destrcutor
    void play(input: string); //function to make a move
    bool isConfigurationValid(board: &Board const); //check is board is setup correctly -> helper for constructor
    vector<vector<Piece* >> getPieces();
    bool isCheckmate(turn: bool);
    bool getTurn();
    void setPiece(row: int, col: int);
    void setTurn(turn: bool);
    bool isTaken(row: int, col: int);
    void displayErrorHandling(message: string);
   
};
#endif