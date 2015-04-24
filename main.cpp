//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  None:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-12 21:04:09
// :ddddddddddhyyddddddddddd: Modified: 2015-04-24 21:36:24
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <SFML/Graphics.hpp>
#include <NO.hpp>

// namespace no {

	class Caca : public sf::Drawable, public no::Interactible {
	public:
		Caca(void);
		Caca(Caca const &);
		~Caca(void);

		Caca &			operator=(Caca const &);

		virtual void	draw(sf::RenderTarget &, sf::RenderStates) const ;

		void			setSprite(sf::Sprite);
		void			setTexture(sf::Texture);
	private:
		// sf::Sprite		_sprite;
		sf::Texture		_texture;
};

	Caca::Caca(void) {}
	Caca::~Caca(void) {}

	// void		Caca::setSprite(sf::Sprite _) { _sprite = _; }
	void		Caca::setTexture(sf::Texture _) { _texture = _; }

	void		Caca::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		sf::Sprite	tmp(_texture);

		target.draw(tmp, states);
	}

// } // no

typedef						void(* _fptr)(void);

sf::RenderWindow			window(sf::VideoMode(800, 600), "SFML window");

sf::RectangleShape *		make(sf::Rect<float> r)
{
	(void)r;
	sf::RectangleShape *	rect = new sf::RectangleShape();
	rect->setPosition(sf::Vector2f(r.left, r.top));
	rect->setSize(sf::Vector2f(r.width, r.height));

	return rect;
}

void		Hello(void)
{
	std::cout << "Hello World" << std::endl;
}

void		Mouse(void)
{
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	std::cout << "Mouse.x: " << pos.x << "Mouse.y: " << pos.y << std::endl;
}

int		main(void)
{
	std::map<sf::Event::EventType, _fptr>	reg;

	Caca caca;
	sf::Texture tex;
	tex.loadFromFile("O.png");

	caca.setTexture(tex);
	reg[sf::Event::KeyPressed] = Hello;
	reg[sf::Event::MouseMoved] = Mouse;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (reg[event.type])
				reg[event.type]();
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		caca.draw(window, sf::RenderStates());
		window.display();
	}
}
