#include <iostream>
#include <string>
#include "empty.h"
using namespace std;

Empty::Empty(int playerWhiteOrBlack) : Piece{playerWhiteOrBlack} {}

bool Empty::playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard){
    return false;
}
bool Empty::canPlayerKill (int row, int col) {
    return false;
}
