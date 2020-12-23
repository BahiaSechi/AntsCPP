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

#include <Graphics/GameRender.h>

#include <atomic>

#include <Graphics/TileDraw.h>
#include <sstream>

////////////////////////////////////////////////////////////
// Main methods
////////////////////////////////////////////////////////////

sf::VertexArray GameRender::tilesVertices(Map *map, int map_x, int map_y)
{
    sf::VertexArray tiles_vertices(sf::Quads, map_x * map_y * 4);
    int             i = 0;
    const Tile      *tile;
    TileDraw        tdraw;
    sf::Vector2i    ttexture_coord;

    for (int y = 0; y < map_y - 1; ++y) {
        for (int x = 0; x < map_x - 1; ++x) {
            tile = map->getTile(x, y);

            tiles_vertices[i].position     = {x * tile_size, y * tile_size};
            tiles_vertices[i + 1].position = {(x + 1) * tile_size, y * tile_size};
            tiles_vertices[i + 2].position = {(x + 1) * tile_size, (y + 1) * tile_size};
            tiles_vertices[i + 3].position = {x * tile_size, (y + 1) * tile_size};

            switch (tile->getType()) {
                case tile_type::EMPTY:
                    ttexture_coord = (tile->isDiscovered() ? tdraw.empty_discovered_texture : tdraw.empty_texture);
                    break;
                case tile_type::OBSTACLE:
                    ttexture_coord = (tdraw.obstacle_texture);
                    break;
                case tile_type::FOOD:
                    ttexture_coord = (tile->isDiscovered() ? tdraw.food_discovered_texture : tdraw.food_texture);
                    break;
                case tile_type::COLONY:
                    ttexture_coord = (tdraw.colony_texture);
                    break;
            }

            tiles_vertices[i].texCoords     = {ttexture_coord.x + 0.f, ttexture_coord.y + 0.f};
            tiles_vertices[i + 1].texCoords = {ttexture_coord.x + tile_size, ttexture_coord.y + 0.f};
            tiles_vertices[i + 2].texCoords = {ttexture_coord.x + tile_size, ttexture_coord.y + tile_size};
            tiles_vertices[i + 3].texCoords = {ttexture_coord.x + 0.f, ttexture_coord.y + tile_size};

            i += 4;
        }
    }

    return tiles_vertices;
}

sf::VertexArray GameRender::antsVertices(const std::vector<Ant *> ants, Tile ***tiles, const AntDraw &adraw)
{
    sf::VertexArray ants_vertices(sf::Quads, ants.size() * 4);
    int             i = 0;
    Tile            *tile;
    sf::Vector2i    pos;

    std::pair<sf::Vector2i, sf::Vector2i> atexture_coord;

    for (auto ant : ants) {
        pos  = ant->getPosition().getPos();
        tile = tiles[pos.y][pos.x];

        ants_vertices[i].position     = {pos.x * tile_size, pos.y * tile_size};
        ants_vertices[i + 1].position = {(pos.x + 1) * tile_size, pos.y * tile_size};
        ants_vertices[i + 2].position = {(pos.x + 1) * tile_size, (pos.y + 1) * tile_size};
        ants_vertices[i + 3].position = {pos.x * tile_size, (pos.y + 1) * tile_size};

        switch (ant->getType()) {
            case QUEEN:
                atexture_coord = adraw.queen_texture;
                break;
            case SCOUT:
                atexture_coord = adraw.scout_texture;
                break;
            case WORKER:
                atexture_coord = adraw.worker_texture;
                break;
            case SLAVEOWNER:
                atexture_coord = adraw.slaveowner_texture;
                break;
            case SOLDIER:
                atexture_coord = adraw.soldier_texture;
                break;
        }

        // + 0.f to cast to float
        ants_vertices[i].texCoords     = {atexture_coord.first.x + 0.f, atexture_coord.first.y + 0.f};
        ants_vertices[i + 1].texCoords = {atexture_coord.second.x + 0.f, atexture_coord.first.y + 0.f};
        ants_vertices[i + 2].texCoords = {atexture_coord.second.x + 0.f, atexture_coord.second.y + 0.f};
        ants_vertices[i + 3].texCoords = {atexture_coord.first.x + 0.f, atexture_coord.second.y + 0.f};

        i += 4;
    }

    return ants_vertices;
}

