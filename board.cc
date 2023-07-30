#include <iostream>
#include <string>
#include "board.h"
#include "player.h"
#include "piece.h"
#include "empty.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "horse.h"
#include "rook.h"
#include "pawn.h"
#include "human.h"
#include "computer.h"

class Piece;
using namespace std;

//----big 5---//
    //constructor
    Board::Board(string type1, string type2, bool isDefault, string setupString) { // type1
    setupBoard(isDefault);
    turn = true; //white is true
    initPlayers("human", "human"); //take in type1/type2
    whiteWins = 0;
    blackWins = 0;
    // player1 = new Human(1); // Create a new Human object and assign it to player1
    // player2 = new Human(0);
    currScore = new Score();
    hasWon = false;
    }

    void Board::setupBoard(bool defaultOrInput) {

    if (defaultOrInput) {
        //Create an 8x8 chessboard with empty spaces
        currBoard = vector<vector<Piece*>>(8, vector<Piece*>(8, nullptr));

        // (8, vector<Piece*>(8, nullptr));

        // Initialize white pieces
        Rook* r1 = new Rook(true, "R");
        currBoard[0][0] = r1;

        Horse* h1 = new Horse(true, "H");
        currBoard[0][1] = h1;

        Bishop* b1 = new Bishop(true, "B");
        currBoard[0][2] = b1;

        Queen* q1 = new Queen(true, "Q");
        currBoard[0][3] = q1;

        King* k1 = new King(true, "K");
        currBoard[0][4] = k1;

        Bishop* b2 = new Bishop(true, "B");
        currBoard[0][5] = b2;

        Horse* h2 = new Horse(true, "H");
        currBoard[0][6] = h2;

        Rook* r2 = new Rook(true, "R");
        currBoard[0][7] = r2;


        for (int col = 0; col < 8; col++) {
            Pawn* p = new Pawn(true, "P");
            currBoard[1][col] = p;
        }

        // // Initialize black pieces
        Rook* r3 = new Rook(false, "R");
        currBoard[7][0] = r3;


        Horse* h3 = new Horse(false, "H");
        currBoard[7][1] = h3;


        Bishop* b3 = new Bishop(false, "B");
        currBoard[7][2] = b3;

        Queen* q3 = new Queen(false, "Q");
        currBoard[7][3] = q3;

        King* k3 = new King(false, "K");
        currBoard[7][4] = k3;
        
        Bishop* b4 = new Bishop(false, "B");
        currBoard[7][5] = b4;

        Horse* h4 = new Horse(false, "H");
        currBoard[7][6] = h4;

        Rook* r4 = new Rook(false, "R");
        currBoard[7][7] = r4;

        for (int col = 0; col < 8; col++) {
            Pawn* p = new Pawn(false, "P");
            currBoard[6][col] = p;
        }
       
        // // Fill the rest of the board with empty spaces
        for (int row = 2; row < 6; row++) {
            for (int col = 0; col < 8; col++) {
                Empty* e = new Empty(false, " ");
                currBoard[row][col] = e;
            }
        }

    } else {
        // manual board input
        cout << "not implemented yet";
    }
        
    }

     void Board::initPlayers(string type1, string type2){
    if (type1 == "human" && type2 == "human") {
        player1 = new Human(1); // Create a new Human object and assign it to player1
        player2 = new Human(0); // Create a new Human object and assign it to player2
    } else if (type1 == "computer" && type2 == "computer") {
        player1 = new Computer(1); // Create a new Computer object and assign it to player1
        player2 = new Computer(0); // Create a new Computer object and assign it to player2
    } else if (type1 == "human" && type2 == "computer") {
        player1 = new Human(1); // Create a new Human object and assign it to player1
        player2 = new Computer(0); // Create a new Computer object and assign it to player2
    } else if (type1 == "computer" && type2 == "human") {
        player1 = new Computer(1); // Create a new Computer object and assign it to player1
        player2 = new Human(0); // Create a new Human object and assign it to player2
    } else {
        cerr << "not a valid type";
    }
     }


 
