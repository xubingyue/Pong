#include "MovementComponent.h"
#include "PositionComponent.h"

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

    virtual void processEntity(artemis::Entity &e);

};
