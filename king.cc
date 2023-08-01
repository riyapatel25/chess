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
        // isCheck is here, because the piece is playable, so check for the opponent's.
        // the last parameter here is redundant.
        if(isCheck(newRow, newCol, chessBoard, chessBoard[newRow][newCol]->color)){
            if(turn == 0){
                cout << "White is in check." << endl;
            }
            else if (turn == 1) {
                cout << "Black is in check." << endl;
            }
        }
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
bool King::isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color){

    // this checks bottom left diagonal
    int r1 = newRow - 1;
    int c1 = newCol - 1;
    
    if (r1>=0 && c1>=0) {
        if(chessBoard[r1][c1]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r1][c1]->pieceType == "K") || 
        (chessBoard[r1][c1]->pieceType == "k"))) {
            return true;
        }
    }

    // this checks top-right diagonal
    int r2 = newRow + 1;
    int c2 = newCol + 1;    
    if (r2<=7 && c2<=7) {
        if(chessBoard[r2][c2]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r2][c2]->pieceType == "K") || 
        (chessBoard[r2][c2]->pieceType == "k"))) {
            return true;
        }
    }

    // checks a diagonal
    int r3 = newRow + 1;
    int c3 = newCol - 1;    
    if (r3<=7 && c3>=0) {
        if(chessBoard[r3][c3]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r3][c3]->pieceType == "K") || 
        (chessBoard[r3][c3]->pieceType == "k"))) {
            return true;
        }
    }

    int r4 = newRow - 1;
    int c4 = newCol + 1;    
    if (r4>=0 && c4<=7) {
        if(chessBoard[r4][c4]->color != chessBoard[newRow][newCol]->color && 
            ((chessBoard[r4][c4]->pieceType == "K") || 
            (chessBoard[r4][c4]->pieceType == "k"))) {
            return true;
        }
    }

    // this checks left
    r1 = newRow;
    c1 = newCol - 1;
    
    if (c1>=0) {
        if(chessBoard[r1][c1]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r1][c1]->pieceType == "K") || 
        (chessBoard[r1][c1]->pieceType == "k"))) {
            return true;
        }
    }

    // this checks right
    r2 = newRow;
    c2 = newCol + 1;    
    if (c2<=7) {
        if(chessBoard[r2][c2]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r2][c2]->pieceType == "K") || 
        (chessBoard[r2][c2]->pieceType == "k"))) {
            return true;
        }
    }

    // this checks down
    r3 = newRow + 1;
    c3 = newCol;
    if (r3 <= 7) {
        if(chessBoard[r3][c3]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r3][c3]->pieceType == "K") || 
        (chessBoard[r3][c3]->pieceType == "k"))) {
            return true;
        }
    }

    // this checks up
    r4 = newRow - 1;
    c4 = newCol;    
    if (r4 >= 0) {
        if(chessBoard[r4][c4]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r4][c4]->pieceType == "K") || 
        (chessBoard[r4][c4]->pieceType == "k"))) {
            return true;
        }
    }

    return false;
}