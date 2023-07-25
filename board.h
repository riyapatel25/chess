
#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <string>
#include "piece.h"

class Board {
    private:
    Board();
    static Board *currBoard;
    static double whiteWins;
	static double blackWins;
    bool turn;
    //2 player objects

	public:
	~Board();
    vector<vector<Piece>> getPieces();
    bool isCheckmate(turn: bool);
    bool getTurn();
    void setPiece(row: int, col: int);
    void setTurn(turn: bool);
    void Play(input: string);
    bool isTaken(row: int, col: int);
    void displayErrorHnadling(message: string);
    void setupBoard();
    bool isConfigurationValid(board: &Board const); //check is board is setup correctly
};
#endif