void GameRender::updateGraphics(Game *game)
{
    // activate the window's context
    window.setActive(true);
    window.setVerticalSyncEnabled(true);

    std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();

    float elapsed_time = 0.0;

    sf::Vector2f vcenter = view_center;
    sf::Vector2f vsize   = view_size;
    auto         map     = game->getMap();
    sf::Vector2f mouse_pos_view;
    sf::Vector2u mouse_pos_grid;

    sf::Font font_default;
    font_default.loadFromFile("assets/fonts/JetBrainsMono-Regular.ttf");
    sf::Text t_ants_counter("", font_default);
    t_ants_counter.setPosition({20.f, 20.f});
    t_ants_counter.setCharacterSize(24);
    t_ants_counter.setFillColor(sf::Color::Black);

    sf::Text t_loop_counter("", font_default);
    t_loop_counter.setPosition({20.f, 50.f});
    t_loop_counter.setCharacterSize(24);
    t_loop_counter.setFillColor(sf::Color::Black);

    sf::Text t_colony_pos("", font_default);
    t_colony_pos.setPosition({20.f, 80.f});
    t_colony_pos.setCharacterSize(24);
    t_colony_pos.setFillColor(sf::Color::Black);

    sf::Text t_mouse_target("", font_default);
    t_mouse_target.setPosition({20.f, 110.f});
    t_mouse_target.setCharacterSize(24);
    t_mouse_target.setFillColor(sf::Color::Black);

    sf::Text t_help("", font_default);
    t_help.setCharacterSize(24);
    t_help.setFillColor(sf::Color::Black);

    TileDraw         tdraw;
    AntDraw          adraw;
    sf::RenderStates ants_render;
    ants_render.texture = &(adraw.ants_texture);

    while (!map->isGenerated()) {}

    sf::Vector2i map_dimension = map->getDimension();

    window.setView(ant_view);

    // the rendering loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            handleGraphicEvent(event, elapsed_time);
        }

        window.clear(sf::Color::White);

        mouse_pos_view = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (mouse_pos_view.x >= 0.f)
            mouse_pos_grid.x = mouse_pos_view.x / tile_size;
        if (mouse_pos_view.y >= 0.f)
            mouse_pos_grid.y = mouse_pos_view.y / tile_size;

        vsize = view_size;

        std::stringstream ss;
        ss << "Nombre de fourmis: " << game->getAnts().size() << '\n';
        t_ants_counter.setString(ss.str());
        ss.str("");

        ss << "Tour numero: " << game->getLoopCount() << '\n';
        t_loop_counter.setString(ss.str());
        ss.str("");

        ss << "Position de la colony: (" << Constants::Map::COLONY_POS.x << "," << Constants::Map::COLONY_POS.y << ")"
           << '\n';
        t_colony_pos.setString(ss.str());
        ss.str("");

        ss << "Cible de la souris: (" << mouse_pos_grid.x << "," << mouse_pos_grid.y << ")" << '\n';
        t_mouse_target.setString(ss.str());
        ss.str("");

        t_help.setPosition({window.getSize().x - 520.f, window.getSize().y - 40.f});
        ss << "Fleches pour bouger, +/- pour zoomer" << '\n';
        t_help.setString(ss.str());
        ss.str("");

        // draw ant stuff
        window.setView(ant_view);
        window.draw(tilesVertices(game->getMap(), map_dimension.x, map_dimension.y), &tdraw.tile_texture);
        window.draw(antsVertices(game->getAnts(), map->getTiles(), adraw), ants_render);


        // draw ui
        window.setView(gui_view);
        window.draw(t_ants_counter);
        window.draw(t_loop_counter);
        window.draw(t_colony_pos);
        window.draw(t_mouse_target);
        window.draw(t_help);

        elapsed_time = wait(t1, t2, 1.0);

        // end the current frame
        window.display();
    }
}

void GameRender::handleGraphicEvent(const sf::Event &event, float elapsed_time)
{
    sf::Vector2f vsize   = getViewSize();
    sf::Vector2f vcenter = getViewCenter();
    float        vzoom   = getViewZoom();

    if (event.type == sf::Event::Closed)
        window.close();

    if (event.type == sf::Event::Resized) {
        // resize my view
        ant_view.setSize({static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
        gui_view.setSize({static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
        gui_view.setCenter(event.size.width / 2, event.size.height / 2);
        // and align shape
    }

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Add) {
            sf::View view = window.getView();
            ant_view.zoom(vzoom - 0.02f);
        }

        if (event.key.code == sf::Keyboard::Subtract) {
            sf::View view = window.getView();
            ant_view.zoom(vzoom + 0.02f);
        }

        if (event.key.code == sf::Keyboard::Left) {
            sf::View view = window.getView();
            vcenter = {vcenter.x - 50.0f, vcenter.y};
            ant_view.setCenter(vcenter);
        }

        if (event.key.code == sf::Keyboard::Right) {
            sf::View view = window.getView();
            vcenter = {vcenter.x + 50.0f, vcenter.y};
            ant_view.setCenter(vcenter);
        }

        if (event.key.code == sf::Keyboard::Up) {
            sf::View view = window.getView();
            vcenter = {vcenter.x, vcenter.y - 50.0f};
            ant_view.setCenter(vcenter);
        }

        if (event.key.code == sf::Keyboard::Down) {
            sf::View view = window.getView();
            vcenter = {vcenter.x, vcenter.y + 50.0f};
            ant_view.setCenter(vcenter);
        }
    }

    setViewCenter(vcenter);
    setViewSize(vsize);
    setViewZoom(vzoom);
}

void GameRender::startGraphics(Game *game)
{
    sf::Vector2f        vsize   = view_size;
    sf::Vector2f        vcenter = view_center;
    sf::ContextSettings wsettings;
    wsettings.antialiasingLevel = 8;

    window.create(sf::VideoMode(vsize.x, vsize.y), "Cool", sf::Style::Default, wsettings);
    window.setVerticalSyncEnabled(true);

    ant_view = sf::View(sf::FloatRect(vcenter.x, vcenter.y, vsize.x, vsize.y));
    ant_view.setCenter(vcenter);
    gui_view = sf::View(sf::FloatRect(vcenter.x, vcenter.y, vsize.x, vsize.y));

    window.setView(ant_view);

    std::thread gthread(&GameRender::updateGraphics, this, game);
    gthread.detach();
}

////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////


const sf::Vector2f &GameRender::getViewCenter() const
{
    return view_center;
}

void GameRender::setViewCenter(const sf::Vector2f &viewCenter)
{
    view_center = viewCenter;
}

const sf::Vector2f &GameRender::getViewSize() const
{
    return view_size;
}

void GameRender::setViewSize(const sf::Vector2f &viewSize)
{
    view_size = viewSize;
}

const float &GameRender::getViewZoom() const
{
    return view_zoom;
}

void GameRender::setViewZoom(const std::atomic<float> &viewZoom)
{
    view_zoom = viewZoom;
}

int GameRender::getTileSize() const
{
    return tile_size;
}

void GameRender::setTileSize(int tileSize)
{
    tile_size = tileSize;
}

sf::RenderWindow &GameRender::getWindow()
{
    return window;
}
