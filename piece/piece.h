#ifndef PIECE_H
#define PIECE_H

class Piece {

protected:
    // int row;
    // int col;
    // int newRow;
    // int newCol;

public:
    virtual void playerMove (int row, int col, int newRow, int newCol) = 0;
    virtual bool canPlayerKill (int row, int col) = 0;
    bool isCheck (int row, int col, int newRow, int newCol);
    virtual ~Piece();
};

#endif
