#pragma once

#include <unordered_map>
#include <string_view>
#include <string>
#include <vector>
#include <utility> //std::pair
#include <algorithm> //std::sort
#include <functional>

namespace AcsGameEngine::Util {      
    
    enum class MediatorMultiPriority
    {
        low,
        normal,
        high,
        critical
    };
    struct MediatorMultiDefaultValues
    {
        inline static const std::string_view tag{ "global" };
    };


    template <typename keyType, typename funcType>
    class MediatorMulti {
        struct EventDataObj
        {
            funcType func;
            MediatorMultiPriority priority{MediatorMultiPriority::normal};
            std::string tag{ MediatorMultiDefaultValues::tag };

            //this is needed for emplace_back
            EventDataObj(funcType f, MediatorMultiPriority p, std::string t) : func(f), priority(p), tag(t) {}
        };
    public:
        MediatorMulti() = default;
        virtual ~MediatorMulti() = default;

        MediatorMulti(const MediatorMulti& other) : m_events(other.m_events)
        {
        }

        MediatorMulti(MediatorMulti&& other) noexcept : m_events(std::move(other.m_events))
        {
        }

        MediatorMulti& operator=(const MediatorMulti& other)
        {
            if (this == &other)
                return *this;
            m_events = other.m_events;
            return *this;
        }

        MediatorMulti& operator=(MediatorMulti&& other) noexcept
        {
            if (this == &other)
                return *this;
            m_events = std::move(other.m_events);
            return *this;
        }
  
        void attach(
            keyType eventName, 
            funcType &&func, 
            MediatorMultiPriority priority = MediatorMultiPriority::normal, 
            std::string tag = std::string{ MediatorMultiDefaultValues::tag }) noexcept
        {
            m_isOrganized[eventName] = false;
            m_events[eventName].emplace_back(std::move(func), priority, tag);
        }

        template <typename... Args>
        void trigger(keyType eventName, Args&&... args)
        {
            makeSureKeySorted(eventName);
            
            auto res = m_events.find(eventName);

            if (res != m_events.end()) {
                for (const auto &eObj : res->second) {
                    if (!eObj.func(std::forward<Args>(args)...)) {
                        break;
                    }
                }                
            }
        }

        void remove(keyType eventName, std::string tag = std::string{ MediatorMultiDefaultValues::tag })
        {
            auto res = m_events.count(eventName);

            if (res) {
                
            }

            throw "NOT IMPLEMENTED";
        }

    private:
        using keyFunc = std::unordered_map<
                            keyType,
                            std::vector<EventDataObj>
                        >;
        keyFunc m_events;
        std::unordered_map<keyType, bool> m_isOrganized;
        std::string m_defaultTag{ "global" };

    private:
        void makeSureKeySorted(keyType eventName)
        {
            if (m_isOrganized.count(eventName) &&
                !m_isOrganized[eventName]) {

                std::sort(
                    m_events[eventName].begin(), m_events[eventName].end(),
                    [](const EventDataObj &a,  const EventDataObj &b) {
                        return a.priority > b.priority;
                    }
                );

                m_isOrganized[eventName] = true;
            }
        }
    };
}
