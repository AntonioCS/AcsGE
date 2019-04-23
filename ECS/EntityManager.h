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

        Entity &makeEntity();

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

        template<typename... Types>
        std::vector<Entity *> findByComponent2() {
            std::vector<Entity *> ve;

            for (auto &e : m_entities) {
                if (e.get()->template  hasComponents<Types...>()) {
                    ve.push_back(&(*e));
                }
            }

            return ve;
        }

        template<typename ComponentType>
        Entity &findOneByComponent()
        {
            auto res = findByComponent<ComponentType>();

            if (res.size() > 0) {
                return res[0];
            }

            throw std::logic_error{ "Component not found" };
        }

        template<typename ComponentType>
        Entity *findOneByComponent2()
        {
            auto res = findByComponent2<ComponentType>();

            if (res.size() > 0) {
                return res[0];
            }

            return nullptr;
        }

    private:
        std::vector<std::unique_ptr<Entity>> m_entities;
    };
}
