#include <iostream>
#include <string>
#include "king.h"
#include "board.h"
using namespace std;

King::King(bool playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}


bool King::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;
    
    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move
    if((rowDifference == 1 && columnDifference == 0) || (rowDifference== 0 && columnDifference == 1)
     || (rowDifference ==1 && columnDifference ==1) ){
        // chessBoard.movePiece(row, col, newRow, newCol);
        return true
    } else{

    cout << "Invalid move, try again" << endl;
        return false;
    }

}



bool King::canPlayerKill (int row, int col) {
    return false;
}

