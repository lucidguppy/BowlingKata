#include "catch.hpp"
#include "BowlingGame.h"

class BowlingTestsFixture {
 public:
  Game g;
  BowlingTestsFixture()
      : g(Game()) {
  }
  void rollMany(int n, int pins) {
    for (int ii = 0; ii < n; ii++)
      g.roll(pins);
  }
};

TEST_CASE_METHOD(BowlingTestsFixture, "GutterGame", "[bowlingGame]") {
  rollMany(20, 0);
  REQUIRE(0 == g.getScore());
}

TEST_CASE_METHOD(BowlingTestsFixture, "AllOnes", "[bowlingGame]") {
  rollMany(20, 1);
  REQUIRE(20 == g.getScore());
}
