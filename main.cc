#include <iostream>
using namespace std;

int main() {

cout << "Chess!" << endl;


    Board myBoard = Board("human", "human", true, "");

    // Get the pieces on the board
    vector<vector<Piece*>> pieces = myBoard.currBoard;

    // Display the board
    for (int row = 7; row >= 0; row--) {
        for (int col = 0; col < 8; col++) {
            if (pieces[row][col]) {
                cout << pieces[row][col]->getSymbol() << " ";
            } else {
                cout << "__ ";
            }
        }
        cout << endl;
    }

    return 0;

}