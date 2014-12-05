#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "components/MovementComponent.h"
#include "components/PositionComponent.h"

#include "artemiscpp/ComponentMapper.h"
#include "artemiscpp/EntityProcessingSystem.h"

namespace artemis
{
    class Entity;
}

class MovementSystem : public artemis::EntityProcessingSystem
{
private:
    artemis::ComponentMapper<MovementComponent> velocityMapper;
    artemis::ComponentMapper<PositionComponent> positionMapper;

public:
    MovementSystem();

    virtual void initialize();

    virtual void processEntity(artemis::Entity& e);

};

#endif  // MOVEMENT_SYSTEM_H
