#include <iostream>
#include <string>
#include "rook.h"
#include "board.h"
using namespace std;

void Rook::playerMove (int row, int col, int newRow, int newCol, Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return;
    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move, a Rook will only move in the same column or the same row for a given move.
    if( (rowDifference > 0 && columnDifference == 0) || (columnDifference > 0 && rowDifference == 0)){
        chessBoard.movePiece(row, col, newRow, newCol);
    } else
    cout << "Invalid move, try again" << endl;


};
bool Rook::canPlayerKill (int row, int col) {};

