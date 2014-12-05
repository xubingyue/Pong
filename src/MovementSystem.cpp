#include "MovementSystem.h"

MovementSystem::MovementSystem() {
    setComponentTypes<MovementComponent,PositionComponent>();
};

void MovementSystem::initialize() {
    velocityMapper.init(*world);
    positionMapper.init(*world);
};

void MovementSystem::processEntity(artemis::Entity &e) {
    positionMapper.get(e)->posX += velocityMapper.get(e)->velocityX * world->getDelta();
    positionMapper.get(e)->posY += velocityMapper.get(e)->velocityY * world->getDelta();
};
