#include <iostream>
#include <string>
#include "horse.h"
#include "board.h"
using namespace std;

Horse::Horse(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}


bool Horse::playerMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn, bool vCheck)
{
     if (chessBoard[row][col]->getColor() != turn){
            return false;
        
     }

     if (chessBoard[newRow][newCol]->getColor() == this->getColor()){

            return false;
        }

    // check if it is within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >= 0 && newCol < 8))){        
        return false;
    }

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move, a Bishop only moves diagonally.
    if ((rowDifference == 1 && columnDifference == 2) ||
        (rowDifference == 2 && columnDifference == 1))
    {
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
    else{
        return false;
    }
}


vector<Move> Horse::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;
    bool vCheck = true;
    // Possible knight moves (relative row and column offsets)
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Check if the new position is within the board boundaries
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if (board[newRow][newCol]->getPieceType() == " " ){
                if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn, vCheck)) {
                    break;
                } else {
                    validMoves.emplace_back(Move(row, col, newRow, newCol));
                }
            } 
            else if (board[newRow][newCol]->getColor() != board[row][col]->getColor()) {
                // kill
                if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn, vCheck)) {
                    break;
                } else {
                    validMoves.emplace_back(Move(row, col, newRow, newCol));
                }            
            }
        }
    }

    return validMoves;
}


bool Horse::isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) {

    // this checks up-left
    int r1 = newRow - 2;
    int c1 = newCol - 1;
    
    if (r1>=0 && c1>=0 ) {
        if(chessBoard[r1][c1]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r1][c1]->getPieceType() == "K") || 
        (chessBoard[r1][c1]->getPieceType() == "k"))) {
            return true;
        }
    }

    //  up-right
    int r2 = newRow - 2;
    int c2 = newCol + 1;
    
    if (r2>=0 && c2<=7) {
        if(chessBoard[r2][c2]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r2][c2]->getPieceType() == "K") || 
        (chessBoard[r2][c2]->getPieceType() == "k"))) {
            return true;
        }
    }

    // this checks down-left
    r2 = newRow + 2;
    c2 = newCol - 1;    
    if (r2<=7 && c2>=0) {
        if(chessBoard[r2][c2]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r2][c2]->getPieceType() == "K") || 
        (chessBoard[r2][c2]->getPieceType() == "k"))) {
            return true;
        }
    }

    // this checks down-right
    int r3 = newRow + 2;
    int c3 = newCol + 1;    
    if (r3<=7 && c3<=7) {
        if(chessBoard[r3][c3]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r3][c3]->getPieceType() == "K") || 
        (chessBoard[r3][c3]->getPieceType() == "k"))) {
            return true;
        }
    }

    // this checks left-down
    r3 = newRow + 1;
    c3 = newCol - 2;
    if (r3<=7 && c3>=0) {
        if(chessBoard[r3][c3]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r3][c3]->getPieceType() == "K") || 
        (chessBoard[r3][c3]->getPieceType() == "k"))) {
            return true;
        }
    }

    // this checks left-up
    r3 = newRow - 1;
    c3 = newCol - 2;
    if (r3>=0 && c3>=0) {
        if(chessBoard[r3][c3]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r3][c3]->getPieceType() == "K") || 
        (chessBoard[r3][c3]->getPieceType() == "k"))) {
            return true;
        }
    }


    // this checks right-up
    int r4 = newRow - 1;
    int c4 = newCol + 2;    
    if (r4>=0 && c4<=7) {
        if(chessBoard[r4][c4]->getColor() != chessBoard[newRow][newCol]->getColor() && 
            ((chessBoard[r4][c4]->getPieceType() == "K") || 
            (chessBoard[r4][c4]->getPieceType() == "k"))) {
            return true;
        }
    }


    // this checks right-down
    r4 = newRow + 1;
    c4 = newCol + 2;    
    if (r4<=7 && c4<=7) {
        if(chessBoard[r4][c4]->getColor() != chessBoard[newRow][newCol]->getColor() && 
            ((chessBoard[r4][c4]->getPieceType() == "K") || 
            (chessBoard[r4][c4]->getPieceType() == "k"))) {
            return true;
        }
    }

    return false;

}