#include "System.h"


namespace AcsGameEngine::ECS {
    void System::setEntityManager(EntityManager* em)
    {
        m_entityManager = em;
    }

    EntityManager* System::getEntityManager() const
    {
        if (m_entityManager == nullptr)
        {
            throw std::runtime_error{"Entity Manager not set"};
        }

        return m_entityManager;
    }

    void System::setRenderer(Renderer *r)
    {
        m_renderer = r;
    }

    Renderer* System::getRenderer() const
    {
        return m_renderer;
    }

    void System::setWindow(Window *window)
    {
        m_window = window;
    }

    void System::setGameState(GameState *gs)
    {
        m_gameState = gs;
    }

    Window* System::getWindow() const
    {
        return m_window;
    }

    GameState* System::getGameState() const
    {
        return m_gameState;
    }

    void System::preUpdate(ms)
    {
    }

    void System::postUpdate(ms)
    {
    }

    void System::preRender()
    {
    }

    void System::postRender()
    {
    }
}
