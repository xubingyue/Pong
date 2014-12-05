#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include "artemiscpp/Component.h"

class MovementComponent : public artemis::Component
{
public:
    float velocityX;
    float velocityY;

    MovementComponent(float velocityX, float velocityY);
};

#endif  // MOVEMENT_COMPONENT_H
