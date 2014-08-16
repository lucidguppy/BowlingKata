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
  void rollSpare() {
    g.roll(5);
    g.roll(5);
  }
  void rollStrike() {
  g.roll(10);
  }
};

TEST_CASE_METHOD(BowlingTestsFixture, "PerfectGame", "[bowlingGame]") {
  rollMany(12, 10);
  REQUIRE(300 == g.getScore());
}

TEST_CASE_METHOD(BowlingTestsFixture, "GutterGame", "[bowlingGame]") {
  rollMany(20, 0);
  REQUIRE(0 == g.getScore());
}

TEST_CASE_METHOD(BowlingTestsFixture, "AllOnes", "[bowlingGame]") {
  rollMany(20, 1);
  REQUIRE(20 == g.getScore());
}

TEST_CASE_METHOD(BowlingTestsFixture, "TestOneSpare", "[bowlingGame]") {
  rollSpare();
  g.roll(3);
  rollMany(17, 0);
  REQUIRE(16 == g.getScore());
}

TEST_CASE_METHOD(BowlingTestsFixture, "TestOneStrike", "[bowlingGame]") {

  rollStrike();
  g.roll(3);
  g.roll(4);
  rollMany(17, 0);
  REQUIRE(24 == g.getScore());
}
