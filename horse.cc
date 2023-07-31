#include <iostream>
#include <string>
#include "horse.h"
#include "board.h"
using namespace std;

Horse::Horse(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}


bool Horse::playerMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn)
{
     if (chessBoard[row][col]->color != turn){
        cout << "cook4"<<endl;
            return false;
        
     }

     if (chessBoard[newRow][newCol]->color == this->color){
        cout << "cook1"<<endl;
        cout << "color: " << this->color<<endl;

            return false;
        }

    // check if it is within bounds.
    if (!((newRow >= 0 && newRow < 8) && (newCol >= 0 && newCol < 8))){
        cout << "cook3"<<endl;
        
        return false;
    }

    int rowDifference = abs(newRow - row);
    int columnDifference = abs(newCol - col);
    // scenarios for a valid move, a Bishop only moves diagonally.
    if ((rowDifference == 1 && columnDifference == 2) ||
        (rowDifference == 2 && columnDifference == 1))
    {
        return true;
    }
    else{
        cout << "cook2"<<endl;
        return false;
    }
}


vector<Move> Horse::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;

    // Possible knight moves (relative row and column offsets)
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Check if the new position is within the board boundaries
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if (board[newRow][newCol]->pieceType == " " ){
                if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn)) {
                    break;
                } else {
                    validMoves.emplace_back(Move(row, col, newRow, newCol));
                }
            } 
            else if (board[newRow][newCol]->color != board[row][col]->color) {
                // kill
                if (!board[row][col]->playerMove(row, col, newRow, newCol, board, turn)) {
                    break;
                } else {
                    validMoves.emplace_back(Move(row, col, newRow, newCol));
                }            
            }
        }
    }

    return validMoves;
}


// bool isCheck (int row, int col, int newRow, int newCol, const Board& chessBoard) {

//     // this checks up-left
//     int r1 = newRow - 2;
//     int c1 = newCol - 1;
    
//     if (r1>=0 && (c1>=0 && c1<=7)) {
//         if(chessBoard.getCurrBoard[r1][c1].color != this.color && 
//         ((chessBoard.getCurrBoard[r1][c1].name == 'K') || 
//         (chessBoard.getCurrBoard[r1][c1].name == 'k'))) {
//             return true;
//         }
//     }

//     //  up-right
//     int r2 = newRow - 2;
//     int c2 = newCol + 1;
    
//     if (r2>=0 && (c2>=0 && c2<=7)) {
//         if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
//         ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
//         (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
//             return true;
//         }
//     }

//     // this checks down-left, down-right
//     int r2 = newRow + 2;
//     int c2 = newCol - 1;    
//     if (r2<=7 && (c2>=0 && c2<=7)) {
//         if(chessBoard.getCurrBoard[r2][c2].color != this.color && 
//         ((chessBoard.getCurrBoard[r2][c2].name == 'K') || 
//         (chessBoard.getCurrBoard[r2][c2].name == 'k'))) {
//             return true;
//         }
//         c2+=2;
//     }

//     int r3 = newRow + 2;
//     int c3 = newCol - 1;    
//     if (r3<=7 && (c3>=0 && c3<=7)) {
//         if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
//         ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
//         (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
//             return true;
//         }
//         c2+=2;
//     }

//     // this checks left-down, left-up
//     int r3 = newRow - 1;
//     int c3 = newCol - 2;
//     if ((r3>=0 && r3<=7) && c3>=0) {
//         if(chessBoard.getCurrBoard[r3][c3].color != this.color && 
//         ((chessBoard.getCurrBoard[r3][c3].name == 'K') || 
//         (chessBoard.getCurrBoard[r3][c3].name == 'k'))) {
//             return true;
//         }
//         r3+=2;
//     }

//     // this checks right-down, right-up
//     int r4 = newRow - 1;
//     int c4 = newCol + 2;    
//     if (r4>=0 && c4>=7) {
//         if(chessBoard.getCurrBoard[r4][c4].color != this.color && 
//             ((chessBoard.getCurrBoard[r4][c4].name == 'K') || 
//             (chessBoard.getCurrBoard[r4][c4].name == 'k'))) {
//             return true;
//         }
//         r4+=2;
//     }
//     return false;
// }