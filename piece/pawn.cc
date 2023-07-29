#include <iostream>
#include <string>
#include "pawn.h"
using namespace std;

Pawn::Pawn(bool playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}

void Pawn::playerMove (int row, int col, int newRow, int newCol, Board& chessBoard) {

    if (!((newRow >= 0 && newRow < 8) && (newCol >=0 && newCol < 8)))
        return;


};
bool Pawn::canPlayerKill (int row, int col) {

};

