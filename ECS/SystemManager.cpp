#include "SystemManager.h"
#include <algorithm>

namespace AcsGameEngine::ECS {

    void SystemManager::init()
    {
        std::for_each(
            std::begin(m_systems), 
            std::end(m_systems),
            [](std::unique_ptr<System> &system)
            {
                system->init();
            }
        );
    }
}
