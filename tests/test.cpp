//
// Created by mateo on 04/12/2020.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <Game.h>

TEST_CASE("Queen giving birth", "[birth_queen]") {
    Game game(60, 60);
    game.start(1);
    auto ants = game.getAnts();

    SECTION("queen give birth for the first time") {
        ants[0]->move(&game);
        REQUIRE(ants[1] != nullptr);
    }
}

//
//SCENARIO("Queen can give birth", "[queen_birth]") {
//    GIVEN("A 60x60 base game with a queen in it") {
//        Game game(60, 60);
//        game.start(1);
//        auto ants = game.getAnts();
//
//        WHEN("the queen give birth for the first time") {
//            ants[0]->move(&game);
//
//            THEN("the first ant is a scout") {
//                REQUIRE(1 == 1);
//            }
//        }
//    }
//}