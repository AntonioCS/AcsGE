#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include <chrono>

#include "System.h"
#include "../Renderer.h"

namespace AcsGameEngine
{
    class Renderer;
    class Window;
    class GameState;
}

namespace AcsGameEngine::ECS
{
    class EntityManager;

    class SystemManager
    {
    public:
        SystemManager() = default;
        SystemManager(Renderer *r, Window *w, EntityManager *em) : m_renderer(r), m_window(w), m_entityManager(em) {}

        template <typename T, typename... TArgs>
        T& addSystem(TArgs&&... mArgs)
        {
            static_assert(std::is_base_of<System, T>::value, "T must inherit from System");

            auto &res = m_systems.emplace_back(std::make_unique<T>(std::forward<TArgs>(mArgs)...));

            res->setEntityManager(m_entityManager);
            res->setRenderer(m_renderer);
            res->setWindow(m_window);
            res->setGameState(m_gameState);

            return static_cast<T&>(*res);
        }

        void init();

        void preUpdate(std::chrono::milliseconds);
        void update(std::chrono::milliseconds);
        void postUpdate(std::chrono::milliseconds);

        void preRender();
        void render();
        void postRender();

        void setup(Renderer *r, Window *w, EntityManager *em, GameState *gs);

        bool isInit() const noexcept;
    private:
        Renderer *m_renderer{nullptr};
        Window *m_window{nullptr};
        EntityManager *m_entityManager{nullptr};
        GameState *m_gameState{ nullptr };
        bool m_isInit{ false };

        std::vector<std::unique_ptr<System>> m_systems;
    };
}
