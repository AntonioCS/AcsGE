#pragma once

#include <vector>
#include <memory>

namespace AcsGameEngine {

    template<typename PointerType>
    class grouping {
    protected:
        std::vector<PointerType> m_group;
    public:

        template<typename Type, typename ...TArgs>
        void add(TArgs&& ...args) {
            m_group.push_back(std::make_unique<Type>(std::forward<TArgs>(args)...));            
        }
    };
}