#pragma once

#include <chrono>
#include <exception>
#include "Entity.h"

namespace AcsGameEngine
{
    class Renderer;
}

namespace AcsGameEngine::ECS {
    using VecEntityRef = std::vector<std::reference_wrapper<Entity>>;

    class EntityManager;

    class System {
    protected:
        VecEntityRef m_vecRef;
        EntityManager *m_entityManager = nullptr;
    public:
        System() = default;
        virtual ~System() = default;

        void setEntityManager(EntityManager *em)
        {
            m_entityManager = em;
        }

        EntityManager *getEntityManager() const
        {
            if (m_entityManager == nullptr)
            {
                throw std::runtime_error{ "Entity Manager not set" };
            }
            return m_entityManager;
        }

        virtual void init() = 0;
        virtual void update(std::chrono::milliseconds) = 0;
        virtual void render(Renderer &renderer) = 0;
    };
}
