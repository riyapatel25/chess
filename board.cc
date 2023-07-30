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
    Board::Board(string type1, string type2) {
    setupBoard();
    turn = true; //white is true
    initPlayers("human", "human"); //take in type1 and type2
    whiteWins = 0;
    blackWins = 0;
    // player1 = new Human(1); // Create a new Human object and assign it to player1
    // player2 = new Human(0);
    currScore = new Score();
    hasWon = false;
    }

    void Board::setupBoard() {


        //Create an 8x8 chessboard with empty spaces
        currBoard = vector<vector<Piece*>>(8, vector<Piece*>(8, nullptr));

        // Initialize white pieces
        Rook* r1 = new Rook(1, "R");
        currBoard[7][0] = r1;

        Horse* h1 = new Horse(1, "H");
        currBoard[7][1] = h1;

        Bishop* b1 = new Bishop(1, "B");
        currBoard[7][2] = b1;

        Queen* q1 = new Queen(1, "Q");
        currBoard[7][3] = q1;

        King* k1 = new King(1, "K");
        currBoard[7][4] = k1;

        Bishop* b2 = new Bishop(1, "B");
        currBoard[7][5] = b2;

        Horse* h2 = new Horse(1, "H");
        currBoard[7][6] = h2;

        Rook* r2 = new Rook(1, "R");
        currBoard[7][7] = r2;


        for (int col = 0; col < 8; col++) {
            Pawn* p = new Pawn(1, "P");
            currBoard[6][col] = p;
        }

        // // Initialize black pieces
        Rook* r3 = new Rook(0, "r");
        currBoard[0][0] = r3;


        Horse* h3 = new Horse(0, "h");
        currBoard[0][1] = h3;


        Bishop* b3 = new Bishop(0, "b");
        currBoard[0][2] = b3;

        Queen* q3 = new Queen(0, "q");
        currBoard[0][3] = q3;

        King* k3 = new King(0, "k");
        currBoard[0][4] = k3;
        
        Bishop* b4 = new Bishop(0, "b");
        currBoard[0][5] = b4;

        Horse* h4 = new Horse(0, "h");
        currBoard[0][6] = h4;

        Rook* r4 = new Rook(0, "r");
        currBoard[0][7] = r4;

        for (int col = 0; col < 8; col++) {
            Pawn* p = new Pawn(0, "p");
            currBoard[1][col] = p;
        }
       
        // // Fill the rest of the board with empty spaces
        for (int row = 2; row < 6; row++) {
            for (int col = 0; col < 8; col++) {
                Empty* e = new Empty(2, " ");
                currBoard[row][col] = e;
            }
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
        cout <<"turn: " << turn << endl;
        // get whos turn
        if(turn) { //white
            bool isValid = (*player1).makeMove(startCoord.first, startCoord.second, endCoord.first, endCoord.second, currBoard);
            if(true){
                //actually move the piece from starting to ending coordinates
                Piece* pieceToMove = currBoard[startCoord.first][startCoord.second];
                currBoard[startCoord.first][startCoord.second] = new Empty(false, " "); // Replace starting position with Empty
                currBoard[endCoord.first][endCoord.second] = pieceToMove; // Place the selected piece in the ending position     
    
            }
            else{
                setTurn(false);
                cout << "Not a valid move, try again white player!" << endl;
            }
        }
        else {  //black
        bool isValid = (*player2).makeMove(startCoord.first, startCoord.second, endCoord.first, endCoord.second, currBoard);
            if(true){ 
                //actually move 
                Piece* pieceToMove = currBoard[startCoord.first][startCoord.second];
                currBoard[startCoord.first][startCoord.second] = new Empty(false, " "); // Replace starting position with Empty
                currBoard[endCoord.first][endCoord.second] = pieceToMove; // Place the selected piece in the ending position
                setTurn(true);
            
            }
            else{
                cout << "Not a valid move, try again black player!" << endl;
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
    int y1 = '8' - coords.second; // Convert row number to integer (0-7) in reverse order (bottom to top)

    return make_pair(y1, x1); // Return the coordinates in (row, column) order
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

bool Board::getHasWon(){
        return hasWon;
    }

  
void Board::processSetupCommand(string input, vector<PieceInfo>& storePieceInfo, bool isSetupComplete) {

    // If isSetupComplete is false, add the piece info to the vector and return
    if (!isSetupComplete) {
        //  + K e1 
        PieceInfo info;
        info.command = input[0]; // + or -
        info.pieceType = input[2]; //"K"
        info.letter = input[4]; //e
        info.number = input[5]; //1
        storePieceInfo.push_back(info);
        return;
    }

   
else{

     // If isSetupComplete is true, it means we are exiting the setup mode and should update the board configuration
    // Clear default board pieces (make all pointers null)
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            delete currBoard[row][col]; // Delete the existing piece at the current position
            currBoard[row][col] = nullptr; // Set the pointer to nullptr
        }
    }
   // Set board pieces based on the stored piece info
    for (const PieceInfo& info : storePieceInfo) {
        char command = info.command;
        char pieceType = info.pieceType;
        char letter = info.letter;
        char number = info.number;

        // Convert letter and number to row and column indices using getCoords function
        pair<char, char> coords = make_pair(letter, number);
        pair<int, int> indices = getCoords(coords);
        int row = indices.first;
        int col = indices.second;

        if (command == '+') {
            // Create the appropriate piece based on the piece type and set it on the board
            Piece* piece = nullptr;

            switch (pieceType) {
                case 'K': piece = new King(1, "K"); break;
                case 'Q': piece = new Queen(1, "Q"); break;
                case 'B': piece = new Bishop(1, "B"); break;
                case 'H': piece = new Horse(1, "H"); break;
                case 'R': piece = new Rook(1, "R"); break;
                case 'P': piece = new Pawn(1, "P"); break;
                case 'k': piece = new King(0, "k"); break;
                case 'q': piece = new Queen(0, "q"); break;
                case 'b': piece = new Bishop(0, "b"); break;
                case 'h': piece = new Horse(0, "h"); break;
                case 'r': piece = new Rook(0, "r"); break;
                case 'p': piece = new Pawn(0, "p"); break;
                default: break; // Invalid piece type, do nothing
            }

            // If a valid piece was created, set it on the board
            if (piece) {
                currBoard[row][col] = piece;
            }
        }
        else if (command == '-') {
            // Remove the piece from the specified position (set it to an empty square)
            currBoard[row][col] = new Empty(false, " ");
        }
    }

    // Clear the stored piece info vector as we no longer need it
    storePieceInfo.clear();

    // Exit setup mode
    cout << "Exited setup mode.\n";

}
}

    