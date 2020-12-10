//
// Created by kyojin on 30/11/2020.
//

#include <Game.h>

#include <iostream>

#include <Ants/Types/Queen.h>
#include <Graphics/TileDraw.h>
#include <Graphics/AntDraw.h>

////////////////////////////////////////////////////////////
// Main methods
////////////////////////////////////////////////////////////

Game::Game(int width, int height)
        : map(new Map(height, width, 16, 2)), ants(std::vector<Ant *>())
{
}

void Game::start(int turn_count = -1)
{
    onCreate();

    std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();

    float elapsed_time = 0.0;
    int   loop_count   = 0;

    sf::Vector2f vsize = view_size.load();

    sf::ContextSettings wsettings;
    wsettings.antialiasingLevel = 8;
    window.create(sf::VideoMode(vsize.x, vsize.y), "Cool", sf::Style::Default, wsettings);
    window.setVerticalSyncEnabled(true);
    std::thread gthread(updateGraphics, std::ref(window), this);
    gthread.detach();

    while (window.isOpen() && (turn_count == -1 || --turn_count >= 0)) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            handleEvent(event, elapsed_time);
        }

        elapsed_time = wait(t1, t2);
        onLogicUpdate(elapsed_time);
        saveToFile(++loop_count);
    }
}

void Game::onCreate()
{
    ants.push_back(new Queen(
            true,
            100,
            0.4,
            Position({51, 51}, std::stack<sf::Vector2i>(), false)
    ));

    saveToFile(-1);
}

void Game::onLogicUpdate(float elapsed_time)
{
    // Firstly, update data for every ant except the queen
    for (int i = 1; i < ants.size(); ++i)
        ants[i]->play_turn(this);

    // Then the queen has the opportunity to give birth
    ants[0]->play_turn(this);
}

void Game::handleEvent(const sf::Event &event, float elapsed_time)
{
    if (event.type == sf::Event::Closed)
        window.close();

    if (event.type == sf::Event::Resized) {
        // resize my view
        sf::View view = window.getView();
        view.setSize({
                             static_cast<float>(event.size.width),
                             static_cast<float>(event.size.height)
                     });
        window.setView(view);
        // and align shape
    }

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Add) {
            sf::View view = window.getView();
            view.zoom(view_zoom - 0.02f);
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Subtract) {
            sf::View view = window.getView();
            view.zoom(view_zoom + 0.02f);
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Left) {
            sf::View     view    = window.getView();
            sf::Vector2f vcenter = view_center.load();
            vcenter = {vcenter.x - 50.0f, vcenter.y};
            view.setCenter(vcenter);
            view_center = vcenter;
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Right) {
            sf::View     view    = window.getView();
            sf::Vector2f vcenter = view_center.load();
            vcenter = {vcenter.x + 50.0f, vcenter.y};
            view.setCenter(vcenter);
            view_center = vcenter;
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Up) {
            sf::View     view    = window.getView();
            sf::Vector2f vcenter = view_center.load();
            vcenter = {vcenter.x, vcenter.y - 50.0f};
            view.setCenter(vcenter);
            view_center = vcenter;
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Down) {
            sf::View     view    = window.getView();
            sf::Vector2f vcenter = view_center.load();
            vcenter = {vcenter.x, vcenter.y + 50.0f};
            view.setCenter(vcenter);
            view_center = vcenter;
            window.setView(view);
        }
    }
}

void Game::saveToFile(int loop_count)
{
    std::ofstream stat_file;
    stat_file.open("evolution.txt", std::ios::out | std::ios::app);

    if (loop_count < 0) {
        stat_file.open("evolution.txt", std::ios::out | std::ios::trunc);
        stat_file << "x acount cfood\n";
    } else {
        stat_file.open("evolution.txt", std::ios::out | std::ios::app);

        if (stat_file.is_open()) {
            stat_file << loop_count << ' ' << ants.size() << ' ' << std::to_string(map->getColonyFood()) << '\n';
        }
    }

    stat_file.close();
}

Game::~Game()
{
    for (Ant *ant : ants) {
        delete ant;
    }

    delete map;
}

////////////////////////////////////////////////////////////
// Non-member functions
////////////////////////////////////////////////////////////

sf::VertexArray tilesVertices(Tile ***tiles, int map_x, int map_y)
{
    sf::VertexArray tiles_vertices(sf::Quads, map_x * map_y * 4);
    int             i = 0;
    Tile            *tile;
    TileDraw        tdraw;
    sf::Vector2i    ttexture_coord;


    for (int y = 0; y < map_y - 1; ++y) {
        for (int x = 0; x < map_x - 1; ++x) {
            tile = tiles[y][x];

            tiles_vertices[i].position     = {x * 16.f, y * 16.f};
            tiles_vertices[i + 1].position = {(x + 1) * 16.f, y * 16.f};
            tiles_vertices[i + 2].position = {(x + 1) * 16.f, (y + 1) * 16.f};
            tiles_vertices[i + 3].position = {x * 16.f, (y + 1) * 16.f};

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
            tiles_vertices[i + 1].texCoords = {ttexture_coord.x + 16.f, ttexture_coord.y + 0.f};
            tiles_vertices[i + 2].texCoords = {ttexture_coord.x + 16.f, ttexture_coord.y + 16.f};
            tiles_vertices[i + 3].texCoords = {ttexture_coord.x + 0.f, ttexture_coord.y + 16.f};

            i += 4;
        }
    }

    return tiles_vertices;
}

