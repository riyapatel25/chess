#include <iostream>
#include <string>
#include "pawn.h"
using namespace std;

Pawn::Pawn(int playerWhiteOrBlack, string pieceType, bool hasMoved) : Piece{playerWhiteOrBlack, pieceType}, hasMovedBefore{hasMoved} {}

bool Pawn::playerMove(int row, int col, int newRow, int newCol, const vector<vector<Piece *>> chessBoard, bool turn, bool vCheck)
{
    if (chessBoard[row][col]->getColor() != turn)
    {
        return false;
    }

    if (chessBoard[newRow][newCol]->getColor() == this->getColor())
    {
        return false;
    }
    // check if the co-ordinates are within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >= 0 && newCol < 8)))
    {
        return false;
    }

    int rowDifference = newRow - row;
    int columnDifference = newCol - col;

    if (turn == 0)
    {
        if ((rowDifference == 1 && columnDifference == 0) || 
            (rowDifference == 2 && columnDifference == 0 && this->hasMovedBefore == false))
        {
            // check if there's a piece in front of the pawn, if there is, then return false
            int i = row + 1;
            while (i <= newRow){
                if (chessBoard[i][newCol]->getColor() == 0 ||
                    chessBoard[i][newCol]->getColor() == 1)
                {
                    return false;
                }
                i+=1;
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
            this->hasMovedBefore = true;
            return true;
        }
        else
        {

            // this indicates attack move, must check if there's a piece there.
            if ((rowDifference == 1) && (columnDifference == -1 || columnDifference == 1))
            {

                if (chessBoard[newRow][newCol]->getColor() == 1)
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
                    this->hasMovedBefore = true;
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
        if ((rowDifference == -1 && columnDifference == 0) || 
            (rowDifference == -2 && columnDifference == 0 && this->hasMovedBefore == false))
        {

            // check if there's a piece in front of the pawn, if there is, then return false else true
            int i = row - 1;
            while (i >= newRow){
                if (chessBoard[i][newCol]->getColor() == 0 ||
                    chessBoard[i][newCol]->getColor() == 1)
                {
                    return false;
                }
                i-=1;
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
            this->hasMovedBefore = true;
            return true;
        }

        else
            // this indicates attack move, must check if there's a piece there.
            if ((rowDifference == -1) && (columnDifference == -1 || columnDifference == 1))
            {

                if (chessBoard[newRow][newCol]->getColor() == 0)
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
                    this->hasMovedBefore = true;
                    return true;
                }
                return false;
            }
    }
}

vector<Move> Pawn::getValidMovesForPiece(vector<vector<Piece *>> board, int row, int col, bool turn)
{
    bool vCheck = true;
    vector<Move> validMoves;

    // Define the direction the pawn moves based on its color
    int direction = (turn) ? -1 : 1;

    // Check if the square in front of the pawn is empty
    int newRow = row + direction;
    int newCol = col;

    if (board[row][col]->playerMove(row, col, newRow, newCol, board, turn, vCheck))
    {

        validMoves.emplace_back(Move(row, col, newRow, newCol));
    }
 
    return validMoves;
}

// isCheck should be called as the last condition, right before a "return true",
// if it's returning false, no need to check it
bool Pawn::isCheck(int newRow, int newCol, const vector<vector<Piece *>> chessBoard, int color)
{
    // Pawn can only be in check with king diagonally, so we check if the king lies anywhere
    // in the diagonal viscinity.

    // If the color is black, Pawn is moving downwards, so only check 2 spaces
    if (chessBoard[newRow][newCol]->getColor() == 0)
    {
        int r1 = newRow + 1;
        int c1 = newCol + 1;

        if (r1 <= 7 && c1 <= 7)
        {
            if (chessBoard[r1][c1]->getColor() != chessBoard[newRow][newCol]->getColor() &&
                ((chessBoard[r1][c1]->getPieceType() == "K") ||
                 (chessBoard[r1][c1]->getPieceType() == "k")))
            {
                return true;
            }
        }
        else
        {
            int r2 = newRow + 1;
            int c2 = newCol - 1;
            if (r2 <= 7 && c2 >= 0)
            {
                if (chessBoard[r2][c2]->getColor() != chessBoard[newRow][newCol]->getColor() &&
                    ((chessBoard[r2][c2]->getPieceType() == "K") ||
                     (chessBoard[r2][c2]->getPieceType() == "k")))
                {
                    return true;
                }
            }
        }
    }
    else
        // if the pawn is white, it's moving up, should look for black pawns diagonally
        if (chessBoard[newRow][newCol]->getColor() == 1)
        {
            int r1 = newRow - 1;
            int c1 = newCol - 1;

            if (r1 >= 0 && c1 >= 0)
            {
                if (chessBoard[r1][c1]->getColor() != chessBoard[newRow][newCol]->getColor() &&
                    ((chessBoard[r1][c1]->getPieceType() == "K") ||
                     (chessBoard[r1][c1]->getPieceType() == "k")))
                {
                    return true;
                }
            }
            else
            {
                int r2 = newRow - 1;
                int c2 = newCol + 1;
                if (r2 >= 0 && c2 <= 7)
                {
                    if (chessBoard[r2][c2]->getColor() != chessBoard[newRow][newCol]->getColor() &&
                        ((chessBoard[r2][c2]->getPieceType() == "K") ||
                         (chessBoard[r2][c2]->getPieceType() == "k")))
                    {
                        return true;
                    }
                }
            }
        }

    return false;
}
