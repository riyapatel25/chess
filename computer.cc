#include "computer.h"
#include "piece.h"
#include <climits>


Computer::Computer(int color, int level) : Player{color}, level{level} {}

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

    // Randomly choose a valid move
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = 100*rand() % validMoves.size();
    return validMoves[randomIndex];
}

Move Computer::levelTwo(vector<vector <Piece*>> board)
{

    // Handle computer player's move (Level 2)
    vector<Move> validMoves = getAllValidMoves(board);

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

    // Find the best move with the highest score
    int bestScore = INT_MIN;
    int bestMoveIndex = -1;

    for (size_t i = 0; i < validMoves.size(); ++i) {

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

        // Update the best move
        if (moveScores[i] > bestScore) {
            bestScore = moveScores[i];
            bestMoveIndex = i;
        }
    }

    // Return the best move
    return validMoves[bestMoveIndex];
}


vector<Move> Computer::getAllValidMoves(vector<vector <Piece*>> board)
{
    vector<Move> validMoves;

    // Iterate through the board to find the current player's pieces
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            Piece *currentPiece = board[row][col];

            // Check if there is a piece on the current square and if it belongs to the current player
            if (currentPiece->getName() != "Empty" && currentPiece->getColor() == color)
            {
                // Generate all possible moves for the current piece
                vector<Move> pieceValidMoves = currentPiece->getValidMovesForPiece(board, row, col);

                // Add the generated moves to the vector of valid moves
                validMoves.insert(validMoves.end(), pieceValidMoves.begin(), pieceValidMoves.end());
            }
        }
    }

    return validMoves;
}
