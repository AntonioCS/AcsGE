#pragma once

#include <chrono>
#include <functional>
#include <algorithm>

#include "ECS/System.h"
#include "Renderer.h"
#include "Window.h"
#include "Uses/UsesRenderer.h"

namespace AcsGameEngine
{
    class GameStateManager;
    class EventManager;
    class AssetManager;

    class GameState : public Uses::UsesRenderer
    {
    public:
        GameState() = default;
        virtual ~GameState() = default;

        virtual void init();
        virtual void handleEvents();
        virtual void update(std::chrono::milliseconds deltaTime);
        virtual void render();
        virtual std::string getName() const noexcept = 0;

        void setGameStateManager(GameStateManager *gsm);
        GameStateManager *getGameStateManager() const;

        void setWindow(Window *window);
        Window *getWindow() const;

        AssetManager* getAssetManager() const;
        void setAssetManager(AssetManager* asset_manager);

        EventManager *getEventManager() const;
        void setEventManager(EventManager *eventManager);
    protected:
        using SysPtr = std::unique_ptr<ECS::System>;
        using SysFunc = std::function<void(SysPtr &sys)>;

        GameStateManager &getGSM() const noexcept;

        void loopAction(SysFunc func)
        {
            std::for_each(
                std::begin(m_systems),
                std::end(m_systems),
                func
            );
        }
    private:
        GameStateManager *m_gameStateManager{nullptr};
        AssetManager *m_assetManager;
        EventManager *m_eventManager;

        Window *m_window{nullptr};
        std::vector<SysPtr> m_systems;
    };
}
