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
            Position({0, 0}, std::stack<int>(), false)
    ));

    saveToFile(-1);
}

void Game::onLogicUpdate(float elapsed_time)
{
    // Firstly, update data for every ant except the queen
    for (int i = 1; i < ants.size(); ++i)
        ants[i]->move(this);

    // Then the queen has the opportunity to give birth
    ants[0]->move(this);
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
    }
}

void Game::saveToFile(int loop_count)
{
    std::ofstream stat_file;

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

const Map *Game::getMap() const
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

////////////////////////////////////////////////////////////
// Non-member functions
////////////////////////////////////////////////////////////

void updateGraphics(sf::RenderWindow &window, Game *game)
{
    sf::Vector2f view_center = game->getViewCenter();
    sf::Vector2f view_size = game->getViewSize();
    sf::View mainView(sf::FloatRect(view_center.x, view_center.y, view_size.x, view_size.y));

    // activate the window's context
    window.setActive(true);

    window.setView(mainView);

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100, 250, 50));

    // the rendering loop
    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        // draw...
        window.draw(shape);

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