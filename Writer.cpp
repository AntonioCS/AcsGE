#include "Writer.h"
#include "Renderer.h"

AcsGameEngine::Writer::Writer(Texture*t, const FontAtlas&fa) : m_fontTexture(t), m_fontAtlas(fa)
{

}

AcsGameEngine::Writer& AcsGameEngine::Writer::setBox(Util::Size size)
{
    m_boxSize = size;
    return *this;
}

AcsGameEngine::Writer& AcsGameEngine::Writer::setPosition(Util::Vector2D pos)
{
    m_pos = pos;
    return *this;
}

AcsGameEngine::Writer& AcsGameEngine::Writer::setColor(Util::Color c)
{
    m_color = c;
    return *this;
}

AcsGameEngine::Writer& AcsGameEngine::Writer::setText(std::string text)
{
    m_text = text;
    return *this;
}

AcsGameEngine::Writer& AcsGameEngine::Writer::setAlignment(Alignment a)
{
    m_alignment = a;
    return *this;
}

void AcsGameEngine::Writer::write(Renderer *renderer)
{
    createSpritesFromText();
    setFontSpritesPositioning();

    //default all white
    int r{255}, g{255}, b{255};
    
    if (m_color != Util::ColorList::_nocolor) {
        r = m_color.r;
        g = m_color.g;
        b = m_color.b;
    }
    
    SDL_SetTextureColorMod(m_fontTexture->getRawPointer(), r,g,b);

    for (const auto &fs : m_fontSprites) {
        renderer->drawSprite(&(fs.sprite));
    }

    //reset
    SDL_SetTextureColorMod(m_fontTexture->getRawPointer(), 255, 255, 255);
}

void AcsGameEngine::Writer::setTexture(Texture *t)
{
    m_fontTexture = t;
}

void AcsGameEngine::Writer::setFontAtlas(const FontAtlas& fa)
{
    m_fontAtlas = fa;
}

void AcsGameEngine::Writer::createSpritesFromText()
{
    m_fontSprites.clear();

    for (const auto &c : m_text) {

        auto gData = m_fontAtlas.getChar(c);

        if (!gData.has_value()) {
            throw std::logic_error{ "Requested unknown character from font map" };
        }

        Sprite2 s{ m_fontTexture };
        s.setPosition({ gData->x + gData->xoffset, gData->y });
        s.setSize({ gData->width, gData->height });        

        m_fontSprites.emplace_back(c, s, *gData);
    }
}

void AcsGameEngine::Writer::setFontSpritesPositioning()
{
    auto localPos = m_pos;
    const char *previousChar = nullptr;

    for (auto &s : m_fontSprites) {

        auto xoffset = s.gData.xoffset;

        if (s.c == '\n') {
            localPos.y += m_fontAtlas.getLineHeight();
            localPos.x = m_pos.x;
            previousChar = nullptr;
            continue;
        }


        if (!previousChar) {
            previousChar = &(s.c);
        }
        else {
            auto kerning = m_fontAtlas.getKerning(*previousChar, s.c);
            if (kerning) {
                xoffset += kerning->distance;
            }

            previousChar = &(s.c);
        }

        Util::Shapes::Rectangle destinationRect{
            {
                localPos.x + xoffset,
                localPos.y + s.gData.yoffset
            },
            {
                s.gData.width,
                s.gData.height
            }
        };

        s.sprite.setDestination(destinationRect);

        /*
        const auto bla = s.gData;

        std::cout << "Char: " << bla.c << '\n' <<
            "As int " << static_cast<int>(bla.c) << '\n' <<
            "x: " << bla.x << '\n' <<
            "y: " << bla.y << '\n' <<
            "width: " << bla.width << '\n' <<
            "height: " << bla.height << '\n' <<
            "xoffset: " << bla.xoffset << '\n' <<
            "yoffset: " << bla.yoffset << '\n' <<
            "xadvance: " << bla.xadvance << "\n";
        //*/

        localPos.x += s.gData.xadvance;
    }
}
