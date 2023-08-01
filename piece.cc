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
