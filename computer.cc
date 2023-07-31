#include "computer.h"
#include "piece.h"
#include <climits>


Computer::Computer(int color, int level) : Player{color}, level{level} {}

<<<<<<< HEAD
Move Computer::makeMove(vector<vector <Piece*>> board)
{

    if (level == 1){
        return levelOne(board);
    }
    if (level == 2){
        return levelTwo(board);
    }
    if (level == 3){
        return levelThree(board);
    }
}

Move Computer::levelOne(vector<vector <Piece*>> board)
{

    // Handle computer player's move (Level 1)
    std::vector<Move> validMoves = getAllValidMoves(board);
=======
Move Computer::makeMove(vector<vector <Piece*>> board, bool turn)
{

    if (level == 1){
        return levelOne(board, turn);
    }
    if (level == 2){
        return levelTwo(board, turn);
    }
    // if (level == 3){
    //     return levelThree(board);
    // }
}

Move Computer::levelOne(vector<vector <Piece*>> board, bool turn)
{

    // Handle computer player's move (Level 1)
    std::vector<Move> validMoves = getAllValidMoves(board, turn);
    
    for (const auto& move : validMoves) {
        // Access elements of move here
        // Example:
        // std::cout << "From: (" << move.getStartRow() << ", " << move.getStartCol() << ") ";
        // std::cout << "To: (" << move.getEndRow() << ", " << move.getEndCol() << ")" << std::endl;
    }
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2

    // Randomly choose a valid move
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = 100*rand() % validMoves.size();
<<<<<<< HEAD
    return validMoves[randomIndex];
}

Move Computer::levelTwo(vector<vector <Piece*>> board)
{

    // Handle computer player's move (Level 2)
    vector<Move> validMoves = getAllValidMoves(board);
=======
    cout << "valid moves size: " << validMoves.size() << endl;
    cout << "Random Move is: " <<endl;
    std::cout << "From: (" << validMoves[randomIndex].getStartRow() << ", " << validMoves[randomIndex].getStartCol() << ") ";
        std::cout << "To: (" << validMoves[randomIndex].getEndRow() << ", " << validMoves[randomIndex].getEndCol() << ")" << std::endl;
    return validMoves[randomIndex];
}

Move Computer::levelTwo(vector<vector <Piece*>> board, bool turn)
{

    // Handle computer player's move (Level 2)
    vector<Move> validMoves = getAllValidMoves(board, turn);
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2

    // Evaluate each move and assign scores based on desirability
    std::vector<int> moveScores(validMoves.size(), 0);

    // Capture rankings based on the piece type that can be captured
<<<<<<< HEAD
    std::unordered_map<std::string, int> captureRankings = {
        {"Pawn", 1},
        {"Knight", 3},
        {"Bishop", 3},
        {"Rook", 5},
        {"Queen", 9}
    };

    // Find the best move with the highest score
    int bestScore = INT_MIN;
    int bestMoveIndex = -1;

    for (size_t i = 0; i < validMoves.size(); ++i) {

        // Check if the move leads to the capture of an opponent's piece
        Piece* targetPiece = board[validMoves[i].getEndRow()][validMoves[i].getEndCol()];
        if (targetPiece.pieceType != "Empty" && targetPiece->getColor() != board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]) {
            std::string capturedPieceType = capturedPiece->getName();
            if (captureRankings.find(capturedPieceType) != captureRankings.end()) {
                moveScores[i] += captureRankings[capturedPieceType]; // Assign score based on capture ranking
            }
        }

        // Evaluate the move based on avoiding capture, capturing moves, and checks
        if (isCheck(validMoves[i], board, board[validMoves[i].getStartRow][validMoves[i].getStartCol]->getColor())) {
            moveScores[i] -= 100; // Avoid moves that lead to check
        }
        if (isCheck(validMoves[i], board, !board[validMoves[i].getStartRow][validMoves[i].getStartCol]->getColor())) {
            moveScores[i] += 50; // Prefer capturing moves that put the opponent in check
        }


        // Update the best move
        if (moveScores[i] > bestScore) {
            bestScore = moveScores[i];
            bestMoveIndex = i;
        }

    }

    // Return the best move
    return validMoves[bestMoveIndex];
}

