#include "EntityManager.h"
#include "Entity.h"

namespace AcsGameEngine::ECS {

	EntityManager::EntityManager()
	{
	}

	EntityManager::~EntityManager()
	{
	}

	Entity & EntityManager::make_entity()
	{		
		return *(m_entities.emplace_back(new Entity));
	}
}