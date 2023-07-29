#include <iostream>
#include <string>
#include "king.h"
#include "board.h"
using namespace std;

King::King(bool playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}


void King::playerMove (int row, int col, int newRow, int newCol, Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return;
    
    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move
    if((rowDifference == 1 && columnDifference == 0) || (rowDifference== 0 && columnDifference == 1)
     || (rowDifference ==1 && columnDifference ==1) ){
        chessBoard.movePiece(row, col, newRow, newCol);
    } else
    cout << "Invalid move, try again" << endl;

}



bool King::canPlayerKill (int row, int col) {

};

