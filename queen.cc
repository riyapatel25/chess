#include <iostream>
#include <string>
#include "queen.h"
#include "board.h"
using namespace std;

/* playerMove will contain the implementation for first checking if it is a valid move,
    and then it will make the change on the board.
*/

Queen::Queen(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}

bool Queen::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn, bool vCheck){

    if (chessBoard[row][col]->getColor() != turn){
        return false;
    }

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8))){
        return false;
    }

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);

    // scenarios for a valid move (can move )
    if (row == newRow || col == newCol || rowDifference == columnDifference){
        int rowStep = (newRow > row) ? 1 : ((newRow < row) ? -1 : 0); // Direction to move vertically
        int colStep = (newCol > col) ? 1 : ((newCol < col) ? -1 : 0); // Direction to move horizontally
        int steps = max(rowDifference, columnDifference);

        for (int i = 1; i < steps; i++) {
            // Check each cell along the path
            int checkRow = row + i * rowStep;
            int checkCol = col + i * colStep;

            // Check if there's a piece in the cell
            if (chessBoard[checkRow][checkCol]->getColor() != 2){
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
    else {
        return false;
    }



}



vector<Move> Queen::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;
    bool vCheck = true;
    // The directions a queen can move (up, down, left, right, and diagonals)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
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

bool Queen::isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color) {

    int r1 = newRow - 1;
    int c1 = newCol - 1;
    // this checks a diagonal
    // the else condition checks to see if there's a piece blocking its path that is not a king, then not
    // checkable for this particular direction

    while (r1>=0 && c1>=0) {
        if(chessBoard[r1][c1]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r1][c1]->getPieceType() == "K") || 
        (chessBoard[r1][c1]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r1][c1]->getPieceType() != " ") {
            break;
        }
        r1-=1;
        c1-=1;
    }

    int r2 = newRow + 1;
    int c2 = newCol + 1;    
    while (r2<=7 && c2<=7) {
        if(chessBoard[r2][c2]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r2][c2]->getPieceType() == "K") || 
        (chessBoard[r2][c2]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r2][c2]->getPieceType() != " ") {
            break;
        }
        r2+=1;
        c2+=1;
    }

    int r3 = newRow + 1;
    int c3 = newCol - 1;    
    while (r3<=7 && c3>=0) {
        if(chessBoard[r3][c3]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r3][c3]->getPieceType() == "K") || 
        (chessBoard[r3][c3]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r3][c3]->getPieceType() != " ") {
            break;
        }
        r3+=1;
        c3-=1;
    }


    int r4 = newRow - 1;
    int c4 = newCol + 1;    
    while (r4>=0 && c4<=7) {
        if(chessBoard[r4][c4]->getColor() !=  chessBoard[newRow][newCol]->getColor() && 
            ((chessBoard[r4][c4]->getPieceType() == "K") || 
            (chessBoard[r4][c4]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r4][c4]->getPieceType() != " ") {
            break;
        }
        r4-=1;
        c4+=1;
    }
    // this checks left
    r1 = newRow;
    c1 = newCol - 1;
    
    while (c1>=0) {
        if(chessBoard[r1][c1]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r1][c1]->getPieceType() == "K") || 
        (chessBoard[r1][c1]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r1][c1]->getPieceType() != " ") {
            break;
        }
        c1-=1;
    }

    // this checks right
     r2 = newRow;
     c2 = newCol + 1;  
    while (c2<=7) {
        if(chessBoard[r2][c2]->getColor() != chessBoard[newRow][newCol]->getColor() &&
        ((chessBoard[r2][c2]->getPieceType() == "K") || 
        (chessBoard[r2][c2]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r2][c2]->getPieceType() != " ") {
            break;
        }
        c2+=1;
    }

    // this checks down
     r3 = newRow + 1;
     c3 = newCol;    
    while (r3<=7) {
        if(chessBoard[r3][c3]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r3][c3]->getPieceType() == "K") || 
        (chessBoard[r3][c3]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r3][c3]->getPieceType() != " ") {
            break;
        }
        r3+=1;
    }

    // this checks up
     r4 = newRow - 1;
     c4 = newCol;    
    while (r4 >= 0) {
        if(chessBoard[r4][c4]->getColor() != chessBoard[newRow][newCol]->getColor() && 
        ((chessBoard[r4][c4]->getPieceType() == "K") || 
        (chessBoard[r4][c4]->getPieceType() == "k"))) {
            return true;
        } else 
        if (chessBoard[r4][c4]->getPieceType() != " ") {
            break;
        }
        r4-=1;
    }

    return false;
}
