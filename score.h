
#ifndef __SCORE_
#define __SCORE_
#include <iostream>
#include <string>

class Score {
    private:
    int whiteWins;
	int blackWins;

	public:
    Score();
	~Score();
    void updateScore(double score, bool whichPlayer);
    double getWhiteScore();
    double getBlackScore();
    void clearScore();
    bool leadingScore(); //who's winning 

};
#endif