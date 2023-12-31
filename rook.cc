#include <iostream>
#include <string>
#include "rook.h"
#include "board.h"
using namespace std;

Rook::Rook(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}

bool Rook::playerMove (int row, int col, int newRow, int newCol, const  vector<vector<Piece*>>  chessBoard, bool turn, bool vCheck){


    if (chessBoard[row][col]->getColor() != turn){
        return false;
    }

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
            if (chessBoard[checkRow][checkCol]->getColor() != 2) {
                return false;
            }
        }
         if (chessBoard[newRow][newCol]->getColor() == this->getColor()){
            return false;
        }
        // isCheck is here, because the piece is playable, so check for the opponent's.
        // the last parameter here is redundant.
        if(isCheck(newRow, newCol, chessBoard, chessBoard[newRow][newCol]->getColor()) && vCheck!= true){
            if(turn == 0){
                cout << "White is in check." << endl;
            }
            else if (turn == 1) {
                cout << "Black is in check." << endl;
            }
        }
        return true; 
    } 
    else 
    {
        return false;
    }

}

vector<Move> Rook::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;
    bool vCheck = true;
    // The directions a rook can move (up, down, left, right)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Continue moving in the same direction until we find an invalid move
        while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn, vCheck)) {
                break;
            }

            validMoves.emplace_back(Move(row, col, newRow, newCol));

            if (board[newRow][newCol]->getPieceType() != " ") {
                // If the destination square is occupied, we can't continue moving in this direction
                break;
            }

            newRow += dr[i];
            newCol += dc[i];
        }
    }

    return validMoves;
}

bool Rook::isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) {

    // this checks left
    int r1 = newRow;
    int c1 = newCol - 1;
    
    while (c1>=0) {
        if(chessBoard[r1][c1]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r1][c1]->getPieceType() == "K") || 
        (chessBoard[r1][c1]->getPieceType() == "k"))) {
            return true;
        }  else 
        if (chessBoard[r1][c1]->getPieceType() != " ") {
            break;
        }
        c1-=1;
    }

    // this checks right
    int r2 = newRow;
    int c2 = newCol + 1;    
    while (c2<=7) {
        if(chessBoard[r2][c2]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r2][c2]->getPieceType() == "K") || 
        (chessBoard[r2][c2]->getPieceType() == "k"))) {
            return true;
        }  else 
        if (chessBoard[r2][c2]->getPieceType() != " ") {
            break;
        }
        c2+=1;
    }

    // this checks down
    int r3 = newRow + 1;
    int c3 = newCol;    
    while (r3<=7) {
        if(chessBoard[r3][c3]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r3][c3]->getPieceType() == "K") || 
        (chessBoard[r3][c3]->getPieceType() == "k"))) {
            return true;
        }  else 
        if (chessBoard[r3][c3]->getPieceType() != " ") {
            break;
        }
        r3+=1;
    }

    // this checks up
    int r4 = newRow - 1;
    int c4 = newCol;    
    while (r4 >= 0) {
        if(chessBoard[r4][c4]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r4][c4]->getPieceType() == "K") || 
        (chessBoard[r4][c4]->getPieceType() == "k"))) {
            return true;
        }  else 
        if (chessBoard[r4][c4]->getPieceType() != " ") {
            break;
        }
        r4-=1;
    }

    return false;
}

