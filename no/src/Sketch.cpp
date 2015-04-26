//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Sketch
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-26 17:31:45
// :ddddddddddhyyddddddddddd: Modified: 2015-04-26 22:41:50
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <Sketch.hpp>
#include <Cookbook.hpp>

std::ostream&		operator<<(std::ostream& os, const no::Sketch & s)
{
	return os << s.getName() << "\n" << s.getMap();
}
std::ostream&		operator<<(std::ostream& os, const no::Sketch * s)
{
	return os << s->getName() << "\n" << s->getMap();
}

namespace no {

	Sketch::Sketch(void) : _name("null") { Cookbook<Sketch>::add(this); }
	Sketch::Sketch(std::string texture_file) : _name(texture_file)
	{
		Cookbook<Sketch>::add(this);
		_texture.loadFromFile(texture_file);
	}
	Sketch::~Sketch(void) {}

	void				Sketch::setTexture(sf::Texture _) { _texture = _; }
	sf::Texture &		Sketch::getTexture(void) { return _texture; }
	std::string			Sketch::getName(void) const { return _name; }

	void				Sketch::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		sf::Sprite	tmp(_texture);

		target.draw(tmp, states);
	}

	sf::Rect<float>		Sketch::getLocalShape(void) const
	{
		sf::Sprite	tmp(_texture);

		return tmp.getLocalBounds();
	}

	sf::Rect<float>		Sketch::getGlobalShape(void) const
	{
		sf::Sprite	tmp(_texture);

		return tmp.getGlobalBounds();
	}

	void				Sketch::drawShape(sf::RenderTarget & target, std::string mode, sf::RenderStates states, std::string status) const
	{
		sf::Rect<float>		r;
		sf::RectangleShape	rect;

		if (status == "Local")
			r = getLocalShape();
		else
			r = getGlobalShape();

		rect.setPosition(sf::Vector2f(r.left, r.top));
		rect.setSize(sf::Vector2f(r.width, r.height));

		if (mode == "fill")
			rect.setFillColor(sf::Color::White);
		else
		{
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineColor(sf::Color::White);
			rect.setOutlineThickness(1);
		}

		target.draw(rect, states);
	}

} // no
