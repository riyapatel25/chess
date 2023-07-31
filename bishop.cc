#include <iostream>
#include <string>
#include "bishop.h"
#include "board.h"
using namespace std;

<<<<<<< HEAD
Bishop::Bishop(bool playerWhiteOrBlack, string name) : Piece{playerWhiteOrBlack, name} {}
=======
Bishop::Bishop(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}
bool Bishop::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn){
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2

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
        return true;
    } 
    else 
    {
        return false;
    }
}


vector<Move> Bishop::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;

    // The directions a bishop can move (diagonals)
    int dr[] = {-1, -1, 1, 1};
    int dc[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Continue moving in the same direction until we find an invalid move
        while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn)) {
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

<<<<<<< HEAD
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
=======

// bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard, int color) {

//     int r1 = newRow - 1;
//     int c1 = newCol - 1;
    
//     while (r1>=0 && c1>=0) {
//         if(chessBoard.getCurrBoard[r1][c1].color != this.color && 
//         ((chessBoard.getCurrBoard[r1][c1].name == 'K') || 
//         (chessBoard.getCurrBoard[r1][c1].name == 'k'))) {
//             return true;
//         }
//         r1-=1;
//         c1-=1;
//     }

//     int r2 = newRow + 1;
//     int c2 = newCol + 1;    
//     while (r2<=7 && c2<=7) {
//         if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
//         ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
//         (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
//             return true;
//         }
//         r2+=1;
//         c2+=1;
//     }

//     int r3 = newRow + 1;
//     int c3 = newCol - 1;    
//     while (r3<=7 && c3>=0) {
//         if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
//         ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
//         (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
//             return true;
//         }
//         r3+=1;
//         c3+-1;
//     }


//     int r4 = newRow - 1;
//     int c4 = newCol + 1;    
//     while (r4>=0 && c4>=7) {
//         if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
//             ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
//             (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
//             return true;
//         }
//         r4-=1;
//         c4+=1;
//     }

//     return false;
// }
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
