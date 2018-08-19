#include "ColisionSystem.h"

#include "../Components/ColisionComponent.h"
#include "../Components/PositionComponent.h"

namespace AcsGameEngine::ECS {

	void ColisionSystem::init() {
		m_vecRef = m_entityManager.findByComponent<ColisionComponent, PositionComponent>();
	}

	void ColisionSystem::update(float dt) {

	}

	void ColisionSystem::render() {

	}
}