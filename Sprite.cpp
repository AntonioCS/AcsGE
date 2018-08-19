#include "Sprite.h"
#include "Renderer.h"
#include "Texture.h"
#include "Window.h"

namespace AcsGameEngine {
/*	Sprite::Sprite() : m_texture(nullptr)
	{

	}*/

	Sprite::Sprite(Texture &texture, SDL_Rect source) : m_texture(texture), m_source(source)
	{
		m_destination.w = m_source.w;
		m_destination.h = m_source.h;
	}	

	Sprite::Sprite(Sprite&& other)
		: m_texture(other.m_texture)
		, m_destination(std::move(other.m_destination))
		, m_source(std::move(other.m_source))
	{
	}

	Sprite::~Sprite()
	{
	}

	void Sprite::setSourceDestination(SDL_Rect source, SDL_Rect destination)
	{
		m_source = std::move(source);
		m_destination = std::move(destination);
	}

	void Sprite::setSource(const SDL_Rect& r)
	{
		setSourceXYWH(r.x, r.y, r.w, r.h);
	}

	void Sprite::setSourceXYWH(int x, int y, int w, int h)
	{
		m_source.x = x;
		m_source.y = y;
		m_source.w = w;
		m_source.h = h;
	}

	void Sprite::setDestinationXYWH(int x, int y, int w, int h)
	{
		m_destination.x = x;
		m_destination.y = y;
		m_destination.w = w;
		m_destination.h = h;
	}

	void Sprite::setSourceXY(int x, int y)
	{
		m_source.x = x;
		m_source.y = y;
	}

	void Sprite::setSourceWH(int w, int h)
	{
		m_source.w = w;
		m_source.h = h;
	}

	void Sprite::setDestinationXY(int x, int y)
	{
		m_destination.x = x;
		m_destination.y = y;
	}

	void Sprite::setDestinationWH(int w, int h)
	{
		m_destination.w = w;
		m_destination.h = h;
	}

	void Sprite::setCenter()
	{
		m_destination.x = -1;
		m_destination.y = -1;
	}
	//*/

	std::pair<int, int> Sprite::getDestinationPoint() const noexcept
	{
		return { m_destination.x, m_destination.y };
	}
	SDL_Rect Sprite::getDestination() const noexcept
	{
		return m_destination;
	}
	SDL_Rect Sprite::getSource() const noexcept
	{
		return m_source;
	}
	const Texture & Sprite::getTexture() const noexcept
	{
		return m_texture;
	}

} // namespace AcsGameEngine
