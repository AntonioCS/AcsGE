#pragma once


#include "../System.h"

namespace AcsGameEngine::ECS {

	class ColisionSystem : public System
	{
	public:
		using System::System;

		~ColisionSystem() = default;

		void init();
		
		void update(float dt);

		void render();
	};
}