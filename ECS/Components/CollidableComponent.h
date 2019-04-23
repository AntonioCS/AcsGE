#pragma once

#include "../Component.h"
#include "../../Util/Vector2D.h"
#include "../../Util/Dimensions.h"
#include "../../Util/Shapes/Rectangle.h"
#include "../../Util/CollisionDetection.h"

namespace AcsGameEngine
{
    class Sprite;
}

namespace AcsGameEngine::ECS {



    class CollidableComponent : public Component
    {
    public:
        CollidableComponent() = default;

        CollidableComponent(float x, float y, float w, float h);

        CollidableComponent(const Sprite* s);

        bool drawRect() const noexcept;

        void updateOrigin(float x, float y);

        void updateDimension(float w, float h);

        void update(float x, float y, float w, float h);

        void update(AcsGameEngine::Util::Vector2D vec);

        void update(AcsGameEngine::Util::Dimensions dim);

        AcsGameEngine::Util::Shapes::Rectangle& getRect();

        bool isColliding(AcsGameEngine::Util::Shapes::Rectangle& otherShape) const;

    private:
        AcsGameEngine::Util::Shapes::Rectangle m_box;
        AcsGameEngine::Util::CollisionDetection m_collision;
    };
}