Move Computer::levelThree(vector<vector <Piece*>> board) {

    std::vector<Move> validMoves = getAllValidMoves(board);

    // Evaluate each move and assign scores based on desirability
    std::vector<int> moveScores(validMoves.size(), 0);

    // Capture rankings based on the piece type that can be captured
    std::unordered_map<std::string, int> captureRankings = {
        {"Pawn", 1},
        {"Knight", 3},
        {"Bishop", 3},
        {"Rook", 5},
        {"Queen", 9}
    };

=======
    std::unordered_map<std::string, int> captureRankingsWhite = {
        {"P", 1},
        {"H", 3},
        {"B", 3},
        {"R", 5},
        {"Q", 9}
        
    };

    std::unordered_map<std::string, int> captureRankingsBlack = {
        {"p", 1},
        {"h", 3},
        {"b", 3},
        {"r", 5},
        {"q", 9}
    };


>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
    // Find the best move with the highest score
    int bestScore = INT_MIN;
    int bestMoveIndex = -1;

    for (size_t i = 0; i < validMoves.size(); ++i) {

<<<<<<< HEAD
        // Evaluate the move based on avoiding capture, capturing moves, and checks
        if (isCheck(validMoves[i], board, board[validMoves[i].getStartRow][validMoves[i].getStartCol]->getColor())) {
            moveScores[i] -= 100; // Avoid moves that lead to check
        }
        if (isCheck(validMoves[i], board, !board[validMoves[i].getStartRow][validMoves[i].getStartCol]->getColor())) {
            moveScores[i] += 50; // Prefer capturing moves that put the opponent in check
        }

        // Check if the move leads to the capture of an opponent's piece
        Piece* targetPiece = board[validMoves[i].getEndRow()][validMoves[i].getEndCol()];
        if (targetPiece.pieceType != "Empty" && targetPiece->getColor() != board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]) {
            std::string capturedPieceType = capturedPiece->getName();
            if (captureRankings.find(capturedPieceType) != captureRankings.end()) {
                moveScores[i] += captureRankings[capturedPieceType]; // Assign score based on capture ranking
            }
        }

        // Check if the move puts the piece in danger of being captured
        if (isAttacked(validMoves[i].getEndRow(), validMoves[i].getEndCol())) {
            // We can change how we rank and in what order
            moveScores[i] -= 20; // Avoid moves that lead to capture by the opponent
        }
=======
        // Check if the move leads to the capture of an opponent's piece
        Piece* targetPiece = board[validMoves[i].getEndRow()][validMoves[i].getEndCol()];
        if (targetPiece->pieceType != " " && targetPiece->color != board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]->color) {
            std::string capturedPieceType = targetPiece->pieceType;

            if(turn){
                if (captureRankingsWhite.find(capturedPieceType) != captureRankingsWhite.end()) {
                    moveScores[i] += captureRankingsWhite[capturedPieceType]; // Assign score based on capture ranking
                }
            } else {
                if (captureRankingsBlack.find(capturedPieceType) != captureRankingsBlack.end()) {
                    moveScores[i] += captureRankingsBlack[capturedPieceType]; // Assign score based on capture ranking
                }
            }
        }

        // Evaluate the move based on avoiding capture, capturing moves, and checks
        // if (isCheck(validMoves[i], board, board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
        //     moveScores[i] -= 100; // Avoid moves that lead to check
        // }
        // if (isCheck(validMoves[i], board, !board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
        //     moveScores[i] += 50; // Prefer capturing moves that put the opponent in check
        // }

