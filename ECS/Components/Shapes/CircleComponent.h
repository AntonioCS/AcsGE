#pragma once

#include "../../Component.h"
#include "../../../Util/Shapes/Circle.h"
#include "../../../Util/Color.h"

namespace AcsGameEngine::ECS {

    class CircleComponent : public Component 
    {
    public:
        Util::Shapes::Circle circle{{100,200}, 20};
        Util::Color color;
    };
}