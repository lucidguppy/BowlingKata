#include "catch.hpp"
#include "BowlingGame.h"

TEST_CASE("TestBowlingGame", "[bowlingGame]") {
  Game g = Game();
  SECTION("Gutter Game"){
    for (int ii=0; ii<20; ii++)
      g.roll(0);
    REQUIRE(0 == g.getScore());
  }
  SECTION("All Ones"){
    for (int ii=0; ii<20; ii++)
      g.roll(1);
    REQUIRE(20 == g.getScore());
  }
}
