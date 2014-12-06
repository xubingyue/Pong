#include "systems/CollisionSystem.h"

CollisionSystem::CollisionSystem(const sf::VideoMode& videoMode)
    : mFieldWidth(videoMode.width)
    , mFieldHeight(videoMode.height)
{
    setComponentTypes<MovementComponent,PositionComponent>();
}

void CollisionSystem::initialize()
{
    mVelocityMapper.init(*world);
    mPositionMapper.init(*world);
};

bool CollisionSystem::checkProcessing() {
    return true;
}

void CollisionSystem::processEntities(artemis::ImmutableBag<artemis::Entity*>& bag) {
    int bagCount = bag.getCount();
    for (int i = 0; i < bagCount; ++i) {
        artemis::Entity& entity1 = *bag.get(i);

        MovementComponent* movementComponent = mVelocityMapper.get(entity1);
        PositionComponent* positionComponent = mPositionMapper.get(entity1);

        // Check collision with walls
        // TODO: need concept of shape to properly do the collision
        if (positionComponent->posX + (movementComponent->velocityX * world->getDelta()) < 0 ||
                positionComponent->posX + (movementComponent->velocityX * world->getDelta()) > mFieldWidth) {
            movementComponent->velocityX *= -1;
        }
        if (positionComponent->posY + (movementComponent->velocityY * world->getDelta()) < 0 ||
                positionComponent->posY + (movementComponent->velocityY * world->getDelta()) > mFieldHeight) {
            movementComponent->velocityY *= -1;
        }

    }
}
