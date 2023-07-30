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

Piece::Piece(bool color, string name) : color{color}, name{name} {}
bool isCheck (int row, int col, int newRow, int newCol) {};
int Piece::getColor(){
    return color;
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

bool Piece::isAttacked(int row, int col, int currMove) {

    // Get the opponent's color
    bool opponentColor = !currMove;

    // Iterate through the board to find the opponent's pieces
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece* currentPiece = currBoard[r][c];

            // Check if there is a piece on the current square and if it belongs to the opponent
            if (currentPiece->getColor() == opponentColor) {
                // Generate all possible moves for the current piece
                std::vector<Move> pieceValidMoves = currentPiece->getValidMovesForPiece(*this, r, c);

                // Check if any of the valid moves target the specified square
                for (const Move& move : pieceValidMoves) {
                    if (move.getEndRow() == row && move.getEndCol() == col) {
                        return true; // The square is being attacked by the opponent's piece
                    }
                }
            }
        }
    }

    return false;

}
