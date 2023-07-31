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
Piece::~Piece() {}

