#include <iostream>
#include <string>
#include "king.h"
#include "board.h"
using namespace std;

King::King(int playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}


bool King::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) {

    // check if new position is within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;
    
    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move: left/right/up/down or any diagonal, only one spot.
    if((rowDifference == 1 && columnDifference == 0) 
    || (rowDifference== 0 && columnDifference == 1)
    || (rowDifference ==1 && columnDifference ==1)) {
        return true;
    } else
    {
        return false;
    }
}

bool King::canPlayerKill (int row, int col) {
    return false;
}

// this function checks if the playing King is in check with the opponent player's king.
bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard) {

    int r1 = newRow - 1;
    int c1 = newCol - 1;
    
    if (r1>=0 && c1>=0) {
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
    if (r2<=7 && c2<=7) {
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
    if (r3<=7 && c3>=0) {
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
    if (r4>=0 && c4>=7) {
        if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
            ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
            (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
            return true;
        }
        r4-=1;
        c4+=1;
    }

    // this checks left
    int r1 = newRow;
    int c1 = newCol - 1;
    
    if (c1>=0) {
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
    if (c2<=7) {
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
    if (r3<=7) {
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
    if (r4 >=0) {
        if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
        ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
        (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
            return true;
        }
        r4-=1;
    }

    return false;
}