//----big 5---//


//     Board::~Board() {
//     // Implement destructor to delete dynamically allocated pieces
//     for (int i = 0; i < 8; i++) {
//         for (int j = 0; j < 8; j++) {
//             delete currBoard[i][j];
//         }
//     }
// }

    vector<vector<Piece*>> Board::getCurrBoard() const {
        return currBoard;
    }

    bool Board::isCheckmate(bool turn){
          return 0;
    }
    bool Board::getTurn(){
          return this->turn;
    }
    void Board::setPiece(int row, int col){
          return;
    }
    void Board::setTurn(bool turn){
        this->turn = turn;
    }
    void Board::play(char letterStart, char numberStart, char letterEnd, char numberEnd){
        cout << "Entered play function:" << endl;
        cout << letterStart << numberStart << " " << letterEnd << numberEnd <<endl;
        pair<char, char> start = make_pair(letterStart, numberStart);
        pair<char, char> end = make_pair(letterEnd, numberEnd);
        //find what the starting and ending coords are based on input (move e1 g1)
        pair <int,int> startCoord = getCoords(start);
        pair <int,int> endCoord = getCoords(end);

        // get whos turn
        if(turn) { //white
            bool isValid = (*player1).makeMove(startCoord.first, startCoord.second, endCoord.first, endCoord.second, currBoard);
            // if(isValid){
                cout << "start"<< endl;
                cout << startCoord.first<<endl;
                cout << startCoord.second<<endl;
                cout << "end"<< endl;
                cout << endCoord.first<<endl;
                cout << endCoord.second<<endl;
                //actually move the piece from starting to ending coordinates
                Piece* pieceToMove = currBoard[startCoord.first][startCoord.second];
                currBoard[startCoord.first][startCoord.second] = new Empty(false, " "); // Replace starting position with Empty
                currBoard[endCoord.first][endCoord.second] = pieceToMove; // Place the selected piece in the ending position
                setTurn(false);
    
            // }
        }
        else {  //black
        bool isValid = (*player2).makeMove(startCoord.first, startCoord.second, endCoord.first, endCoord.second, currBoard);
            if(isValid){
                //actually move 
                Piece* pieceToMove = currBoard[startCoord.second][startCoord.first];
                currBoard[startCoord.second][startCoord.first] = new Empty(false, " "); // Replace starting position with Empty
                currBoard[endCoord.second][endCoord.first] = pieceToMove; // Place the selected piece in the ending position
                setTurn(true);
                // cout << currBoard;
            }
        }

        //call makeMove on piece 
    }
    bool Board::isTaken(int row, int col){
          return 0;
    }
    void Board::displayErrorHandling(string message){
          return;
    }
  

//the board contains exactly one white king and exactly one black king; 
//that no pawns are on the first or last row of the board
//and that neither king is in check
    bool Board::isConfigurationValid(){
        return 0;
    }

pair<int, int> Board::getCoords(pair<char, char>& coords) {
    int x1 = coords.first - 'a'; // Convert column letter to integer (0-7)
    int y1 = (coords.second - '0') -1; // Convert row number to integer (0-7)

    return make_pair(x1, y1);
}



// output operator

ostream& operator<<(ostream& os, const Board& chessBoard) {
   
    for (int i = 0; i < chessBoard.currBoard.size(); i++) {
        for (int j = 0; j < chessBoard.currBoard[i].size(); j++) {
       
            os << '|' << (*(chessBoard.currBoard[i][j])).pieceType << '|'; // Print the piece letter if it exists
        }
        os << '\n';
    }
    return os;
}



   void Board::enterSetupMode(){
    cout << "enterSetupMode";
   }
  void Board::processSetupCommand(string input){
    cout << "processSetupCommand";
    }

    bool Board::getHasWon(){
        return hasWon;
    }