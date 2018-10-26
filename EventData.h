#pragma once

union SDL_Event;

namespace AcsGameEngine {

    class EventData
    {
    public:
        EventData(SDL_Event &event);
        ~EventData() = default;    

        void stopPropagation();
    private:
        bool m_propagate{ true };
        SDL_Event &m_event;
    };
}