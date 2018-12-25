#pragma once

#include <unordered_map>
#include <vector>
#include <string>

namespace AcsGameEngine::Util {
    template <typename keyType, typename funcType>
    class Mediator {
    public:
        Mediator() = default;
        virtual ~Mediator() = default;

        Mediator(const Mediator& other) : m_events(other.m_events)
        {
        }

        Mediator(Mediator&& other) noexcept : m_events(std::move(other.m_events))
        {
        }

        Mediator& operator=(const Mediator& other)
        {
            if (this == &other)
                return *this;
            m_events = other.m_events;
            return *this;
        }

        Mediator& operator=(Mediator&& other) noexcept
        {
            if (this == &other)
                return *this;
            m_events = std::move(other.m_events);
            return *this;
        }

        void attach(keyType eventName, funcType &&func) noexcept
        {
            m_events[eventName] = std::move(func);
        }

        template <typename... Args>
        void trigger(keyType eventName, Args&&... args)
        {
            if (m_events.find(eventName) != m_events.end()) {
                m_events[eventName](std::forward<Args>(args)...);
            }
        }
    private:
        using keyFunc = std::unordered_map<keyType, funcType>;
        keyFunc m_events;
    };
}
