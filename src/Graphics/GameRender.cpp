//
// Created by mateo on 12/12/2020.
//

#include <Graphics/GameRender.h>

#include <atomic>

#include <Graphics/TileDraw.h>
#include <Graphics/AntDraw.h>

////////////////////////////////////////////////////////////
// Main methods
////////////////////////////////////////////////////////////

sf::VertexArray GameRender::tilesVertices(Tile ***tiles, int map_x, int map_y)
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

sf::VertexArray GameRender::antsVertices(std::vector<Ant *> ants, Tile ***tiles, int map_x, int map_y)
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

void GameRender::updateGraphics(Game *game)
{
    std::chrono::system_clock::time_point t1           = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point t2           = std::chrono::system_clock::now();
    float                                 elapsed_time = 0.0;

    sf::Vector2f vcenter       = view_center.load();
    sf::Vector2f vsize         = view_size.load();
    sf::View     main_view(sf::FloatRect(vcenter.x, vcenter.y, vsize.x, vsize.y));
    Map          *map          = game->getMap();
    sf::Vector2i map_dimension = map->getDimension();

    sf::Font font_default;
    font_default.loadFromFile("assets/fonts/JetBrainsMono-Regular.ttf");
    sf::Text text_ants_counter("", font_default);
    text_ants_counter.setCharacterSize(24);
    text_ants_counter.setFillColor(sf::Color::Black);

    TileDraw         tdraw;
    AntDraw          adraw;
    sf::RenderStates ants_render;
    ants_render.texture = &(adraw.ants_texture);

    while (map->getTiles() == nullptr) {}

    // activate the window's context
    window.setActive(true);
    window.setVerticalSyncEnabled(true);

    Tile *tile;

    // the rendering loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            handleGraphicEvent(event, elapsed_time);
        }

        window.clear(sf::Color::White);

        vcenter = view_center.load();
        vsize   = view_size.load();

        text_ants_counter.setString("Nb de fourmis: " + std::to_string(game->getAnts().size()));

        // draw map
        window.draw(tilesVertices(map->getTiles(), map_dimension.x, map_dimension.y), &tdraw.tile_texture);
        window.draw(antsVertices(game->getAnts(), map->getTiles(), map_dimension.x, map_dimension.y), ants_render);
        window.draw(text_ants_counter);

        elapsed_time = wait(t1, t2, 1.0);

        // end the current frame
        window.display();
    }
}


void GameRender::createText(const std::string &str, sf::Text &text) const
{

}

void GameRender::startGraphics(Game *game)
{
    sf::Vector2f        vsize = view_size.load();
    sf::ContextSettings wsettings;
    wsettings.antialiasingLevel = 8;

    window.create(sf::VideoMode(vsize.x, vsize.y), "Cool", sf::Style::Default, wsettings);
    window.setVerticalSyncEnabled(true);
    std::thread gthread(&GameRender::updateGraphics, this, game);
    gthread.detach();
}

void GameRender::handleGraphicEvent(const sf::Event &event, float elapsed_time)
{
    sf::Vector2f vsize   = getViewSize().load();
    sf::Vector2f vcenter = getViewCenter().load();
    float        vzoom   = getViewZoom().load();

    if (event.type == sf::Event::Closed)
        window.close();

    if (event.type == sf::Event::Resized) {
        // resize my view
        sf::View view = window.getView();
        view.setSize({static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
        window.setView(view);
        // and align shape
    }

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Add) {
            sf::View view = window.getView();
            view.zoom(vzoom - 0.02f);
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Subtract) {
            sf::View view = window.getView();
            view.zoom(vzoom + 0.02f);
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Left) {
            sf::View view = window.getView();
            vcenter = {vcenter.x - 50.0f, vcenter.y};
            view.setCenter(vcenter);
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Right) {
            sf::View view = window.getView();
            vcenter = {vcenter.x + 50.0f, vcenter.y};
            view.setCenter(vcenter);
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Up) {
            sf::View view = window.getView();
            vcenter = {vcenter.x, vcenter.y - 50.0f};
            view.setCenter(vcenter);
            window.setView(view);
        }

        if (event.key.code == sf::Keyboard::Down) {
            sf::View view = window.getView();
            vcenter = {vcenter.x, vcenter.y + 50.0f};
            view.setCenter(vcenter);
            window.setView(view);
        }
    }

    setViewCenter(vcenter);
    setViewSize(vsize);
    setViewZoom(vzoom);
}

////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////


const std::atomic<sf::Vector2f> &GameRender::getViewCenter() const
{
    return view_center;
}

void GameRender::setViewCenter(const std::atomic<sf::Vector2f> &viewCenter)
{
    view_center.store(viewCenter);
}

const std::atomic<sf::Vector2f> &GameRender::getViewSize() const
{
    return view_size;
}

void GameRender::setViewSize(const std::atomic<sf::Vector2f> &viewSize)
{
    view_size.store(viewSize);
}

const std::atomic<float> &GameRender::getViewZoom() const
{
    return view_zoom;
}

void GameRender::setViewZoom(const std::atomic<float> &viewZoom)
{
    view_zoom.store(viewZoom);
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
