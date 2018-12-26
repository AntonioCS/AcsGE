#include "UsesRenderer.h"

namespace AcsGameEngine::Uses {

    void UsesRenderer::setRenderer(Renderer* r)
    {
        m_renderer = r;
    }

    Renderer* UsesRenderer::getRenderer() const
    {
        return m_renderer;
    }
}
