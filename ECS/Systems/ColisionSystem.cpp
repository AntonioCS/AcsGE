#include "ColisionSystem.h"

#include "../Components/CollisionComponent.h"
#include "../Components/PositionComponent.h"

namespace AcsGameEngine::ECS {

	void ColisionSystem::init() {
		m_vecRef = m_entityManager.findByComponent<CollisionComponent, PositionComponent>();
	}

	void ColisionSystem::update(float dt) {

	}

	void ColisionSystem::render() {

	}
}