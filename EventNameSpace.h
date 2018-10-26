#pragma once

#include <functional>
#include "Util/Mediator.h"
#include "EventData.h"

namespace AcsGameEngine {

    using Util::Mediator;
    using eventFunc = std::function<void(EventData &eventData)>;

    class EventNameSpace : public Mediator<uint32_t, eventFunc>
    {
    public:
        EventNameSpace(EventNameSpace *parent, std::string name)
            : m_parent(parent), m_name(name) {}
        EventNameSpace(std::string name) : EventNameSpace(nullptr, name) {}
        ~EventNameSpace() = default;


    private:
        EventNameSpace *m_parent;
        std::string m_name;
        std::vector<EventNameSpace> m_children;

    };
}