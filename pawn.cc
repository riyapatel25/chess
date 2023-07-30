#include <iostream>
#include <string>
#include "pawn.h"
using namespace std;

Pawn::Pawn(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}

bool Pawn::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  chessBoard) {

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return false;


};
bool Pawn::canPlayerKill (int row, int col) {
    return false;
}

