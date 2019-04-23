#pragma once
#include <unordered_map>
#include "Util/Vector2D.h"

namespace  AcsGameEngine {
    //class KeyboardManager;

   //class KeyboardManager;
    class MouseBtnData {
        //MouseManager::MouseBtns type;
        bool isClicked{ false };
        uint64_t startClickTs{ 0 };
        uint64_t endClickTs{ 0 };
    };

    class MouseManager
    {
    public:
        enum class MouseBtnTypes
        {
            BTN_LEFT,
            BTN_MIDDLE,
            BTN_RIGHT,
            BTN_X1,
            BTN_X2,
        };

        static MouseManager& getInstance();

        MouseManager(MouseManager const &) = delete;
        MouseManager(MouseManager &&) = delete;

        void operator=(MouseManager const &) = delete;
        void operator=(MouseManager &&) = delete;

        void recordLocation(int x, int y, int xrel, int yrel);

        ~MouseManager() = default;

        //void recordBtnDown(MouseBtnTypes btnType) 
        //void recordBtnUp(MouseBtnTypes btnType) 

        void setWheelScrollData(int x, int y) noexcept {
            m_scroll.x = x;
            m_scroll.y = y;
        }

        Util::Vector2D getWheelScrollData()
        {
            return m_scroll;
        }

        void setBtnState();

        bool isLeftBtnPressed() const noexcept;
        bool isRightBtnPressed() const noexcept;
    private:
        MouseManager() = default;

        std::unordered_map<MouseBtnTypes, MouseBtnData> m_btns{
            {MouseBtnTypes::BTN_LEFT, MouseBtnData()},
            {MouseBtnTypes::BTN_MIDDLE, MouseBtnData()},
            {MouseBtnTypes::BTN_RIGHT, MouseBtnData()},
            {MouseBtnTypes::BTN_X1, MouseBtnData()},
            {MouseBtnTypes::BTN_X2, MouseBtnData()},
        };

        //SDL_MOUSEMOTION
        Util::Vector2D m_location;
        Util::Vector2D m_locationRel;

        //SDL_MOUSEWHEEL
        Util::Vector2D m_scroll;
    };
}
