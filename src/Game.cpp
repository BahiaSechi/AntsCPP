//
// Created by kyojin on 30/11/2020.
//

#include <Game.h>

#include <iostream>
#include <Ants/Types/Queen.h>
#include <mutex>

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

    window.create(sf::VideoMode(800, 600), "Cool");
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
    stat_file.open("evolution.txt", std::ios::out | std::ios::trunc);

    stat_file << "x acount cfood\n";
}

void Game::updateGraphics() const
{
    // TODO: Voir ça plus tard
}

void Game::onUpdate(float elapsed_time)
{
    std::cout << elapsed_time << std::endl;
    // TODO: Handle events

    // TODO: Update data
    for (Ant *ant : ants)
        ant->play_turn(this);

    Queen *queen = new Queen(true, 100, 0.4, Position({0, 0}, std::stack<int>(), false));
    ants.push_back(queen);

    // TODO: Update graphics
    // graphic_thread.join();
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

////////////////////////////////////////////////////////////
// Non-member functions
////////////////////////////////////////////////////////////

void updateGraphics(sf::RenderWindow &window, Game *game)
{
    sf::Vector2f    view_center   = game->getViewCenter().load();
    sf::Vector2f    view_size     = game->getViewSize().load();
    sf::View        main_view(sf::FloatRect(view_center.x, view_center.y, view_size.x, view_size.y));
    sf::Vector2i    map_dimension = game->getMap()->getDimension();

    // activate the window's context
    window.setActive(true);
    window.setView(main_view);

    int hlines_count = map_dimension.y / game->getTileSize() + 1;
    int vlines_count = map_dimension.x / game->getTileSize() + 1;

//    sf::VertexArray hlines(sf::Lines, hlines_count);
//    sf::VertexArray vlines(sf::Lines, vlines_count);
//
//    for (int i = 0; i < hlines_count; i+=1) {
//        hlines[i].position = sf::Vector2f({0.0f, i * game->getTileSize() + 0.0f});
//        hlines[i + 1].position = sf::Vector2f({map_dimension.y + 0.0f, i * game->getTileSize() + 0.0f});
//    }
//
//    for (int j = 0; j < vlines_count; j+=1) {
//        vlines[j].position = sf::Vector2f({j * game->getTileSize() + 0.0f, 0.0f});
//        vlines[j + 1].position = sf::Vector2f({j * game->getTileSize() + 0.0f, map_dimension.x + 0.0f});
//    }

//    sf::Texture ant_texture;
//    ant_texture.loadFromFile("../assets/ants/walk.png",
//                             sf::IntRect(0, 0, 200, 250));
//    sf::Sprite ant(ant_texture);

    // the rendering loop
    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        // draw...
//        window.draw(shape);
//        window.draw(hlines);
//        window.draw(vlines);
//        window.draw(ant);

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