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

Piece::Piece(int color, string pieceType) : color{color}, pieceType{pieceType} {}
Piece::~Piece() {}

// bool isCheckMate()
// {

//     // this part itself will give the king positions for both players
//     std::pair<int, int> whiteKingCords;
//     std::pair<int, int> blackKingCords;
//     for (int r = 0; r < 8; r++)
//     {
//         for (int c = 0; c < 8; c++)
//         {
//             if (chessBoard[r][c]->pieceType == "K")
//             {
//                 whiteKingCords.first = r;
//                 whiteKingCords.second = c;
//             }
//             else if (chessBoard[r][c]->pieceType == "k")
//             {
//                 blackKingCords.first = r;
//                 blackKingCords.second = c;
//             }
//         }
//     }




// }


// bool Piece::checkable(const vector<vector<Piece*>>& chessBoard) {

//     // this part itself will give the king positions for both players
//     std::pair<int, int> whiteKingCords;
//     std::pair<int, int> blackKingCords;
//     for (int r = 0; r < 8; r++)
//     {
//         for (int c = 0; c < 8; c++)
//         {
//             if (chessBoard[r][c]->pieceType == "K")
//             {
//                 whiteKingCords.first = r;
//                 whiteKingCords.second = c;
//             }
//             else if (chessBoard[r][c]->pieceType == "k")
//             {
//                 blackKingCords.first = r;
//                 blackKingCords.second = c;
//             }
//         }
//     }
//     cout << whiteKingCords.first << whiteKingCords.second << endl;
//     cout <<blackKingCords.first << blackKingCords.second << endl;

//     int opponentColor = 0; // for black opponent
//     // Check if any opponent's piece threatens the king's position
//     for (int row = 0; row < 8; row++) {
//         for (int col = 0; col < 8; col++) {
//             Piece* piece = chessBoard[row][col];
//             if (piece && piece->color == opponentColor) {
//                 if (piece->playerMove(row, col, whiteKingCords.first, whiteKingCords.second, chessBoard, false)) {
//                     // cout << "White is in check...." << endl;
//                     break;
//                 }
//                 else {
//                     // cout << "White is not in check..." << endl;
//                 }
//             }
//         }
//     }
//     opponentColor = 1; // for white opponent
//     for (int row = 0; row < 8; row++) {
//     for (int col = 0; col < 8; col++) {
//         Piece* piece = chessBoard[row][col];
//         if (piece && piece->color == opponentColor) {
//             cout << row << col << blackKingCords.first <<blackKingCords.second << endl;
//             if (piece->playerMove(row, col, blackKingCords.first, blackKingCords.second, chessBoard, false)) {
//                 cout << "Black is in check...." << endl;
//                 break;
//             } else {
//                     cout << "Black is not in check..." << endl;
//                 }
//         }
//     }
// }
// }
