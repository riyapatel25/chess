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
#include "empty.h"

using namespace std;

//----big 5---//
    //constructor
    Board::Board(type1: string, type2: string, isDefault: bool, setupString: string) { // type1
    setupBoard(isDefault: bool);
    turn = true; //white is true
    whiteWins = 0
    blackWins = 0
    initPlayer("human") //take in type1
    initPlayer("human") //take in type2
    this.currScore = new Score();
    }

    void Board::setupBoard(bool defaultOrInput, Board& board){

    if(defaultOrInput){
        // Create an 8x8 chessboard with empty spaces
        board.currBoard = vector<vector<Piece*>>(8, vector<Piece*>(8, nullptr));

        // Initialize white pieces
        currBoard[0][0] = new Rook(true);
        currBoard[0][1] = new Knight(true);
        currBoard[0][2] = new Bishop(true);
        currBoard[0][3] = new Queen(true);
        currBoard[0][4] = new King(true);
        currBoard[0][5] = new Bishop(true);
        currBoard[0][6] = new Knight(true);
        currBoard[0][7] = new Rook(true);

        for (int col = 0; col < 8; col++) {
            pieces[1][col] = new Pawn(true);
        }

        // Initialize black pieces
        currBoard[7][0] = new Rook(false);
        currBoard[7][1] = new Knight(false);
        currBoard[7][2] = new Bishop(false);
        currBoard[7][3] = new Queen(false);
        currBoard[7][4] = new King(false);
        currBoard[7][5] = new Bishop(false);
        currBoard[7][6] = new Knight(false);
        currBoard[7][7] = new Rook(false);

        for (int col = 0; col < 8; col++) {
            currBoard[6][col] = new Pawn(false);
        }

        // Fill the rest of the board with empty spaces
        for (int row = 2; row < 6; row++) {
            for (int col = 0; col < 8; col++) {
                currBoard[row][col] = new EmptySpace();
            }
        }

    }
    else{
        //manual board input
        cout << "not implemented yet";
    }
        
    }

    initPlayer(type1: string, type2: string){
        if(type1 == "human" && type2 == "human"){
            this.player1 = new Human(1);
            this.player2 = new Human(0);
        } 
        else if(type1 == "computer" && type2 == "computer"){
            this.player1 = new Computer(1);
            this.player2 = new Computer(0);
        }
        else if(type1 == "human" && type2 == "computer"){
            this.player1 = new Human(1);
            this.player2 = new Computer(0);
        }
        else if(type1 == "computer" && type2 == "human"){
            this.player1 = new Computer(1);
            this.player2 = new Human(0);
        }
        else{
            cerr << "not a valid type";
        }
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
    void Board::play(input: string){

        
          //find what the starting and ending coords are based on input (move e1 g1)
          pair <int,int> startCoord;
          pair <int,int> endCoord;

        //whos turn



    }
    bool Board::isTaken(row: int, col: int){
          return 0;
    }
    void Board::displayErrorHnadling(message: string){
          return 0;
    }
  

//the board contains exactly one white king and exactly one black king; 
//that no pawns are on the first or last row of the board
//and that neither king is in check
    bool isConfigurationValid(board: &Board const){
        return 0;
    }

const vector<vector<Piece*>>& Board::getPieces() const {
    return currBoard;
}


