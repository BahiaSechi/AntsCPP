//
// Created by mateo on 12/12/2020.
//

#ifndef ANTS_GAMERENDER_H
#define ANTS_GAMERENDER_H

#include <atomic>

#include <Ants/Types/Ant.h>
#include <Board/Map.h>
#include <Board/Tile.h>
#include <Game.h>

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

    sf::Vector2f view_center = sf::Vector2f(100.0f, 100.0f);
    sf::Vector2f view_size   = sf::Vector2f(800.0f, 800.0f);
    float        view_zoom   = 1.0f;

    int tile_size = 16;

public:
    sf::VertexArray tilesVertices(const Map &map, int map_x, int map_y);

    sf::VertexArray antsVertices(std::vector<Ant *> ants, Tile ***tiles, int map_x, int map_y);

    /**
     * Function called by a delegated thread to update graphics
     *
     * @param window
     */
    void updateGraphics(Game *game);

    void startGraphics(Game *game);

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
