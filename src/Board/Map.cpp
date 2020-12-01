//
// Created by kyojin on 23/11/2020.
//

#include <Board/Map.h>

#include <random>

#include <Board/ColonyTile.h>
#include <Board/ObstacleTile.h>
#include <Board/FoodTile.h>
#include <Board/EmptyTile.h>

Map::~Map()
{
    for (int y = 0; y < dimension.y; ++y) {
        for (int x = 0; x < dimension.x; ++x) {
            delete[] tiles[y][x];
        }
        delete[] tiles[y];
    }

    delete[] tiles;
    tiles = nullptr;
}

Map::Map(int height, int width, int colony_food, int big_food_source_count)
        : colony_food(colony_food), big_food_source_count(big_food_source_count)
{
    dimension = {width, height};
    tiles = new Tile **[height];

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 10.0);

    for (int y = 0; y < height; ++y) {
        tiles[y] = new Tile *[width];


        for (int x = 0; x < width; ++x) {
            if (y == height / 2 && x == width / 2) {
                tiles[y][x] = new ColonyTile({x, y});
            } else {
                float tile_type_prob = dis(gen);

                if (tile_type_prob <= 3.0) {
                    // TODO: implement every type of obstacle
                    // 30% chance of small food tile
                    tiles[y][x] = new ObstacleTile({x, y});
                } else if (tile_type_prob <= 3.002) {
                    // 0.02% chance of small food tile
                    tiles[y][x] = new FoodTile({x, y});
                } else {
                    tiles[y][x] = new EmptyTile({x, y});
                }
            }

        }
    }

    // TODO: x and y could point to the tile at the middle of the map, thus deleting the first colony tile. Change that.
    for (int i = 0; i < big_food_source_count; ++i) {
        int x = rand() % width;
        int y = rand() % height;
        tiles[y][x] = new FoodTile({x, y});
    }
}

std::ostream &operator<<(std::ostream &os, const Map &map)
{
    os << "dimension: (" << map.dimension.x << ", " << map.dimension.y;

    for (int y = 0; y < map.dimension.y; ++y) {
        os << "\n";
        for (int x = 0; x < map.dimension.x; ++x) {
            Tile *tile = map.tiles[y][x];
            switch (tile->getType()) {
                case tile_type::EMPTY:
                    os << "E";
                    break;
                case tile_type::OBSTACLE:
                    os << "O";
                    break;
                case tile_type::FOOD:
                    os << "F";
                    break;
                case tile_type::COLONY:
                    os << "C";
                    break;
            }
        }
    }

    return os;
}

const sf::Vector2i &Map::getDimension() const {
    return dimension;
}

void Map::setDimension(const sf::Vector2i &dimension) {
    Map::dimension = dimension;
}

Tile ***Map::getTiles() const {
    return tiles;
}

void Map::setTiles(Tile ***tiles) {
    Map::tiles = tiles;
}

int Map::getColonyFood() const {
    return colony_food;
}

void Map::setColonyFood(int colonyFood) {
    colony_food = colonyFood;
}
