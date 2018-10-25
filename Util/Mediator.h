#pragma once

#include <unordered_map>
#include <vector>
#include <string>

namespace AcsGameEngine::Util {
    template <typename keyType, typename funcType>
    class Mediator {
    public:
        static const std::string defaultNameSpace;

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

        void attach(keyType eventName, funcType func) noexcept
        {
            attach(defaultNameSpace, eventName, func);
        }

        void attach(std::string nameSpace, keyType eventName, funcType func) noexcept
        {
            m_events[nameSpace][eventName] = func;
        }


        template <typename... Args>
        void trigger(keyType eventName, Args&&... args)
        {
            trigger(defaultNameSpace, eventName, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void trigger(std::string nameSpace, keyType eventName, Args&&... args)
        {
            if (m_events.find(nameSpace) != m_events.end()) {
                auto eventsGroup = m_events[nameSpace];

                if (eventsGroup.find(eventName) != eventsGroup.end()) {
                    eventsGroup[eventName](std::forward<Args>(args)...);
                }
            }
        }
    private:
        using keyFunc = std::unordered_map<keyType, funcType>;
        std::unordered_map<std::string, keyFunc> m_events;

    };

    template <typename keyType, typename funcType>
    const std::string Mediator<keyType, funcType>::defaultNameSpace{ "Global" };
}
