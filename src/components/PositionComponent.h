#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "artemiscpp/Component.h"

class PositionComponent : public artemis::Component
{

public:
    float posX;
    float posY;
    PositionComponent(float posX, float posY);
};

#endif  // POSITION_COMPONENT_H
