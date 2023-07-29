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
    }

    void Board::setupBoard(bool defaultOrInput) {
    cout << "hi";
    if (defaultOrInput) {
        // // Create an 8x8 chessboard with empty spaces
        currBoard = vector<vector<Piece*>>(8, vector<Piece*>(8, nullptr));

        // // Initialize white pieces
        Rook* r1 = new Rook(true);
        currBoard[0].emplace_back(r1);
        // currBoard[0].push_back(new Horse(true));
        // currBoard[0].push_back(new Bishop(true));
        // currBoard[0].push_back(new Queen(true));
        // currBoard[0].push_back(new King(true));
        // currBoard[0].push_back(new Bishop(true));
        // currBoard[0].push_back(new Horse(true));
        // currBoard[0].push_back(new Rook(true));

        // for (int col = 0; col < 8; col++) {
        //     currBoard[1].push_back(new Pawn(true));
        // }

        // // Initialize black pieces
        // currBoard[7].push_back(new Rook(false));
        // currBoard[7].push_back(new Horse(false));
        // currBoard[7].push_back(new Bishop(false));
        // currBoard[7].push_back(new Queen(false));
        // currBoard[7].push_back(new King(false));
        // currBoard[7].push_back(new Bishop(false));
        // currBoard[7].push_back(new Horse(false));
        // currBoard[7].push_back(new Rook(false));

        // for (int col = 0; col < 8; col++) {
        //     currBoard[6].push_back(new Pawn(false));
        // }

        // // Fill the rest of the board with empty spaces
        // for (int row = 2; row < 6; row++) {
        //     for (int col = 0; col < 8; col++) {
        //         currBoard[row].push_back(new Empty(false));
        //     }
        // }

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
        // if(type1 == "human" && type2 == "human"){
        //     *player1 = new Human(1);
        //     *player2 = new Human(0);
        // } 
        // else if(type1 == "computer" && type2 == "computer"){
        //     *player1 = new Computer(1);
        //     *player2 = new Computer(0);
        // }
        // else if(type1 == "human" && type2 == "computer"){
        //     *player1 = new Human(1);
        //     *player2 = new Computer(0);
        // }
        // else if(type1 == "computer" && type2 == "human"){
        //     *player1 = new Computer(1);
        //     *player2 = new Human(0);
        // }
        // else{
        //     cerr << "not a valid type";
        // }
    

    //destructor
//     Board::~Board() {
//     // Implement destructor to delete dynamically allocated pieces
//     for (int i = 0; i < 8; i++) {
//         for (int j = 0; j < 8; j++) {
//             delete currBoard[i][j];
//         }
//     }
// }


//----big 5---//

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
        pair<char, char> start = make_pair(letterStart, numberStart);
        pair<char, char> end = make_pair(letterEnd, numberEnd);
        //find what the starting and ending coords are based on input (move e1 g1)
        pair <int,int> startCoord = getCoords(start);
        pair <int,int> endCoord = getCoords(end);
        // get whos turn
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

//  vector<vector<Piece*>>& Board::getPieces() const {
//     return currBoard;
// }

pair<int, int> Board::getCoords(pair<char, char>& coords) {
    int x1 = coords.first - 'a'; // Convert column letter to integer (0-7)
    int y1 = 8 - (coords.second - '0'); // Convert row number to integer (0-7)

    return make_pair(x1, y1);
}



// output operator
ostream& operator<<(ostream& os, const Board& chessBoard) {

    for (const auto& row : chessBoard.currBoard) {
        for (const auto& piece : row) {
            os << '|' << piece << '|';
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