>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2

        // Update the best move
        if (moveScores[i] > bestScore) {
            bestScore = moveScores[i];
            bestMoveIndex = i;
        }
<<<<<<< HEAD
=======

>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
    }

    // Return the best move
    return validMoves[bestMoveIndex];
}

<<<<<<< HEAD

vector<Move> Computer::getAllValidMoves(vector<vector <Piece*>> board)
=======
// Move Computer::levelThree(vector<vector <Piece*>> board) {

//     std::vector<Move> validMoves = getAllValidMoves(board);

//     // Evaluate each move and assign scores based on desirability
//     std::vector<int> moveScores(validMoves.size(), 0);

//     // Capture rankings based on the piece type that can be captured
//     std::unordered_map<std::string, int> captureRankings = {
//         {"P", 1},
//         {"H", 3},
//         {"B", 3},
//         {"R", 5},
//         {"Q", 9},
//         {"p", 1},
//         {"h", 3},
//         {"b", 3},
//         {"r", 5},
//         {"q", 9},
//     };

//     // Find the best move with the highest score
//     int bestScore = INT_MIN;
//     int bestMoveIndex = -1;

//     for (size_t i = 0; i < validMoves.size(); ++i) {

//         // Evaluate the move based on avoiding capture, capturing moves, and checks
//         // if (isCheck(validMoves[i], board, board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
//         //     moveScores[i] -= 100; // Avoid moves that lead to check
//         // }
//         // if (isCheck(validMoves[i], board, !board[validMoves[i].getStartRow][validMoves[i].getStartCol]->color)) {
//         //     moveScores[i] += 50; // Prefer capturing moves that put the opponent in check
//         // }

//         // Check if the move leads to the capture of an opponent's piece
//         Piece* targetPiece = board[validMoves[i].getEndRow()][validMoves[i].getEndCol()];
//         if (targetPiece->pieceType != " " && targetPiece->color != board[validMoves[i].getStartRow()][validMoves[i].getStartCol()]->color) {
//             std::string capturedPieceType = targetPiece->pieceType;
//             if (captureRankings.find(capturedPieceType) != captureRankings.end()) {
//                 moveScores[i] += captureRankings[capturedPieceType]; // Assign score based on capture ranking
//             }
//         }

//         // Check if the move puts the piece in danger of being captured
//         if (isAttacked(validMoves[i].getEndRow(), validMoves[i].getEndCol())) {
//             // We can change how we rank and in what order
//             moveScores[i] -= 20; // Avoid moves that lead to capture by the opponent
//         }

//         // Update the best move
//         if (moveScores[i] > bestScore) {
//             bestScore = moveScores[i];
//             bestMoveIndex = i;
//         }
//     }

//     // Return the best move
//     return validMoves[bestMoveIndex];
// }


vector<Move> Computer::getAllValidMoves(vector<vector <Piece*>> board, bool turn)
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
{
    vector<Move> validMoves;

    // Iterate through the board to find the current player's pieces
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            Piece *currentPiece = board[row][col];

            // Check if there is a piece on the current square and if it belongs to the current player
<<<<<<< HEAD
            if (currentPiece->getName() != "Empty" && currentPiece->getColor() == color)
            {
                // Generate all possible moves for the current piece
                vector<Move> pieceValidMoves = currentPiece->getValidMovesForPiece(board, row, col);
=======
            if (currentPiece->pieceType != " " && currentPiece->color == color)
            {
                // Generate all possible moves for the current piece
                vector<Move> pieceValidMoves = currentPiece->getValidMovesForPiece(board, row, col, turn);
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2

                // Add the generated moves to the vector of valid moves
                validMoves.insert(validMoves.end(), pieceValidMoves.begin(), pieceValidMoves.end());
            }
        }
    }

    return validMoves;
}
<<<<<<< HEAD
=======


bool Computer::makeMove(int row, int col, int newRow, int newCol, const vector<vector<Piece*>>  board, bool turn){
    return false;
}
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
