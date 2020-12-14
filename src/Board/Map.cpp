//
// Created by kyojin on 23/11/2020.
//

#include <Board/Map.h>

#include <random>

#include <Board/ColonyTile.h>
#include <Board/ObstacleTile.h>
#include <Board/FoodTile.h>
#include <Board/EmptyTile.h>
#include <iostream>

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
        : colony_food(colony_food), big_food_source_count(big_food_source_count), is_generated(false),
          dimension({width, height})
{
}

void Map::generate()
{
    int width  = dimension.x;
    int height = dimension.y;

    tiles = new Tile **[height];

    std::random_device               rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937                     gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 10.0);
    float                            tile_type_prob;

    for (int y = 0; y < height; ++y) {
        tiles[y] = new Tile *[width];
        for (int x = 0; x < width; ++x) {
            tiles[y][x] = nullptr;
        }
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (tiles[y][x] == nullptr) {
                if (y == height / 2 && x == width / 2) {
                    tiles[y][x] = new ColonyTile({x, y});
                } else {
                    tile_type_prob = dis(gen);

                    if (tile_type_prob <= 3.0) {
                        tile_type_prob = dis(gen);

                        if (!nbNeighbors(y, x)) {
                            tiles[y][x] = new ObstacleTile({x, y});
                            if (!(x - 1 < 0 || x + 1 >= width || 0 > y - 1 || y + 1 >= height)) {
                                if (tile_type_prob >= 7.0) {
                                    tiles[y][x - 1] = new ObstacleTile({x - 1, y});
                                }
                                if (tile_type_prob >= 9.0) {
                                    tiles[y + 1][x] = new ObstacleTile({x, y + 1});
                                }
                                if (tile_type_prob >= 9.5) {
                                    tiles[y + 1][x - 1] = new ObstacleTile({x - 1, y + 1});
                                }
                                if (tile_type_prob >= 9.9) {
                                    tiles[y - 1][x] = new ObstacleTile({x, y - 1});
                                }
                                if (tile_type_prob >= 10.0) {
                                    tiles[y + 1][x] = new ObstacleTile({x, y + 1});
                                }
                            }
                        } else {
                            tiles[y][x] = new EmptyTile({x, y});
                        }
                    } else if (tile_type_prob <= 3.002) {
                        // 0.02% chance of small food tile
                        tiles[y][x] = new FoodTile({x, y});
                    } else {
                        tiles[y][x] = new EmptyTile({x, y});
                    }
                }
            }
        }
    }


    for (int i = 0; i < big_food_source_count; ++i) {
        int x = rand() % width;
        int y = rand() % height;
        if (tiles[y][x]->getType() != tile_type::COLONY) {
//            if (tiles[y][x] != nullptr) {
//                delete [] tiles[y][x];
//            }

            tiles[y][x] = new FoodTile({x, y});
        } else {
            tiles[y / 2][x] = new FoodTile({x, y});
        }
    }

    is_generated = true;
}

int Map::nbNeighbors(int y, int x)
{
    sf::Vector2i dimension = this->getDimension();

    if ((x - 1 < 0) || (x + 1 >= x) || (0 > y - 1) || (y + 1 >= y)) {
        return 0;
    }

    std::vector<Tile *> around = {
            tiles[y - 1][x - 1],
            tiles[y - 1][x],
            tiles[y - 1][x + 1],
            tiles[y][x - 1],
            tiles[y][x + 1],
            tiles[y + 1][x - 1],
            tiles[y + 1][x],
            tiles[y + 1][x + 1]
    };

    return std::count_if(around.begin(), around.end(), [](Tile *tile) {
        if (tile == nullptr) {
            return false;
        }

        return tile->getType() != tile_type::EMPTY;
    });

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

const sf::Vector2i &Map::getDimension() const
{
    return dimension;
}

void Map::setDimension(const sf::Vector2i &dimension)
{
    Map::dimension = dimension;
}

Tile ***Map::getTiles() const
{
    return tiles;
}

void Map::setTiles(Tile ***tiles)
{
    std::lock_guard<std::mutex> guard(mtx);
    Map::tiles = tiles;
}

int Map::getColonyFood() const
{
    return colony_food;
}

void Map::setColonyFood(int colonyFood)
{
    this->colony_food = colonyFood;
}

bool Map::isGenerated() const
{
    return is_generated;
}

Tile *Map::setTile(int x, int y, Tile *tile)
{
    std::lock_guard<std::mutex> guard(mtx);
    tiles[y][x] = tile;
}

Tile *Map::getTile(int x, int y) const
{
    return tiles[y][x];
}
