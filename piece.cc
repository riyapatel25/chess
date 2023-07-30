#include <iostream>
#include <string>
#include "piece.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include "horse.h"
#include "pawn.h"
#include "empty.h"
#include "bishop.h"
#include "board.h"

using namespace std;

Piece::Piece(int color, string pieceType ) : color{color}, pieceType{pieceType} {}
bool isCheck (int row, int col, int newRow, int newCol) {};
Piece::~Piece() {
}
// bool getPlayerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) {

//     /*
//     Here,
//     based on the piece type at the board position, call the respective piece type.
//     Also, need to split commands like E8 so that E->5, since that is the column number.
//     */
//      *chessBoard[row][col].playerMove(row, col, newRow, newCol, chessBoard);
// //    if(chessBoard[row][col].pieceName == "Queen") {
// //     *chessBoard[row][col].playerMove(row, col, newRow, newCol, chessBoard);
// //    }
// //     else if (chessBoard[row][col].pieceName == "Rook") {
// //         *chessBoard[row][col].playerMove(row, col, newRow, newCol, chessBoard); 
// //     } 
// //     else if (chessBoard[row][col].pieceName == "Bishop") {
// //         *chessBoard[row][col].playerMove(row, col, newRow, newCol, chessBoard); 
// //     }
// //     else if (chessBoard[row][col].pieceName == "King") {
// //         *chessBoard[row][col].playerMove(row, col, newRow, newCol, chessBoard); 
// //     }
// //     else if (chessBoard[row][col].pieceName == "Pawn") {
// //         *chessBoard[row][col].playerMove(row, col, newRow, newCol, chessBoard); 
// //     }
// //     else if (chessBoard[row][col].pieceName == "Horse") {
// //         *chessBoard[row][col].playerMove(row, col, newRow, newCol, chessBoard); 
// //     }
// //         else if (chessBoard[row][col].pieceName == "Empty") {
// //         Empty empty; 
// //         empty.playerMove(row, col, newRow, newCol, chessBoard); 
// //     }


// }