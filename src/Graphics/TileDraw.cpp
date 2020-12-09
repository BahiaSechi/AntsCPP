//
// Created by mateo on 09/12/2020.
//

#include <Graphics/TileDraw.h>

TileDraw::TileDraw()
{
    tile_texture.loadFromFile("assets/world/Overworld.png");

    colony_texture = {536, 57};
    empty_discovered_texture = {192,208};
    empty_texture = {0, 0};
    food_discovered_texture = {1, 546};
    food_texture = {15, 544};
    obstacle_texture = {480, 3};
}
