#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include <cassert>
#include <chrono>
#include "System.h"

namespace AcsGameEngine
{
    class Renderer;
    class Window;
}

namespace AcsGameEngine::ECS
{
    class EntityManager;

    class SystemManager
    {
    public:
        SystemManager(Renderer *r, Window *w, EntityManager *em) : m_renderer(r), m_window(w), m_entityManager(em) {}

        template <typename T, typename... TArgs>
        T& addSystem(TArgs&&... mArgs)
        {
            static_assert(std::is_base_of<System, T>::value, "T must inherit from System");
            auto &res = m_systems.emplace_back(std::make_unique<T>(std::forward<TArgs>(mArgs)...));

            res.get()->setEntityManager(m_entityManager);
            res.get()->setRenderer(m_renderer);
            res.get()->setWindow(m_window);

            return static_cast<T&>(*res);
        }

        void init();
        void update(std::chrono::milliseconds);
        void render();

    private:
        Renderer *m_renderer{nullptr};
        Window *m_window{nullptr};
        EntityManager *m_entityManager{nullptr};

        std::vector<std::unique_ptr<System>> m_systems;
    };
}
