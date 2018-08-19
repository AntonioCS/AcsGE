#pragma once


#include "../System.h"
#include "../EntityManager.h"
#include "../Entity.h"
#include "../../Renderer.h"

namespace AcsGameEngine::ECS {

	class RendererSystem : public System
	{
		Renderer &m_renderer;
	public:
		RendererSystem(EntityManager &em, Renderer &renderer);
		~RendererSystem();

		void init();

		void update(float dt);

		void render();
	};
}