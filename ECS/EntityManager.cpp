#include "EntityManager.h"
#include "Entity.h"

namespace AcsGameEngine::ECS {
    Entity & EntityManager::makeEntity()
    {
        return *(m_entities.emplace_back(new Entity));
    }
}