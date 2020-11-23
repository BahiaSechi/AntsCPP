//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_SLAVEOWNER_H
#define ANTSPROJECT_SLAVEOWNER_H

#include <Ants/Types/Ant.h>

class SlaveOwner : public Ant {
private:
    bool has_larva;

public:
    SlaveOwner(bool has_larva);
    ~SlaveOwner() override;
};


#endif //ANTSPROJECT_SLAVEOWNER_H
