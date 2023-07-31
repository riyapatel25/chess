#include <iostream>
#include <string>
#include "queen.h"
#include "board.h"
using namespace std;

/* playerMove will contain the implementation for first checking if it is a valid move,
    and then it will make the change on the board.
*/

Queen::Queen(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}

bool Queen::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn){

    if (chessBoard[row][col]->color != turn){
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
            if (chessBoard[checkRow][checkCol]->color != 2){
                return false;
            }
        } 
            if (chessBoard[newRow][newCol]->color == this->color){
            return false;
        }
        return true;
    }
    else {
        return false;
    }



}

// bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard) {

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
//         // this checks left
//     int r1 = newRow;
//     int c1 = newCol - 1;
    
//     while (c1>=0) {
//         if(chessBoard.getCurrBoard[r1][c1].color != this.color && 
//         ((chessBoard.getCurrBoard[r1][c1].name == 'K') || 
//         (chessBoard.getCurrBoard[r1][c1].name == 'k'))) {
//             return true;
//         }
//         c1-=1;
//     }

//     // this checks right
//     int r2 = newRow;
//     int c2 = newCol + 1;    
//     while (c2<=7) {
//         if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
//         ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
//         (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
//             return true;
//         }
//         c2+=1;
//     }

//     // this checks down
//     int r3 = newRow + 1;
//     int c3 = newCol;    
//     while (r3<=7) {
//         if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
//         ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
//         (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
//             return true;
//         }
//         r3+=1;
//     }

//     // this checks up
//     int r4 = newRow - 1;
//     int c4 = newCol;    
//     while (r4 >=0) {
//         if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
//         ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
//         (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
//             return true;
//         }
//         r4-=1;
//     }


//     return false;
// }