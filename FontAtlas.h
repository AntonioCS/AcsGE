#pragma once

#include <string>
#include <vector>
#include <optional>
#include <unordered_map>

//http://www.angelcode.com/products/bmfont/doc/file_format.html
namespace AcsGameEngine {
    class FontAtlas
    {
    public:
        struct GlyphData
        {
            char c{};
            int x{};
            int y{};
            int width{};
            int height{};
            int xoffset{};
            int yoffset{};
            int xadvance{};
        };

        struct Kerning
        {
            char first{};
            char second{};
            int distance{0};

            Kerning() = default;
            Kerning(char f, char s, int d) : first(f), second(s), distance(d) {}
        };

        struct FontInfo
        {
            std::string name{};
            int size{};
            int lineHeight{};
            int base{};
        };

        FontAtlas() = default;
        FontAtlas(const std::string& filePath);

        void loadFromFile(const std::string& filePath);
        bool hasData() const noexcept;
        std::optional<GlyphData> getChar(const char& c);
        std::optional<Kerning> getKerning(const char &first, const char &second);

        int getFontSize() const noexcept;
        std::string getFontName() const noexcept;
        int getBase() const noexcept;
        int getLineHeight() const noexcept;

    private:
        std::unordered_map<int, GlyphData> m_charsData;
        std::vector<Kerning> m_kernings;

        bool m_hasData{ false };
        std::string m_file;

        FontInfo m_fontInfo;
    };
}
