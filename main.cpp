//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  None:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-12 21:04:09
// :ddddddddddhyyddddddddddd: Modified: 2015-04-21 14:31:04
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

#include "NO.hpp"

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

int		main(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	typedef		void(* _fptr)(void);
	no::Registry<sf::Event::EventType, _fptr>	reg;

	reg.load(new no::Register<sf::Event::EventType, _fptr>(sf::Event::KeyPressed, Hello));
	reg.load(new no::Register<sf::Event::EventType, _fptr>(sf::Event::KeyPressed, Hello));
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			reg.update(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
}
