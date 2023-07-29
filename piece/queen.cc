#include <iostream>
#include <string>
#include "queen.h"
#include "board.h"
using namespace std;

/* playerMove will contain the implementation for first checking if it is a valid move,
    and then it will make the change on the board.
*/
Queen::Queen(bool playerWhiteOrBlack) {}

void Queen::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);

    // scenarios for a valid move
    if (row == newRow || col == newCol || rowDifference == columnDifference){
        chessBoard.movePiece(row, col, newRow, newCol);
    } else
    cout << "Invalid move, try again" << endl;

};

bool Queen::canPlayerKill (int row, int col) {

};
