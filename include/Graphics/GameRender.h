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

#ifndef ANTS_GAMERENDER_H
#define ANTS_GAMERENDER_H

#include <atomic>

#include <Ants/Types/Ant.h>
#include <Board/Map.h>
#include <Board/Tile.h>
#include <Graphics/AntDraw.h>
#include <Game.h>
#include <constants.h>

class Ant;

class Game;

class Map;

class Tile;

class GameRender
{
private:
    sf::RenderWindow window;
    sf::View         ant_view;
    sf::View         gui_view;

    sf::Vector2f view_center = sf::Vector2f(Constants::Map::COLONY_POS.x + 0.f, Constants::Map::COLONY_POS.y + 0.f);
    sf::Vector2f view_size   = sf::Vector2f(800.0f, 800.0f);
    float        view_zoom   = 1.0f;

    float tile_size = Constants::Map::TILESIZE;

public:
    /**
     * Generates the vertices to draw the tiles of the map.
     *
     * @param map
     * @param map_x
     * @param map_y
     * @return
     */
    sf::VertexArray tilesVertices(Map *map, int map_x, int map_y);

    /**
     * Generates the vertices to draw the ants.
     *
     * @param ants
     * @param tiles
     * @param adraw
     * @return
     */
    sf::VertexArray antsVertices(const std::vector<Ant *> ants, Tile ***tiles, const AntDraw &adraw);

    /**
     * Function called by a delegated thread to update graphics.
     *
     * @param window
     */
    void updateGraphics(Game *game);

    /**
     * Start the graphic side of the software, display the window and run updateGraphics in a new thread.
     *
     * @param game
     */
    void startGraphics(Game *game);

    /**
     * Handle graphics related events like zooming or moving the camera.
     *
     * @param event
     * @param elapsed_time
     */
    void handleGraphicEvent(const sf::Event &event, float elapsed_time);

    const sf::Vector2f &getViewCenter() const;

    void setViewCenter(const sf::Vector2f &viewCenter);

    const sf::Vector2f &getViewSize() const;

    void setViewSize(const sf::Vector2f &viewSize);

    const float &getViewZoom() const;

    void setViewZoom(const std::atomic<float> &viewZoom);

    int getTileSize() const;

    void setTileSize(int tileSize);

    sf::RenderWindow &getWindow();
};

#endif //ANTS_GAMERENDER_H