sf::VertexArray antsVertices(std::vector<Ant *> ants, Tile ***tiles, int map_x, int map_y)
{
    sf::VertexArray ants_vertices(sf::Quads, ants.size() * 4);
    int             i = 0;
    Tile            *tile;
    sf::Vector2i    atexture_coord;
    sf::Vector2i    pos;

    for (auto ant : ants) {
        pos  = ant->getPosition().getPos();
        tile = tiles[pos.y][pos.x];

        ants_vertices[i].position     = {pos.x * 16.f, pos.y * 16.f};
        ants_vertices[i + 1].position = {(pos.x + 1) * 16.f, pos.y * 16.f};
        ants_vertices[i + 2].position = {(pos.x + 1) * 16.f, (pos.y + 1) * 16.f};
        ants_vertices[i + 3].position = {pos.x * 16.f, (pos.y + 1) * 16.f};

        ants_vertices[i].texCoords     = {atexture_coord.x + 0.f, atexture_coord.y + 0.f};
        ants_vertices[i + 1].texCoords = {atexture_coord.x + 200.f, atexture_coord.y + 0.f};
        ants_vertices[i + 2].texCoords = {atexture_coord.x + 200.f, atexture_coord.y + 250.f};
        ants_vertices[i + 3].texCoords = {atexture_coord.x + 0.f, atexture_coord.y + 250.f};

        i += 4;
    }

    return ants_vertices;
}

void updateGraphics(sf::RenderWindow &window, Game *game)
{
    sf::Vector2f view_center   = game->getViewCenter().load();
    sf::Vector2f view_size     = game->getViewSize().load();
    sf::View     main_view(sf::FloatRect(view_center.x, view_center.y, view_size.x, view_size.y));
    Map          *map          = game->getMap();
    sf::Vector2i map_dimension = map->getDimension();

    TileDraw         tdraw;
    AntDraw          adraw;
    sf::RenderStates ants_render;
    ants_render.texture   = &(adraw.ants_texture);

    while (map->getTiles() == nullptr) {}

    // activate the window's context
    window.setActive(true);
    window.setVerticalSyncEnabled(true);

    Tile *tile;

    // the rendering loop
    while (window.isOpen()) {
        window.clear(sf::Color::White);

        view_center = game->getViewCenter().load();
        view_size   = game->getViewSize().load();

        // draw map
        window.draw(tilesVertices(map->getTiles(), map_dimension.x, map_dimension.y), &tdraw.tile_texture);
        window.draw(antsVertices(game->getAnts(), map->getTiles(), map_dimension.x, map_dimension.y), ants_render);

        // end the current frame
        window.display();
    }
}

float wait(std::chrono::system_clock::time_point t1, std::chrono::system_clock::time_point t2)
{
    using namespace std::chrono;

    float time_between_frame = 1000.0;
    t1 = system_clock::now();
    duration<double, std::milli> work_time = t1 - t2;

    if (work_time.count() < time_between_frame) {
        duration<double, std::milli> delta_ms(time_between_frame - work_time.count());
        auto                         delta_ms_duration = duration_cast<milliseconds>(delta_ms);
        std::this_thread::sleep_for(milliseconds(delta_ms_duration.count()));
    }

    t2 = system_clock::now();
    duration<double, std::milli> sleep_time = t2 - t1;

    return work_time.count();
}

////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////

Map *Game::getMap() const
{
    return map;
}

void Game::setMap(Map &map)
{
    delete this->map;
    this->map = &map;
}

std::vector<Ant *> &Game::getAnts()
{
    return ants;
}

void Game::setAnts(const std::vector<Ant *> &ants)
{
    Game::ants = ants;
}

const std::atomic<sf::Vector2f> &Game::getViewCenter() const
{
    return view_center;
}

void Game::setViewCenter(const sf::Vector2f &viewCenter)
{
    view_center = viewCenter;
}

const std::atomic<sf::Vector2f> &Game::getViewSize() const
{
    return view_size;
}

void Game::setViewSize(const sf::Vector2f &viewSize)
{
    view_size = viewSize;
}

const std::atomic<float> &Game::getViewZoom() const
{
    return view_zoom;
}

void Game::setViewZoom(float viewZoom)
{
    view_zoom = viewZoom;
}

int Game::getTileSize() const
{
    return tile_size;
}

void Game::setTileSize(int tileSize)
{
    tile_size = tileSize;
}