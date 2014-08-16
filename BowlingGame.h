/*
 * BowlingGame.h
 *
 *  Created on: Aug 16, 2014
 *      Author: matt
 */

#ifndef BOWLINGGAME_H_
#define BOWLINGGAME_H_

class Game {
 private:
  int score;

 public:
  Game() : score(0){
  };
  ;
  void roll(int pins);
  int getScore();

};

#endif /* BOWLINGGAME_H_ */
