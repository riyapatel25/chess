#include "computer.h"
#include "piece.h"

Computer::Computer(int color, int level) : Player{color}, level{level} {}

Move Computer::makeMove(vector<vector <Piece*>> board)
{

    if (level == 1)
    {
        return levelOne(board);
    }
    if (level == 2)
    {
        return levelTwo(board);
    }
}

Move Computer::levelOne(vector<vector <Piece*>> board)
{

    // Handle computer player's move (Level 1)
    std::vector<Move> validMoves = getAllValidMoves(board);

    // Randomly choose a valid move
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % validMoves.size();
    return validMoves[randomIndex];
}

Move Computer::levelTwo(vector<vector <Piece*>> board)
{

    // Handle computer player's move (Level 2)
    vector<Move> validMoves = getAllValidMoves(board);

    // Check if there is any capturing move or check available
    vector<Move> capturingMoves;
    vector<Move> checkMoves;

    for (const Move &move : validMoves)
    {
        Piece *targetPiece = board[move.getEndRow()][move.getEndCol()];
        if (targetPiece && targetPiece->getColor() != color)
        {
            capturingMoves.push_back(move);
        }
        // Assume check function is already implemented for the board
        if (board[move.getEndRow()][move.getEndCol()]->isCheck(move, board))
        {
            checkMoves.push_back(move);
        }
    }

    // If there is at least one capturing move, prefer capturing moves
    if (!capturingMoves.empty())
    {
        srand(static_cast<unsigned int>(time(0)));
        int randomIndex = rand() % capturingMoves.size();
        return capturingMoves[randomIndex];
    }

    // If there is at least one check move, prefer check moves
    if (!checkMoves.empty())
    {
        srand(static_cast<unsigned int>(time(0)));
        int randomIndex = rand() % checkMoves.size();
        return checkMoves[randomIndex];
    }

    // If no capturing move or check move is available, choose a valid move randomly
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % validMoves.size();
    return validMoves[randomIndex];
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
