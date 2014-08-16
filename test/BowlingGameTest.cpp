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
  int n = 20;
  int pins = 0;
  rollMany(n, pins);
  REQUIRE(0 == g.getScore());
}

TEST_CASE_METHOD(BowlingTestsFixture, "AllOnes", "[bowlingGame]") {
  int n = 20;
  int pins = 1;
  rollMany(n, pins);
  REQUIRE(20 == g.getScore());
}
