#include <iostream>
#include <string>
#include "king.h"
#include "board.h"
using namespace std;

King::King(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}


bool King::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn) {


  if (chessBoard[row][col]->color != turn){
        return false;
  }

  if (chessBoard[newRow][newCol]->color == this->color){
            return false;
        }


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


vector<Move> King::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;

    // The directions a king can move (up, down, left, right, and diagonals)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Check if the new position is within the bounds of the board
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {

            if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn)) {
                break;
            }
            // Check if the new position is not occupied by a piece of the same color
            if (board[newRow][newCol]->pieceType == " ") {
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            } else if (board[newRow][newCol]->color != board[row][col]->color) {
                // kill
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            }
        }
    }

    return validMoves;
}

// // this function checks if the playing King is in check with the opponent player's king.
// bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard) {

//     int r1 = newRow - 1;
//     int c1 = newCol - 1;
    
//     if (r1>=0 && c1>=0) {
//         if(chessBoard.getCurrBoard[r1][c1].color != this.color && 
//         ((chessBoard.getCurrBoard[r1][c1].name == 'K') || 
//         (chessBoard.getCurrBoard[r1][c1].name == 'k'))) {
//             return true;
//         }
//         r1-=1;
//         c1-=1;
//     }

//     int r2 = newRow + 1;
//     int c2 = newCol + 1;    
//     if (r2<=7 && c2<=7) {
//         if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
//         ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
//         (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
//             return true;
//         }
//         r2+=1;
//         c2+=1;
//     }

//     int r3 = newRow + 1;
//     int c3 = newCol - 1;    
//     if (r3<=7 && c3>=0) {
//         if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
//         ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
//         (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
//             return true;
//         }
//         r3+=1;
//         c3+-1;
//     }

//     int r4 = newRow - 1;
//     int c4 = newCol + 1;    
//     if (r4>=0 && c4>=7) {
//         if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
//             ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
//             (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
//             return true;
//         }
//         r4-=1;
//         c4+=1;
//     }

//     // this checks left
//     int r1 = newRow;
//     int c1 = newCol - 1;
    
//     if (c1>=0) {
//         if(chessBoard.getCurrBoard[r1][c1].color != this.color && 
//         ((chessBoard.getCurrBoard[r1][c1].name == 'K') || 
//         (chessBoard.getCurrBoard[r1][c1].name == 'k'))) {
//             return true;
//         }
//         c1-=1;
//     }

//     // this checks right
//     int r2 = newRow;
//     int c2 = newCol + 1;    
//     if (c2<=7) {
//         if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
//         ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
//         (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
//             return true;
//         }
//         c2+=1;
//     }

//     // this checks down
//     int r3 = newRow + 1;
//     int c3 = newCol;    
//     if (r3<=7) {
//         if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
//         ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
//         (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
//             return true;
//         }
//         r3+=1;
//     }

//     // this checks up
//     int r4 = newRow - 1;
//     int c4 = newCol;    
//     if (r4 >=0) {
//         if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
//         ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
//         (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
//             return true;
//         }
//         r4-=1;
//     }

//     return false;
// }