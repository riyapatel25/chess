#include <iostream>
#include <string>
#include "piece.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include "horse.h"
#include "pawn.h"
#include "empty.h"
#include "bishop.h"
#include "board.h"

using namespace std;

bool isCheck (int row, int col, int newRow, int newCol) {};

void getPlayerMove (int row, int col, int newRow, int newCol, Board& chessBoard) {

    /*
    Here,
    based on the piece type at the board position, call the respective piece type.
    Also, need to split commands like E8 so that E->5, since that is the column number.
    */

   if(chessBoard[row][col].pieceName == "Queen") {
    Queen queen;
    queen.playerMove(row, col, newRow, newCol, chessBoard);
   }
    else if (chessBoard[row][col].pieceName == "Rook") {
        Rook rook; 
        rook.playerMove(row, col, newRow, newCol, chessBoard); 
    } 
    else if (chessBoard[row][col].pieceName == "Bishop") {
        Bishop bishop; 
        bishop.playerMove(row, col, newRow, newCol, chessBoard); 
    }
    else if (chessBoard[row][col].pieceName == "King") {
        King king; 
        king.playerMove(row, col, newRow, newCol, chessBoard); 
    }
    else if (chessBoard[row][col].pieceName == "Pawn") {
        Pawn pawn; 
        pawn.playerMove(row, col, newRow, newCol, chessBoard); 
    }
    else if (chessBoard[row][col].pieceName == "Horse") {
        Horse horse; 
        horse.playerMove(row, col, newRow, newCol, chessBoard); 
    }
        else if (chessBoard[row][col].pieceName == "Empty") {
        Empty empty; 
        empty.playerMove(row, col, newRow, newCol, chessBoard); 
    }


}