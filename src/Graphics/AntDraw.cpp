//
// Created by mateo on 09/12/2020.
//

#include <Graphics/AntDraw.h>

AntDraw::AntDraw()
{
    std::string filepath = "../../assets/ants/walk.png";

    queen_texture = {0, 0};
    scoot_texture = {0, 0};
    slaveowner_texture = {0, 0};
    soldier_texture = {0, 0};
    worker_texture = {0, 0};
}
