#pragma once


namespace AcsGameEngine {
    class Renderer;
}

namespace AcsGameEngine::Uses {

    class UsesRenderer
    {
    public:
        void setRenderer(Renderer *r);
        Renderer *getRenderer() const;
    private:
        Renderer *m_renderer = nullptr;
    };
}