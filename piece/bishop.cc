#include <iostream>
#include <string>
#include "bishop.h"
#include "board.h"
using namespace std;

Bishop::Bishop(bool playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}

void Bishop::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    /*
    scenarios for a valid move, a Bishop only moves diagonally, and therefore, 
    both row and column should either increase or decrease by the same value.
   */
    if( rowDifference == columnDifference){
        chessBoard.movePiece(row, col, newRow, newCol);
    } else
    cout << "Invalid move, try again" << endl;

};
bool Bishop::canPlayerKill (int row, int col) {

};

