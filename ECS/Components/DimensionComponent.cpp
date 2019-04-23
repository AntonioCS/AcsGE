#include "DimensionComponent.h"

namespace AcsGameEngine::ECS {

    DimensionComponent::DimensionComponent(float w, float h) : m_dimensions(w, h)
    {
    }    
    
    DimensionComponent::DimensionComponent(int w, int h) : m_dimensions(w, h)
    {
    }

    DimensionComponent::DimensionComponent(const Util::Dimensions d) : m_dimensions(d)
    {
    }

    void DimensionComponent::update(float w, float h)
    {
        m_dimensions.width = w;
        m_dimensions.height = h;
    }

    void DimensionComponent::update(int w, int h)
    {
        update(static_cast<float>(w), static_cast<float>(h));
    }

    AcsGameEngine::Util::Dimensions DimensionComponent::getDimensions() const
    {
        return m_dimensions;
    }
}
