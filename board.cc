#include <iostream>
#include <string>
#include "board.h"
#include "piece.h"
#include "emptyspace.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

using namespace std;

//----big 5---//
    //constructor
    Board::Board() {
    setupBoard();
    turn = true; //white is true
    whiteWins = 0
    blackWins = 0
    }
    //destructor
    Board::~Board() {
    // Implement destructor to delete dynamically allocated pieces
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete pieces[i][j];
        }
    }
}
//----big 5---//

    vector<vector<Piece>> Board::getPieces(){
        return pieces;
    }
    bool Board::isCheckmate(turn: bool){
          return 0;
    }
    bool Board::getTurn(){
          return this->turn;
    }
    void Board::setPiece(row: int, col: int){
          return 0;
    }
    void Board::setTurn(turn: bool){

    }
    void Board::Play(input: string){
          return 0;
    }
    bool Board::isTaken(row: int, col: int){
          return 0;
    }
    void Board::displayErrorHnadling(message: string){
          return 0;
    }
    void Board::setupBoard(){
          return 0;
    }

//the board contains exactly one white king and exactly one black king; 
//that no pawns are on the first or last row of the board
//and that neither king is in check
    bool isConfigurationValid(board: &Board const){
        return 0;
    }


