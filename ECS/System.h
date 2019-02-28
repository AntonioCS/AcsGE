#pragma once

#include <chrono>
#include <exception>
#include "Entity.h"

namespace AcsGameEngine {
    class Window;
    class Renderer;
}

namespace AcsGameEngine::ECS {
    using VecEntityRef = std::vector<std::reference_wrapper<Entity>>;

    class EntityManager;

    class System {
    protected:
        VecEntityRef m_vecRef;
    public:
        System() = default;
        virtual ~System() = default;

        void setEntityManager(EntityManager* em);
        EntityManager* getEntityManager() const;

        void setRenderer(Renderer *);
        Renderer *getRenderer() const;

        void setWindow(Window *);
        Window *getWindow() const;

        virtual void init() = 0;
        virtual void update(std::chrono::milliseconds) = 0;
        virtual void render() = 0;
    protected:
        template <typename T>
        static T msConvert(std::chrono::milliseconds ms) noexcept
        {
            return std::chrono::duration_cast<
                std::chrono::duration<T>
            >(ms).count();
        };
    private:
        Renderer *m_renderer = nullptr;
        Window *m_window = nullptr;
        EntityManager *m_entityManager = nullptr;
    };
}
