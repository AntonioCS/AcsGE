#include "SystemManager.h"
#include <algorithm>
#include <functional>

namespace AcsGameEngine::ECS {

    void loopSystems(std::vector<std::unique_ptr<System>> &vec,
        std::function<void(std::unique_ptr<System> &system)> func)
    {
        std::for_each(
            std::begin(vec),
            std::end(vec),
            func
        );
    }

    void SystemManager::init()
    {
        loopSystems(
            m_systems,
            [](std::unique_ptr<System> &system) {
                system->init();
            }
        );

        m_isInit = true;
    }

    void SystemManager::preUpdate(std::chrono::milliseconds ts)
    {
        loopSystems(
            m_systems,
            [&ts](std::unique_ptr<System> &system) {
                system->preUpdate(ts);
            }
        );
    }


    void SystemManager::update(std::chrono::milliseconds ts)
    {

        loopSystems(
            m_systems,
            [&ts](std::unique_ptr<System> &system) {
                system->update(ts);
            }
        );
    }

    void SystemManager::postUpdate(std::chrono::milliseconds ts)
    {
        loopSystems(
            m_systems,
            [&ts](std::unique_ptr<System> &system) {
                system->postUpdate(ts);
            }
        );
    }

    void SystemManager::preRender()
    {
        loopSystems(
            m_systems,
            [](std::unique_ptr<System> &system) {
                system->preRender();
            }
        );
    }

    void SystemManager::render()
    {
        loopSystems(
            m_systems,
            [](std::unique_ptr<System> &system) {
                system->render();
            }
        );
    }

    void SystemManager::postRender()
    {
        loopSystems(
            m_systems,
            [](std::unique_ptr<System> &system) {
                system->preRender();
            }
        );
    }

    void SystemManager::setup(Renderer* r, Window* w, EntityManager* em, GameState *gs)
    {
        m_renderer = r;
        m_window = w;
        m_entityManager = em;
        m_gameState = gs;
    }

    bool SystemManager::isInit() const noexcept
    {
        return m_isInit;
    }
}
