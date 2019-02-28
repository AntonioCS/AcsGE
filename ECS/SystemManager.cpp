#include "SystemManager.h"
#include <algorithm>
#include <functional>

#define LOOP_SYSTEMS(anonFunc) std::for_each( \
                                std::begin(m_systems), \
                                std::end(m_systems), \
                                anonFunc \
                            )
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
}
namespace AcsGameEngine::ECS {
    void SystemManager::init()
    {
        loopSystems(
            m_systems,
            [](std::unique_ptr<System> &system) {
                system->init();
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

    void SystemManager::render()
    {
        loopSystems(
            m_systems,
            [](std::unique_ptr<System> &system) {
                system->render();
            }
        );
    }
}