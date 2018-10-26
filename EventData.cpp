#include "EventData.h"

namespace  AcsGameEngine {
    EventData::EventData(SDL_Event &event) : m_event(event)
    {
        
    }

    void EventData::stopPropagation()
    {
        m_propagate = false;
    }
}
