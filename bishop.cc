#include <iostream>
#include <string>
#include "bishop.h"
#include "board.h"
using namespace std;

Bishop::Bishop(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}
bool Bishop::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn, bool vCheck){

    if (chessBoard[row][col]->color != turn){
        return false;
    }

    // check if new position is within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    /*
    scenarios for a valid move, a Bishop only moves diagonally, and therefore, 
    both row and column should either increase or decrease by the same value.
   */
    if (rowDifference == columnDifference) {
        // here must be checking if no piece of its own obstructs the path.
        int rowStep = (newRow > row) ? 1 : -1; // Direction to move vertically
        int colStep = (newCol > col) ? 1 : -1; // Direction to move horizontally

        for (int i = 1; i < rowDifference; i++) {
            // Check each cell along the diagonal path (excluding the starting and target cells)
            int checkRow = row + i * rowStep;
            int checkCol = col + i * colStep;

            // Check if there's a piece in the cell
            if (chessBoard[checkRow][checkCol]->color != 2) {
                return false;
            }
        }

        if (chessBoard[newRow][newCol]->color == this->color){
            return false;
        }
        // isCheck is here, because the piece is playable, so check for the opponent's.
        // the last parameter here is redundant.
        if(isCheck(newRow, newCol, chessBoard, chessBoard[newRow][newCol]->color) && vCheck!= true){
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



vector<Move> Bishop::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;
    bool vCheck = true;
    // The directions a bishop can move (diagonals)
    int dr[] = {-1, -1, 1, 1};
    int dc[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Continue moving in the same direction until we find an invalid move
        while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn, vCheck)) {
                break;
            }

            validMoves.emplace_back(Move(row, col, newRow, newCol));

            if (board[newRow][newCol]->pieceType != " ") {
                // If the destination square is occupied, we can't continue moving in this direction
                break;
            }

            newRow += dr[i];
            newCol += dc[i];
        }
    }

    return validMoves;
}


bool Bishop::isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) {

    int r1 = newRow - 1;
    int c1 = newCol - 1;
    
    // Based on our grid, this checks positions to the south-west of the currently placed bishop.
    // If the color doesn't match, only then does it proceed to checking the other "and" condition, and 
    // we already know that the colors are different, so only one of the "or" conditions for the kings will pass.

    while (r1>=0 && c1>=0) {
        if(chessBoard[r1][c1]->color != chessBoard[newRow][newCol]->color && 
        ((chessBoard[r1][c1]->pieceType == "K") || 
        (chessBoard[r1][c1]->pieceType == "k"))) {
            return true;
        } else 
        if (chessBoard[r1][c1]->pieceType != " ") {
            break;
        }
        r1-=1;
        c1-=1;
    }

    // this checks positions to the north-east of the currently placed bishop.
    int r2 = newRow + 1;
    int c2 = newCol + 1;    
    while (r2<=7 && c2<=7) {
        if(chessBoard[r2][c2]->color !=  chessBoard[newRow][newCol]->color && 
        ((chessBoard[r2][c2]->pieceType == "K") || 
        (chessBoard[r2][c2]->pieceType == "k"))) {
            return true;
        }
         else 
        if (chessBoard[r2][c2]->pieceType != " ") {
            break;
        }
        r2+=1;
        c2+=1;
    }

    // this checks positions to the north-west of the currently placed bishop.

    int r3 = newRow + 1;
    int c3 = newCol - 1;    
    while (r3<=7 && c3>=0) {
        if(chessBoard[r3][c3]->color !=  chessBoard[newRow][newCol]->color && 
        ((chessBoard[r3][c3]->pieceType == "K") || 
        (chessBoard[r3][c3]->pieceType == "k"))) {
            return true;
        }  else 
        if (chessBoard[r3][c3]->pieceType != " ") {
            break;
        }
        r3+=1;
        c3-=1;
    }

    // this checks positions to the south-east of the currently placed bishop.

    int r4 = newRow - 1;
    int c4 = newCol + 1;    
    while (r4>=0 && c4<=7) {
        if(chessBoard[r4][c4]->color !=  chessBoard[newRow][newCol]->color && 
            ((chessBoard[r4][c4]->pieceType == "K") || 
            (chessBoard[r4][c4]->pieceType == "k"))) {
            return true;
        }  else 
        if (chessBoard[r4][c4]->pieceType != " ") {
            break;
        }
        r4-=1;
        c4+=1;
    }

    return false;
}

