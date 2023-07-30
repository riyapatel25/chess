#include <iostream>
#include <string>
#include "bishop.h"
#include "board.h"
using namespace std;

Bishop::Bishop(bool playerWhiteOrBlack, string name) : Piece{playerWhiteOrBlack, name} {}

bool Bishop::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    /*
    scenarios for a valid move, a Bishop only moves diagonally, and therefore, 
    both row and column should either increase or decrease by the same value.
   */
    if( rowDifference == columnDifference){
        // chessBoard.movePiece(row, col, newRow, newCol);
        return true;
    } else{
    cout << "Invalid move, try again" << endl;
    return false;
    }

}
bool Bishop::canPlayerKill (int row, int col) {
    return false;
}

vector<Move> Bishop::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) {
    vector<Move> validMoves;

    // The directions a bishop can move (diagonals)
    int dr[] = {-1, -1, 1, 1};
    int dc[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; ++i) {
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
