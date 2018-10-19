#include "SystemManager.h"
#include <algorithm>

namespace AcsGameEngine::ECS {
    void SystemManager::add(System&& system)
    {
        m_systems.push_back(system);
    }

    void SystemManager::init()
    {
        std::for_each(
            std::begin(m_systems), 
            std::end(m_systems),
            [](const System &system)
            {
                
            }
        );
    }
}
