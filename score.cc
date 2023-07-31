#include "score.h"

Score::Score() : whiteWins(0), blackWins(0) {}

Score::~Score() {}

void Score::updateScore(double score, int whichPlayer) {
    if (score > 0) {
        if (whichPlayer == 1) {
            whiteWins++;
        } else if(whichPlayer == 0){
            blackWins++;
        }
        //stalemate
        else if(whichPlayer == 2){
             whiteWins+= 0.5;
            blackWins+= 0.5;
        }
    }
}

double Score::getWhiteScore() {
    return whiteWins;
}

double Score::getBlackScore() {
    return blackWins;
}
pair<double, double> Score::getScore() {
    return make_pair(whiteWins, blackWins);
}


void Score::clearScore() {
    whiteWins = 0;
    blackWins = 0;
}

bool Score::leadingScore() {
    return whiteWins > blackWins;
}
