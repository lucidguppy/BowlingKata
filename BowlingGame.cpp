#include "BowlingGame.h"
#include <vector>
#include <cassert>

void Game::roll(int pins) {
  currentRoll += 1;
  rolls.push_back(pins);
}

bool Game::isSpare(int frameIndex) {
  return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}

int Game::getScore() {
  int score = 0;
  int frameIndex = 0;
  for (int frame = 0; frame < 10; ++frame) {
    if (isSpare(frameIndex)) {
      score += 10 + rolls[frameIndex + 2];
      frameIndex += 2;
    } else {
      score += rolls[frameIndex] + rolls[frameIndex + 1];
      frameIndex += 2;
    }
  }
  return score;
}
