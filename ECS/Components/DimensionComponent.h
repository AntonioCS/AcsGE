#pragma once

#include "../Component.h"
#include "../../Util/Dimensions.h"

namespace AcsGameEngine::ECS {

    class DimensionComponent : public Component
    {
    public:
        DimensionComponent() = default;
        DimensionComponent(float w, float h);
        DimensionComponent(int w, int h);
        DimensionComponent(const Util::Dimensions d);

        void update(float w, float h);
        void update(int w, int h);

        AcsGameEngine::Util::Dimensions getDimensions() const;

    private:
        AcsGameEngine::Util::Dimensions m_dimensions;
    };
}