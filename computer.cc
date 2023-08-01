#include "computer.h"
#include "piece.h"
#include <climits>
#include <unordered_map>
Computer::Computer(int color, int level) : Player{color}, level{level} {}


Move Computer::makeMove(vector<vector <Piece*>> board, bool turn)
{

    if (level == 1){
        return levelOne(board, turn);
    }
    if (level == 2){
        return levelTwo(board, turn);
    }
    if (level == 3){
        return levelThree(board, turn);
    }
}

Move Computer::levelOne(vector<vector <Piece*>> board, bool turn)
{

    // Handle computer player's move (Level 1)
    std::vector<Move> validMoves = getAllValidMoves(board, turn);
    
    // for (const auto& move : validMoves) {
    //     // Access elements of move here
    //     // Example:
    //     // std::cout << "From: (" << move.getStartRow() << ", " << move.getStartCol() << ") ";
    //     // std::cout << "To: (" << move.getEndRow() << ", " << move.getEndCol() << ")" << std::endl;
    // }

    // Randomly choose a valid move
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = 100*rand() % validMoves.size();
    cout << "Random Move is: " <<endl;
    std::cout << "From: (" << validMoves[randomIndex].getStartRow() << ", " << validMoves[randomIndex].getStartCol() << ") ";
        std::cout << "To: (" << validMoves[randomIndex].getEndRow() << ", " << validMoves[randomIndex].getEndCol() << ")" << std::endl;
    return validMoves[randomIndex];
}

Move Computer::levelTwo(vector<vector <Piece*>> board, bool turn)
{

    // Handle computer player's move (Level 2)
    vector<Move> validMoves = getAllValidMoves(board, turn);

    // Evaluate each move and assign scores based on desirability
    std::vector<int> moveScores(validMoves.size(), 0);

    // Capture rankings based on the piece type that can be captured
    std::unordered_map<std::string, int> captureRankings = {
        {"P", 1},
        {"H", 3},
        {"B", 3},
        {"R", 5},
        {"Q", 9},
        {"p", 1},
        {"h", 3},
        {"b", 3},
        {"r", 5},
        {"q", 9}
    };


    // Find the best move with the highest score
    int bestScore = INT_MIN;
    int bestMoveIndex = -1;

    for (size_t i = 0; i < validMoves.size(); ++i) {

        // Check if the move leads to the capture of an opponent's piece
        Piece* targetPiece = board[validMoves[i].getEndRow()][validMoves[i].getEndCol()];
        if (targetPiece->pieceType != " " && targetPiece->color != board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]->color) {
            std::string capturedPieceType = targetPiece->pieceType;

            if (captureRankings.find(capturedPieceType) != captureRankings.end()) {
                moveScores[i] += captureRankings[capturedPieceType]; // Assign score based on capture ranking
            }
        }

        // Evaluate the move based on avoiding capture, capturing moves, and checks
        // if (isCheck(validMoves[i], board, board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
        //     moveScores[i] -= 100; // Avoid moves that lead to check
        // }
        // if (isCheck(validMoves[i], board, !board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
        //     moveScores[i] += 50; // Prefer capturing moves that put the opponent in check
        // }


        // Update the best move
        if (moveScores[i] > bestScore) {
            bestScore = moveScores[i];
            bestMoveIndex = i;
        }

    }

    // Return the best move
    cout << "Best Score is: " << bestScore<< endl;
    for(int i = 0; i < moveScores.size(); i++){
        cout << "score: " << moveScores[i]<<endl;
    }

    // Return the best move
    if(bestScore == 0){
        cout << " Randomly choose a valid move" <<endl;
        // Randomly choose a valid move
        srand(static_cast<unsigned int>(time(0)));
        int randomIndex = 100*rand() % validMoves.size();
        return validMoves[randomIndex];
    }

    if(bestMoveIndex == -1){
        cerr << "no more valid moves we should never enter here once isCheck and isCheckmate are implemented" <<endl;
    }


    return validMoves[bestMoveIndex];
}

