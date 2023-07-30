#include <iostream>
#include <string>
#include "horse.h"
#include "board.h"
using namespace std;

Horse::Horse(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}


bool Horse::playerMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard)
{

    if (!((newRow >= 0 && newRow < 8) && (newCol >= 0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move, a Bishop only moves diagonally.
    if ((rowDifference == 1 && columnDifference == 2) ||
        (rowDifference == 2 && columnDifference == 1))
    {
        // chessBoard.movePiece(row, col, newRow, newCol);
        return true;
    }
    else{
        cout << "Invalid move, try again" << endl;
        return false;
    }
}
bool Horse::canPlayerKill(int row, int col){
    return false;
}
