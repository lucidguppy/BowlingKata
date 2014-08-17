#include "BowlingGame.h"

void Game::roll(int pins) {
  currentRoll += 1;
  rolls.push_back(pins);
}

bool Game::isSpare(int frameIndex) {
  return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}

bool Game::isStrike(int frameIndex) {
  return rolls[frameIndex] == 10;
}

int Game::strikeBonus(int frameIndex) {
  return rolls[frameIndex + 1] + rolls[frameIndex + 2];
}

int Game::spareBonus(int frameIndex) {
  return rolls[frameIndex + 2];
}

int Game::getScore() {
  int score = 0;
  int frameIndex = 0;
  for (int frame = 0; frame < 10; ++frame) {
    if (isStrike(frameIndex)) {
      score += 10 + strikeBonus(frameIndex);
      frameIndex++;
    } else if (isSpare(frameIndex)) {
      score += 10 + spareBonus(frameIndex);
      frameIndex += 2;
    } else {
      score += rolls[frameIndex] + rolls[frameIndex + 1];
      frameIndex += 2;
    }
  }
  return score;
}
