/**
 * Address :
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 * Note :
 * This file is owned by an ENSICAEN student.  No portion of this
 * document may be reproduced, copied  or revised without written
 * permission of the authors.
 *
 * @author Mateo RABOTIN <mateo.rabotin@ecole.ensicaen.fr>
 * @author Bahia SECHI <bahia.sechi@ecole.ensicaen.fr>
 *
 * @date November 2020
 * @file main.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <Game.h>

//TEST_CASE("Queen giving birth", "[birth_queen]") {
//    Game game(60, 60);
//    game.start(1);
//
//    SECTION("queen give birth for the first time") {
//        game.getAnts()[0]->move(&game);
//        REQUIRE(game.getAnts()[1] != nullptr);
//    }
//}

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