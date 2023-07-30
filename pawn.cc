#include <iostream>
#include <string>
#include "pawn.h"
using namespace std;

Pawn::Pawn(bool playerWhiteOrBlack, string name) : Piece{playerWhiteOrBlack, name} {}

bool Pawn::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) {

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;


};
bool Pawn::canPlayerKill (int row, int col) {
    return false;
}

vector<Move> Pawn::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) {
    vector<Move> validMoves;
    Piece* pawn = board[row][col];
    bool isWhite = pawn->getColor(); // returns 1 if white

    // Define the direction the pawn moves based on its color
    int direction = (isWhite) ? -1 : 1;

    // Check if the square in front of the pawn is empty
    int newRow = row + direction;
    int newCol = col;
    if (newRow >= 0 && newRow < 8 && !board.isTaken(newRow, newCol)) {
        validMoves.emplace_back(Move(row, col, newRow, newCol));


        // If it is the pawn's first move, it can move two squares forward
        // Only works for default board right now
        if ((isWhite && row == 1) || (!isWhite && row == 6)) {
            newRow += direction;
            if (newRow >= 0 && newRow < 8 && !board.isTaken(newRow, newCol)) {
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            }
        }
    }

    // Check if the pawn can capture diagonally
    int captureCols[] = {col - 1, col + 1};
    for (int i = 0; i < 2; i++) {
        newCol = captureCols[i];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            Piece* targetPiece = board[newRow][newCol];
            if (targetPiece && targetPiece->getColor() != isWhite) {
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            }
        }
    }

    return validMoves;
}

