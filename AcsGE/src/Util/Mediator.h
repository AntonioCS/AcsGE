#pragma once

#include <unordered_map>
#include <vector>

namespace AcsGameEngine::Util {
    template <typename keyType, typename funcType>
    class Mediator {
    public:
        void attach(keyType eventName, funcType func) noexcept
        {
            m_events[eventName].push_back(func);
        }

        template <typename... Args>
        void trigger(keyType eventName, Args... args)
        {
            if (m_events.find(eventName) != m_events.end()) {
                for (const auto& f : m_events[eventName]) {
                    f(args...);
                }
            }
        }

    private:
        std::unordered_map<keyType, std::vector<funcType>> m_events;
    };
}
