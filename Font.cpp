#include "Font.h"
#include <iostream>

namespace AcsGameEngine {
    Font::Font() : Font(nullptr) //Font(nullptr)
    {
    }

    Font::Font(TTF_Font *font) : m_fontPtr(font, TTF_CloseFont)
    {
    }

    TTF_Font *Font::getRawPointer() const
    {
        return m_fontPtr.get();
    }
}
