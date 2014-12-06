#include "systems/MovementSystem.h"

MovementSystem::MovementSystem()
{
    setComponentTypes<MovementComponent,PositionComponent>();
};

void MovementSystem::initialize()
{
    mVelocityMapper.init(*world);
    mPositionMapper.init(*world);
};

void MovementSystem::processEntity(artemis::Entity& e)
{
    mPositionMapper.get(e)->posX += mVelocityMapper.get(e)->velocityX * world->getDelta();
    mPositionMapper.get(e)->posY += mVelocityMapper.get(e)->velocityY * world->getDelta();
};
