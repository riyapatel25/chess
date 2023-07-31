#include "piece.h"

class Horse: public Piece {
    public:
<<<<<<< HEAD
    Horse(bool PlayerWhiteOrBlack, string name);
    virtual bool playerMove (int row, int col, int newRow, int newCol, const Board& chessBoard) override;
    virtual bool canPlayerKill (int row, int col) override;
    virtual vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col) override;
    virtual bool isCheck(Move move, vector<vector <Piece*>> board) override;
=======
    Horse(int PlayerWhiteOrBlack, string pieceType);
    bool playerMove (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard, bool turn) override;
    // bool isCheck (int row, int col, int newRow, int newCol, const vector<vector<Piece*>> chessBoard) override;
    vector<Move> getValidMovesForPiece(vector<vector <Piece*>> board, int row, int col, bool turn) override;


>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2

};