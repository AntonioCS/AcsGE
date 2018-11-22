#pragma once

#include <vector>
#include <memory> //unique_ptr
#include <functional> //std::reference_wrapper

namespace AcsGameEngine::ECS {
    class Entity;

    class EntityManager
    {
    public:
        EntityManager() = default;
        ~EntityManager() = default;

        Entity &make_entity();

        template<typename... Types>
        std::vector<std::reference_wrapper<Entity>> findByComponent() {
            std::vector<std::reference_wrapper<Entity>> ve;

            for (auto &e : m_entities) {
                if (e.get()->template  hasComponents<Types...>()) {
                    ve.push_back(*e);
                }
            }

            return ve;
        }

    private:
        std::vector<std::unique_ptr<Entity>> m_entities;
    };
}
