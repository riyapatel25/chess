#include <iostream>
#include <string>
#include "empty.h"
using namespace std;

Empty::Empty(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}

bool Empty::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard , bool turn){
    return false;
}
