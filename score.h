
#ifndef __SCORE_
#define __SCORE_
#include <iostream>
#include <string>
using namespace std;

class Score {
    private:

	public:
    Score();
	~Score();
    void updateScore(double score, int whichPlayer);
    double getWhiteScore();
    double getBlackScore();
    void clearScore();
    bool leadingScore(); //who's winning 
    double whiteWins;
	double blackWins;
    pair<double, double> getScore();

};
#endif