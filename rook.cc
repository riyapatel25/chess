#include <iostream>
#include <string>
#include "rook.h"
#include "board.h"
using namespace std;

Rook::Rook(int playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}

bool Rook::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    // checks if the new position is within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move, a Rook will only move in the same column or the same row for a given move.
    if( (rowDifference > 0 && columnDifference == 0) 
        || (columnDifference > 0 && rowDifference == 0)) {

        int rowStep = (newRow > row) ? 1 : ((newRow < row) ? -1 : 0); // Direction to move vertically
        int colStep = (newCol > col) ? 1 : ((newCol < col) ? -1 : 0); // Direction to move horizontally
        int steps = max(rowDifference, columnDifference);

        for (int i = 1; i < steps; i++) {
            // Check each cell along the path
            int checkRow = row + i * rowStep;
            int checkCol = col + i * colStep;
            if (chessBoard.getCurrBoard()[checkRow][checkCol].color != 2) {
                return false;
            }
        }
        return true; 
    } 
    else 
    {
        return false;
    }

}

bool Rook::canPlayerKill (int row, int col) {
    return false;
}
bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard){

    // this checks left
    int r1 = newRow;
    int c1 = newCol - 1;
    
    while (c1>=0) {
        if(chessBoard.getCurrBoard[r1][c1].color != this.color && 
        ((chessBoard.getCurrBoard[r1][c1].name == 'K') || 
        (chessBoard.getCurrBoard[r1][c1].name == 'k'))) {
            return true;
        }
        c1-=1;
    }

    // this checks right
    int r2 = newRow;
    int c2 = newCol + 1;    
    while (c2<=7) {
        if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
        ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
        (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
            return true;
        }
        c2+=1;
    }

    // this checks down
    int r3 = newRow + 1;
    int c3 = newCol;    
    while (r3<=7) {
        if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
        ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
        (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
            return true;
        }
        r3+=1;
    }

    // this checks up
    int r4 = newRow - 1;
    int c4 = newCol;    
    while (r4 >=0) {
        if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
        ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
        (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
            return true;
        }
        r4-=1;
    }

    return false;
}
