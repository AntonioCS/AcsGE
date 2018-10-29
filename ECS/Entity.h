#pragma once

#include <memory>
#include <unordered_map>
#include <type_traits>
#include <exception>
#include <cassert>

#include "Component.h"

namespace AcsGameEngine::ECS {

	class Entity {
	public:
		using ComponentId = std::size_t;
		using ComponentPtr = std::unique_ptr<Component>;
	private:
		std::unordered_map<ComponentId, ComponentPtr> m_components;

		ComponentId getUniqueComponentId() {
			static ComponentId uId{ 0 };
			return uId++;
		}

		template<typename T>
		ComponentId getComponentId() {
			static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
			static ComponentId id{ getUniqueComponentId() };
			return id;
		}

	public:

		template<typename T, typename... TArgs>
		T& addComponent(TArgs&&... mArgs) {
			assert(!hasComponent<T>());

			auto ComponentKey = getComponentId<T>();

			m_components.insert(std::make_pair(ComponentKey, std::make_unique<T>(std::forward<TArgs>(mArgs)...)));
			m_components[ComponentKey]->parentEntity = this;

			return *static_cast<T*>(m_components[ComponentKey].get());
			//return *reinterpret_cast<T*>(m_components[ComponentKey].get());
		}

		template<typename T>
		T& getComponent() {
			auto ComponentKey = getComponentId<T>();
			auto result = m_components.find(ComponentKey);

			if (result != m_components.end()) {
				return *static_cast<T*>(result->second.get());

				//https://github.com/SuperV1234/Tutorials/blob/master/DiveIntoC%2B%2B11/5_Entities/p9.cpp#L131
				//Will cause read access violation
				//return *reinterpret_cast<T*>(result->second.get());
			}

			throw std::exception{ "No matching Component" };
		}

		template<typename T>
		bool hasComponent() {
			auto ComponentKey = getComponentId<T>();
			return (m_components.find(ComponentKey) != m_components.end());
		}

		template<typename T, typename... MoreComponents>
		bool hasComponents() {
			if constexpr (sizeof...(MoreComponents) == 0) {
				return hasComponent<T>();
			}
			else {
				return hasComponent<T>() && hasComponents<MoreComponents...>();
			}
		}
	};
}
