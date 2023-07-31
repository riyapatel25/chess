#include <iostream>
#include <string>
#include "pawn.h"
using namespace std;

Pawn::Pawn(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}


bool Pawn::playerMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn)
{
      if (chessBoard[row][col]->color != turn){
        return false;
      }

     if (chessBoard[newRow][newCol]->color == this->color){
            return false;
        }
    // check if the co-ordinates are within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >= 0 && newCol < 8))){
        return false;
    }

    int rowDifference = newRow - row;
    int columnDifference = newCol - col;
    // a columnDifference = rowDifference = 1 indicates an attack move, so must make sure that
    // there is a piece at that position, otherwise it will not be a valid move.

    // This indicates a black player, for now the pieces will occupy rows 6,7
    // therefore, can only move rows downward
    if (turn == 0)
    {
        if (rowDifference == 1 && columnDifference == 0)
        {
            // check if there's a piece in front of the pawn, if there is, then return false else true
            if (chessBoard[newRow][newCol]->color == 0 ||
                chessBoard[newRow][newCol]->color == 1)
            {
                return false;
            }
            return true;
        }
        else{

            // this indicates attack move, must check if there's a piece there.
            if ((rowDifference == 1) && (columnDifference == -1 || columnDifference == 1))
            {
                
                if (chessBoard[newRow][newCol]->color == 1)
                {

                    return true;
                }
                return false;
            }
        }
    }

    // This indicates a white player, for now the pieces will occupy rows 0,1
    // therefore, can only move rows upward
    else if (turn == 1)
    {
        if (rowDifference == -1 && columnDifference == 0)
        {

            // check if there's a piece in front of the pawn, if there is, then return false else true
            if (chessBoard[newRow][newCol]->color == 0 ||
                chessBoard[newRow][newCol]->color == 1)
            {
                return false;
            }
            return true;
        }

        else
            // this indicates attack move, must check if there's a piece there.
            if ((rowDifference == -1 ) && (columnDifference == -1 || columnDifference == 1))
            {
    
                if (chessBoard[newRow][newCol]->color == 0)
                {
                    return true;
                }
                return false;
            }
    }
}



// // isCheck should be called as the last condition, right before a "return true",
// // if it's returning false, no need to check it
// bool Pawn::isCheck(int row, int col, int newRow, int newCol, const Board &chessBoard)
// {
//     // Pawn can only be in check with king diagonally, so we check if the king lies anywhere
//     // in the diagonal viscinity.

//     // If the color is black, Pawn is moving downwards, so only check 2 spaces
//     if (chessBoard.getCurrBoard[newRow][newCol].color == 0)
//     {
//         int r1 = newRow + 1;
//         int c1 = newCol + 1;

//         if (r1 <= 7 && c1 <= 7)
//         {
//             if (chessBoard.getCurrBoard[r1][c1].color != this.color &&
//                 ((chessBoard.getCurrBoard[r1][c1].name == 'K') ||
//                  (chessBoard.getCurrBoard[r1][c1].name == 'k')))
//             {
//                 return true;
//             }
//         }
//         else
//         {
//             int r2 = newRow + 1;
//             int c2 = newCol + 1;
//             if (r2 <= 7 && c2 >= 0)
//             {
//                 if (chessBoard.getCurrBoard[r2][c2].color != this.color &&
//                     ((chessBoard.getCurrBoard[r2][c2].name == 'K') ||
//                      (chessBoard.getCurrBoard[r2][c2].name == 'k')))
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     else
//         // if the pawn is white, it's moving up, should look for black pawns diagonally
//         if (chessBoard.getCurrBoard[newRow][newCol].color == 1)
//         {
//             int r1 = newRow - 1;
//             int c1 = newCol - 1;

//             if (r1 >= 0 && c1 >= 0)
//             {
//                 if (chessBoard.getCurrBoard[r1][c1].color != this.color &&
//                     ((chessBoard.getCurrBoard[r1][c1].name == 'K') ||
//                      (chessBoard.getCurrBoard[r1][c1].name == 'k')))
//                 {
//                     return true;
//                 }
//             }
//             else
//             {
//                 int r2 = newRow - 1;
//                 int c2 = newCol + 1;
//                 if (r2 >= 0 && c2 <= 7)
//                 {
//                     if (chessBoard.getCurrBoard[r2][c2].color != this.color &&
//                         ((chessBoard.getCurrBoard[r2][c2].name == 'K') ||
//                          (chessBoard.getCurrBoard[r2][c2].name == 'k')))
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//     return false;
// }