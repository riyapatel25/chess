#include <iostream>
#include <string>
#include "horse.h"
#include "board.h"
using namespace std;

Horse::Horse(bool playerWhiteOrBlack, string name) : Piece{playerWhiteOrBlack, name} {}


bool Horse::playerMove(int row, int col, int newRow, int newCol, const Board &chessBoard)
{

    if (!((newRow >= 0 && newRow < 8) && (newCol >= 0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move, a Bishop only moves diagonally.
    if ((rowDifference == 1 && columnDifference == 2) ||
        (rowDifference == 2 && columnDifference == 1))
    {
        // chessBoard.movePiece(row, col, newRow, newCol);
        return true;
    }
    else{
        cout << "Invalid move, try again" << endl;
        return false;
    }
}
bool Horse::canPlayerKill(int row, int col){
    return false;
}


vector<Move> Horse::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) {
    vector<Move> validMoves;

    // Possible knight moves (relative row and column offsets)
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Check if the new position is within the board boundaries
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if (board[newRow][newCol]->getName() == "Empty" ){
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            } 
            else if (board[newRow][newCol]->getColor() != board[row][col]->getColor()) {
                // kill
                validMoves.emplace_back(Move(row, col, newRow, newCol));
            }
        }
    }

    return validMoves;
}
