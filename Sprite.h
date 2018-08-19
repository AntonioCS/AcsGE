#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <memory>
#include "Texture.h"

namespace AcsGameEngine {


	class Sprite {
	private:
		Texture & m_texture;// = nullptr;
		SDL_Rect m_source{ 0, 0, 0, 0 };
		SDL_Rect m_destination{ 0, 0, 0, 0 };

	public:
		Sprite(Texture &texture, SDL_Rect);
		Sprite(Sprite&& other);
		virtual ~Sprite();

		void setSourceDestination(SDL_Rect, SDL_Rect);
		void setSource(const SDL_Rect&);

		void setSourceXYWH(int, int, int, int);
		void setDestinationXYWH(int, int, int, int);

		void setSourceXY(int, int);
		void setDestinationXY(int, int);

		void setSourceWH(int, int);
		void setDestinationWH(int, int);

		void setCenter();

		std::pair<int, int> getDestinationPoint() const noexcept;
		SDL_Rect getDestination() const noexcept;
		SDL_Rect getSource() const noexcept;

		const Texture& getTexture() const noexcept;
	};
}  // namespace AcsGameEngine
#endif /* SPRITE_H */
