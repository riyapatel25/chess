
#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <string>
#include "piece.h"

class Board {
    private:
    Board(type1: string, type2: string, isSetup: bool, setupString: string);
    static Board *currBoard;
    Score currScore;
    bool turn;
    Player player1; //white player
    Player player2; //black player

	public:
	~Board();
    vector<vector<Piece* >> getPieces();
    bool isCheckmate(turn: bool);
    bool getTurn();
    void setPiece(row: int, col: int);
    void setTurn(turn: bool);
    void play(input: string);
    bool isTaken(row: int, col: int);
    void displayErrorHnadling(message: string);
    void setupBoard();
    bool isConfigurationValid(board: &Board const); //check is board is setup correctly
};
#endif