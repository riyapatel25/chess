#include <iostream>
#include <string>
#include "king.h"
#include "board.h"
using namespace std;

King::King(bool playerWhiteOrBlack, string name) : Piece{playerWhiteOrBlack, name} {}


bool King::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;
    
    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move
    if((rowDifference == 1 && columnDifference == 0) || (rowDifference== 0 && columnDifference == 1)
     || (rowDifference ==1 && columnDifference ==1) ){
        // chessBoard.movePiece(row, col, newRow, newCol);
        return true;
    } else{

    cout << "Invalid move, try again" << endl;
        return false;
    }

}



bool King::canPlayerKill (int row, int col) {
    return false;
}

vector<Move> King::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) {
    vector<Move> validMoves;

    // The directions a king can move (up, down, left, right, and diagonals)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Check if the new position is within the bounds of the board
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            // Check if the new position is not occupied by a piece of the same color
            if (board[newRow][newCol]->getName() == "Empty") {
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            } else if (board[newRow][newCol]->getColor() != board[row][col]->getColor()) {
                // kill
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            }
        }
    }

    return validMoves;
}