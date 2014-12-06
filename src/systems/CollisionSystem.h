#ifndef COLLISION_SYSTEM_H_
#define COLLISION_SYSTEM_H_

#include <SFML/Window.hpp>

#include "components/MovementComponent.h"
#include "components/PositionComponent.h"

#include "artemiscpp/ComponentMapper.h"
#include "artemiscpp/EntityProcessingSystem.h"

class CollisionSystem : public artemis::EntitySystem
{
private:
    artemis::ComponentMapper<MovementComponent> mVelocityMapper;
    artemis::ComponentMapper<PositionComponent> mPositionMapper;

    float mFieldWidth;
    float mFieldHeight;

public:
    CollisionSystem(const sf::VideoMode& videoMode);

    virtual void initialize();
    virtual bool checkProcessing();
    virtual void processEntities(artemis::ImmutableBag<artemis::Entity*>& bag);
};

#endif  // COLLISION_SYSTEM_H_
