#include <iostream>
#include <string>
#include "queen.h"
#include "board.h"
using namespace std;

/* playerMove will contain the implementation for first checking if it is a valid move,
    and then it will make the change on the board.
*/

Queen::Queen(bool playerWhiteOrBlack, string name) : Piece{playerWhiteOrBlack, name} {}

bool Queen::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);

    // scenarios for a valid move
    if (row == newRow || col == newCol || rowDifference == columnDifference){
        // chessBoard.movePiece(row, col, newRow, newCol);
        return true;
    } else{
    cout << "Invalid move, try again" << endl;
    return false;
    }

}

bool Queen::canPlayerKill (int row, int col) {
    return false;
}


vector<Move> Queen::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) {
    vector<Move> validMoves;

    // The directions a queen can move (up, down, left, right, and diagonals)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Continue moving in the same direction until we find an invalid move
        while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if (!board[newRow][newCol]->playerMove(row, col, newRow, newCol, board)) {
                break;
            }

            validMoves.emplace_back(Move(row, col, newRow, newCol));

            if (board[newRow][newCol]->getName() != "Empty") {
                // If the destination square is occupied, we can't continue moving in this direction
                break;
            }

            newRow += dr[i];
            newCol += dc[i];
        }
    }

    return validMoves;
}
