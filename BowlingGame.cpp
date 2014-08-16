#include "BowlingGame.h"

void Game::roll(int pins) {
  this->score += pins;
}

int Game::getScore() {
  return this->score;
}
