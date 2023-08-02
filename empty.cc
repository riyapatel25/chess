#include <iostream>
#include <string>
#include "empty.h"
using namespace std;

Empty::Empty(int playerWhiteOrBlack, string pieceType) : Piece{playerWhiteOrBlack, pieceType} {}

bool Empty::playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard , bool turn, bool vCheck){
    return false;
}

vector<Move> Empty::getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) {
    vector<Move> validMoves;
    return validMoves;
}

bool Empty::isCheck (int newRow, int newCol, const vector<vector<Piece*>>  chessBoard, int color){
    return false;
}
