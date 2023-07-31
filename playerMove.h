#ifndef PLAYERMOVE_H_
#define PLAYERMOVE_H_
using namespace std;

class Move {
public:
    Move(int startRow, int startCol, int endRow, int endCol)
        : startRow(startRow), startCol(startCol), endRow(endRow), endCol(endCol) {}

    int getStartRow() const { return startRow; }
    int getStartCol() const { return startCol; }
    int getEndRow() const { return endRow; }
    int getEndCol() const { return endCol; }

private:
    int startRow; // Starting row of the piece being moved
    int startCol; // Starting column of the piece being moved
    int endRow;   // Ending row of the move
    int endCol;   // Ending column of the move
};


<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 4630f1f996d1ce30183e4b04157cb3ffcde40dc2
