
#ifndef __SCORE_
#define __SCORE_
#include <iostream>
#include <string>

class Score {
    private:
    Score();
    int whiteWins;
	int blackWins;

	public:
	~Score();
    void updateScore(score: double, whichPlayer: bool);
    double getWhiteScore(score: double);
    double getBlackScore(score: double);
    void clearScore();
    bool leadingScore(); //who's winning 

};
#endif