Move Computer::levelThree(vector<vector <Piece*>> board, bool turn) {

    std::vector<Move> validMoves = getAllValidMoves(board, turn);
    bool isEqualRank = false;

    // Evaluate each move and assign scores based on desirability
    std::vector<int> moveScores(validMoves.size(), 0);

    // Capture rankings based on the piece type that can be captured
    std::unordered_map<std::string, int> captureRankings = {
        {"P", 1},
        {"H", 3},
        {"B", 3},
        {"R", 5},
        {"Q", 9},
        {"p", 1},
        {"h", 3},
        {"b", 3},
        {"r", 5},
        {"q", 9},
    };

    // Find the best move with the highest score
    int bestScore = INT_MIN;
    int bestMoveIndex = -1;

    for (size_t i = 0; i < validMoves.size(); ++i) {

        // Evaluate the move based on avoiding capture, capturing moves, and checks
        // if (isCheck(validMoves[i], board, board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
        //     moveScores[i] -= 100; // Avoid moves that lead to check
        // }
        // if (isCheck(validMoves[i], board, !board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
        //     moveScores[i] += 50; // Prefer capturing moves that put the opponent in check
        // }

        // Check if the move leads to the capture of an opponent's piece
        Piece* targetPiece = board[validMoves[i].getEndRow()][validMoves[i].getEndCol()];
        if (targetPiece->pieceType != " " && targetPiece->color != board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]->color) {
            string capturedPieceType = targetPiece->pieceType;
            if (captureRankings.find(capturedPieceType) != captureRankings.end()) {
                moveScores[i] += captureRankings[capturedPieceType]; // Assign score based on capture ranking
            } else {
                cout << "Error: piece not found in ranking" << endl;
            }
        }

        // Check if the move puts the piece in danger of being captured
        if (isAttacked(validMoves[i].getEndRow(), validMoves[i].getEndCol(), board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]->color, board)) {
            // We can change how we rank and in what order
            cout << "if you move: " <<  board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]->pieceType << " from: " << "(" << validMoves[i].getStartRow() << "," << validMoves[i].getStartCol() << ")" << " -> " << "(" << validMoves[i].getEndRow() << "," << validMoves[i].getEndCol() << ")" <<endl;
            Piece* pieceToMove = board[validMoves[i].getStartRow()][validMoves[i].getStartCol()];

            string willBecapturedPieceType = pieceToMove->pieceType;
            if (captureRankings.find(willBecapturedPieceType) != captureRankings.end()) {
                moveScores[i] -= captureRankings[willBecapturedPieceType]; // Assign score based on capture ranking
            } else {
                cout << "Error: piece not found in ranking" << endl;
            }

        }

        // Update the best move
        if (moveScores[i] > bestScore) {
            bestScore = moveScores[i];
            bestMoveIndex = i;
        }
    }

    // Return the best move
    cout << "Best Score is: " << bestScore<< endl;
    for(int i = 0; i < moveScores.size(); i++){
        cout << "score: " << moveScores[i]<<endl;
    }


    // Return the best move if all moves have the same rank, choose randomly
    int firstValue = moveScores[0];
    for (int i = 1; i < moveScores.size(); ++i) {
        if (moveScores[i] != firstValue) {
            isEqualRank = false; // If any value is different set isEqualRank to false
            break;
        } else {
            isEqualRank = true; 
        }
    }

    if(isEqualRank){
        cout << " Randomly choose a valid move" <<endl;
        // Randomly choose a valid move
        srand(static_cast<unsigned int>(time(0)));
        int randomIndex = rand() % validMoves.size();
        return validMoves[randomIndex];
    }

    if(bestMoveIndex == -1){
        cerr << "no more valid moves we should never enter here once isCheck and isCheckmate are implemented" <<endl;
    }

    return validMoves[bestMoveIndex];
}


vector<Move> Computer::getAllValidMoves(vector<vector <Piece*>> board, bool turn)
{
    vector<Move> validMoves;

    // Iterate through the board to find the current player's pieces
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            Piece *currentPiece = board[row][col];

            // Check if there is a piece on the current square and if it belongs to the current player
            if (currentPiece->pieceType != " " && currentPiece->color == color)
            {
                // Generate all possible moves for the current piece
                vector<Move> pieceValidMoves = currentPiece->getValidMovesForPiece(board, row, col, turn);

                // Add the generated moves to the vector of valid moves
                validMoves.insert(validMoves.end(), pieceValidMoves.begin(), pieceValidMoves.end());
            }
        }
    }

    return validMoves;
}


bool Computer::makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board, bool turn){
    return false;
}


bool Computer::isAttacked(int row, int col, int currMove, const vector<vector<Piece*>>  board) {
    cout << "color: " << currMove <<endl;

    // Get the opponent's color
    int opponentColor = !currMove;

    cout << "opponents color: " << opponentColor <<endl;


    // Iterate through the board to find the opponent's pieces
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece* currentPiece = board[r][c];

            // Check if there is a piece on the current square and if it belongs to the opponent
            if (currentPiece->color == opponentColor) {
                // Generate all possible moves for the current piece
                std::vector<Move> pieceValidMoves = currentPiece->getValidMovesForPiece(board, r, c, opponentColor);

                // Check if any of the valid moves target the specified square
                for (const Move& move : pieceValidMoves) {
                    if (move.getEndRow() == row && move.getEndCol() == col) {
                        
                        cout << "dangerous move for peice:  "<<  currentPiece->pieceType <<" (" << move.getStartRow() << "," << move.getStartCol() << ") -> (" << move.getEndRow() << "," << move.getEndCol() << ")"<<endl;
                        return true; // The square is being attacked by the opponent's piece
                    }
                }
            }
        }
    }

    return false;
}