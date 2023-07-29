#include "score.h"

Score::Score() : whiteWins(0), blackWins(0) {}

Score::~Score() {}

void Score::updateScore(double score, bool whichPlayer) {
    if (score > 0) {
        if (whichPlayer) {
            whiteWins++;
        } else {
            blackWins++;
        }
    }
}

double Score::getWhiteScore() {
    return whiteWins;
}

double Score::getBlackScore() {
    return blackWins;
}

void Score::clearScore() {
    whiteWins = 0;
    blackWins = 0;
}

bool Score::leadingScore() {
    return whiteWins > blackWins;
}
