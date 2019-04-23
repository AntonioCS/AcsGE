#pragma once

#include <vector>

#include "FontAtlas.h"
#include "Texture.h"
#include "Sprite2.h"
#include "Util/Color.h"




namespace AcsGameEngine {

    class Renderer;
    
    //label = game.add.text(w/2, h/2, 'game over\n\nscore: '+score+'\n\npress the UP arrow key\nto restart',
        //{ font: '30px Arial', fill: '#fff', align: 'center' });
    //label.anchor.setTo(0.5, 0.5);
    class Writer
    {
        using Sprite2 = AcsGameEngine::Sprite2;
        using GlyphData = AcsGameEngine::FontAtlas::GlyphData;
    public:
        enum Alignment
        {
            LEFT,
            CENTER,
            RIGHT
        };

        Writer() = default;
        Writer(Texture *, const FontAtlas &);
        //Writer(Texture *, FontAtlas &, Util::Shapes::Rectangle);
        Writer &setBox(Util::Size size);
        Writer &setPosition(Util::Vector2D pos);
        Writer &setColor(Util::Color c);
        Writer &setText(std::string text);
        Writer &setAlignment(Alignment);

        void write(Renderer *);

        void setTexture(Texture *);
        void setFontAtlas(const FontAtlas &);


    private:
        struct FontSprite
        {
            char c;
            Sprite2 sprite;
            GlyphData gData;

            FontSprite(char c, Sprite2 s, GlyphData g) : c{c}, sprite{s}, gData{g} {}
        };

        std::vector<FontSprite> m_fontSprites;

        Texture *m_fontTexture;
        FontAtlas m_fontAtlas;

        Util::Color m_color{};
        Util::Size m_boxSize;
        Util::Vector2D m_pos;
        std::string m_text;
        Alignment m_alignment{ LEFT };

        void createSpritesFromText();
        void setFontSpritesPositioning();
    };
}
