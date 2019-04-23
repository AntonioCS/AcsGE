#include "FontAtlas.h"
#include <fstream>
#include <algorithm>

namespace AcsGameEngine {
    FontAtlas::FontAtlas(const std::string& filePath)
    {
        loadFromFile(filePath);
    }

    void FontAtlas::loadFromFile(const std::string& filePath) 
    {
        std::ifstream fontMapFile(filePath);

        if (fontMapFile) {
            m_charsData.clear();

            const auto stopOnSpace = [](const std::string &str, std::size_t start) {
                const auto max = str.length();

                while (start < max && str[start++] != ' ')
                    ;

                return (start < max ? --start : start);
            };
            const auto fetchItem = [&stopOnSpace](const std::string &line, const std::string &searchForStartOf) -> std::string
            {
                std::size_t f{ line.find(searchForStartOf) };
                std::size_t f2{};

                if (f != std::string::npos) {
                    f += searchForStartOf.length();
                    f2 = stopOnSpace(line, f);

                    return line.substr(f, f2 - f);
                }

                throw std::logic_error{ "Unable to find item: " + searchForStartOf };
            };
            const auto fillResultWithSearchData = [&fetchItem](const std::string &line, std::vector<std::string> findIn, std::vector<int> &result)
            {
                for (const auto &str : findIn) {
                    auto res = fetchItem(line, str);
                    result.push_back(std::stoi(res));
                }

                if (result.size() != findIn.size()) {
                    throw std::logic_error{ "Search error on: " + line };
                }
            };

            const std::vector<std::string> findInCharLine{
                "id=","x=","y=","width=","height=",
                "xoffset=","yoffset=","xadvance="
            };
            const std::vector<std::string> findInKerningLine{
                "first=", "second=", "amount="
            };            
            
            const std::vector<std::string> findInCommon{
                "lineHeight=", "base="
            };

            std::vector<int> result;
            std::string line;

            //Get info
            std::getline(fontMapFile, line);
            if (line.compare(0, 4, "info") == 0) {
                auto fontName = fetchItem(line, "face=\"");
                fontName.pop_back(); //remove last "

                m_fontInfo.name = fontName;
                m_fontInfo.size = std::stoi(fetchItem(line, "size="));
            }
            else {
                throw std::logic_error{ "Unable to extract font info" };
            }

            //Get common
            std::getline(fontMapFile, line);
            if (line.compare(0, 6, "common") == 0) {
                fillResultWithSearchData(line, findInCommon, result);

                m_fontInfo.lineHeight = result[0];
                m_fontInfo.base = result[1];

                result.clear();
            }
            else {
                throw std::logic_error{ "Unable to extract font info" };
            }

            while (std::getline(fontMapFile, line)) {
                if (line.compare(0, 8, "char id=") == 0) {
                    fillResultWithSearchData(line, findInCharLine, result);
            
                    m_charsData.emplace(
                        result[0],
                        GlyphData{ 
                            static_cast<char>(result[0]), 
                            result[1], result[2], result[3], result[4], result[5], result[6], result[7] 
                        }
                    );

                    result.clear();
                }

                if (line.compare(0,8,"kerning ") == 0) {
                    fillResultWithSearchData(line, findInKerningLine, result);

                    m_kernings.emplace_back(
                        static_cast<char>(result[0]),
                        static_cast<char>(result[1]),
                        result[2]
                    );

                    result.clear();
                }
            }

            m_hasData = true;
        }
        else {
            throw std::logic_error{ "Unable to open file: " + filePath };
        }
    }

    bool FontAtlas::hasData() const noexcept
    {
        return m_hasData;
    }

    std::optional<FontAtlas::GlyphData> FontAtlas::getChar(const char& c)
    {
        auto const cc = static_cast<int>(c);

        if (m_hasData && m_charsData.find(cc) != m_charsData.end()) {
            return std::make_optional(m_charsData[cc]);
        }

        return {};
    }

    std::optional<FontAtlas::Kerning> FontAtlas::getKerning(const char & first, const char & second)
    {

        const auto res = std::find_if(
            std::begin(m_kernings), 
            std::end(m_kernings),[&first, &second](const Kerning &k)
        {
            return (k.first == first && k.second == second);
        });

        if (res != m_kernings.end()) {
            return std::make_optional(*res);
        }

        return {}; //std::optional<Kerning>();
    }

    int FontAtlas::getBase() const noexcept
    {
        return m_fontInfo.base;
    }

    int FontAtlas::getLineHeight() const noexcept
    {
        return m_fontInfo.lineHeight;
    }

    int FontAtlas::getFontSize() const noexcept
    {
        return m_fontInfo.size;
    }

    std::string FontAtlas::getFontName() const noexcept
    {
        return m_fontInfo.name;
    }
}
