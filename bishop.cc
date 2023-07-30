#include <iostream>
#include <string>
#include "bishop.h"
#include "board.h"
using namespace std;

Bishop::Bishop(bool playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}

bool Bishop::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    /*
    scenarios for a valid move, a Bishop only moves diagonally, and therefore, 
    both row and column should either increase or decrease by the same value.
   */
    if( rowDifference == columnDifference){
        // chessBoard.movePiece(row, col, newRow, newCol);
        return true;
    } else{
    cout << "Invalid move, try again" << endl;
    return false;
    }

}
bool Bishop::canPlayerKill (int row, int col) {
    return false;
}

