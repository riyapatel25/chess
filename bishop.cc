#include <iostream>
#include <string>
#include "bishop.h"
#include "board.h"
using namespace std;

Bishop::Bishop(int playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}

bool Bishop::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    // check if new position is within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    /*
    scenarios for a valid move, a Bishop only moves diagonally, and therefore, 
    both row and column should either increase or decrease by the same value.
   */
    if (rowDifference == columnDifference) {
        // here must be checking if no piece of its own obstructs the path.
        int rowStep = (newRow > row) ? 1 : -1; // Direction to move vertically
        int colStep = (newCol > col) ? 1 : -1; // Direction to move horizontally

        for (int i = 1; i < rowDifference; i++) {
            // Check each cell along the diagonal path (excluding the starting and target cells)
            int checkRow = row + i * rowStep;
            int checkCol = col + i * colStep;

            // Check if there's a piece in the cell
            if (chessBoard.getCurrBoard()[checkRow][checkCol]->color != 2) {
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

bool Bishop::canPlayerKill (int row, int col) {
    return false;
}

bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard, int color) {

    int r1 = newRow - 1;
    int c1 = newCol - 1;
    
    while (r1>=0 && c1>=0) {
        if(chessBoard.getCurrBoard[r1][c1].color != this.color && 
        ((chessBoard.getCurrBoard[r1][c1].name == 'K') || 
        (chessBoard.getCurrBoard[r1][c1].name == 'k'))) {
            return true;
        }
        r1-=1;
        c1-=1;
    }

    int r2 = newRow + 1;
    int c2 = newCol + 1;    
    while (r2<=7 && c2<=7) {
        if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
        ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
        (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
            return true;
        }
        r2+=1;
        c2+=1;
    }

    int r3 = newRow + 1;
    int c3 = newCol - 1;    
    while (r3<=7 && c3>=0) {
        if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
        ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
        (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
            return true;
        }
        r3+=1;
        c3+-1;
    }


    int r4 = newRow - 1;
    int c4 = newCol + 1;    
    while (r4>=0 && c4>=7) {
        if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
            ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
            (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
            return true;
        }
        r4-=1;
        c4+=1;
    }

    return false;
}