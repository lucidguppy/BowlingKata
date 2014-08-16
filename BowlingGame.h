/*
 * BowlingGame.h
 *
 *  Created on: Aug 16, 2014
 *      Author: matt
 */
#include <vector>

#ifndef BOWLINGGAME_H_
#define BOWLINGGAME_H_

class Game {
 private:
  int currentRoll;
  std::vector<int> rolls;
  bool isSpare(int frameIndex);
  bool isStrike(int frameIndex);
  int strikeBonus(int frameIndex);
  int spareBonus(int frameIndex);

 public:
  Game()
      : currentRoll(0) {
  }
  ;

  void roll(int pins);
  int getScore();

};

#endif /* BOWLINGGAME_H_ */
