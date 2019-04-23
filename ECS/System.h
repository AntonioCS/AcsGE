#pragma once

#include <chrono>
#include <exception>
#include "Entity.h"

namespace AcsGameEngine {
    class Window;
    class Renderer;
    class GameState;
}

namespace AcsGameEngine::ECS {
    using VecEntityRef = std::vector<std::reference_wrapper<Entity>>;
    using ms = std::chrono::milliseconds;
    class EntityManager;

    class System {
    protected:
        VecEntityRef m_vecRef;
    public:
        System() = default;
        virtual ~System() = default;

        void setEntityManager(EntityManager* em);
        void setRenderer(Renderer *);
        void setWindow(Window *);
        void setGameState(GameState *);

        EntityManager* getEntityManager() const;
        Renderer *getRenderer() const;
        Window *getWindow() const;
        GameState *getGameState() const;

        virtual void init() = 0;

        virtual void preUpdate(ms);
        virtual void update(ms) = 0;
        virtual void postUpdate(ms);

        virtual void preRender();
        virtual void render() = 0;
        virtual void postRender();
    protected:
        template <typename T>
        static T msConvert(std::chrono::milliseconds ms) noexcept
        {
            return std::chrono::duration_cast<
                std::chrono::duration<T>
            >(ms).count();
        };
    private:
        Renderer *m_renderer{ nullptr };
        Window *m_window{ nullptr };
        EntityManager *m_entityManager{ nullptr };
        GameState *m_gameState{ nullptr };
    };
}
