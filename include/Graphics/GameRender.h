//
// Created by mateo on 12/12/2020.
//

#ifndef ANTS_GAMERENDER_H
#define ANTS_GAMERENDER_H

#include <atomic>

#include <Ants/Types/Ant.h>
#include <Board/Tile.h>
#include <Game.h>

class Game;

class Ant;

class Tile;

class GameRender
{
private:
    sf::RenderWindow window;
    sf::View         ant_view;
    sf::View         gui_view;

    std::atomic<sf::Vector2f> view_center = std::atomic<sf::Vector2f>(sf::Vector2f(0.0f, 0.0f));
    std::atomic<sf::Vector2f> view_size   = std::atomic<sf::Vector2f>(sf::Vector2f(500.0f, 500.0f));
    std::atomic<float>        view_zoom   = std::atomic<float>({1.0f});

    int tile_size = 16;

public:
    sf::VertexArray tilesVertices(Tile ***tiles, int map_x, int map_y);

    sf::VertexArray antsVertices(std::vector<Ant *> ants, Tile ***tiles, int map_x, int map_y);

    /**
     * Function called by a delegated thread to update graphics
     *
     * @param window
     */
    void updateGraphics(Game *game);

    void startGraphics(Game *game);

    void handleGraphicEvent(const sf::Event &event, float elapsed_time);

    const std::atomic<sf::Vector2f> &getViewCenter() const;

    void setViewCenter(const std::atomic<sf::Vector2f> &viewCenter);

    const std::atomic<sf::Vector2f> &getViewSize() const;

    void setViewSize(const std::atomic<sf::Vector2f> &viewSize);

    const std::atomic<float> &getViewZoom() const;

    void setViewZoom(const std::atomic<float> &viewZoom);

    int getTileSize() const;

    void setTileSize(int tileSize);

    sf::RenderWindow &getWindow();
};

#endif //ANTS_GAMERENDER_H
