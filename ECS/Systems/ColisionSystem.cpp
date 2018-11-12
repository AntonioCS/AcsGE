#include "ColisionSystem.h"

#include "../Components/CollisionComponent.h"
#include "../Components/PositionComponent.h"
#include "../EntityManager.h"

namespace AcsGameEngine::ECS {

	void ColisionSystem::init() {
		m_vecRef = getEntityManager()->findByComponent<CollisionComponent, PositionComponent>();
	}

	void ColisionSystem::update(float dt) {

	}

	void ColisionSystem::render() {

	}
}