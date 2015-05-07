//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  None:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-12 21:04:09
// :ddddddddddhyyddddddddddd: Modified: 2015-04-28 20:48:31
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <SFML/Graphics.hpp>
#include <NO.hpp>
#include <Sketch.hpp>
#include <Cookbook.hpp>

// std::ostream&		operator<<(std::ostream& os, const sf::Event::EventType & e)
// {
// 	return os << no::getEventType(e);
// }
// std::ostream&		operator<<(std::ostream& os, const sf::Event::EventType * e)
// {
// 	return os << no::getEventType(*e);
// }

sf::RenderWindow			window(sf::VideoMode(800, 600), "SFML window");

void		Hello(void)
{
	std::cout << "Hello World" << std::endl;
}

void		Mouse(void)
{
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	std::cout << "Mouse.x: " << pos.x << "\tMouse.y: " << pos.y << std::endl;
}

int		main(void)
{
	// std::map<sf::Event::EventType, _fptr>	reg;

	typedef sf::Event::EventType		Event;
	typedef no::_fptr					fptr;
	typedef no::Sketch<Event, fptr>		Sketch;

	Sketch sketch1("res/O.png");
	Sketch sketch2("res/apple.png");

	std::cout << (void*)Hello << std::endl;
	std::cout << (void*)Mouse << std::endl;

	sketch1[sf::Event::MouseMoved] = Mouse;
	sketch1[sf::Event::KeyPressed] = Hello;
	sketch2[sf::Event::MouseMoved] = Mouse;

	// c++ doesn't like very much types
	no::Cookbook<Sketch>::print();
	// no::Cookbook<no::Interactible<sf::Event::EventType, no::_fptr> >::print();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sketch1[event.type])
				sketch1[event.type]();
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		sketch1.drawShape(window, "line");
		sketch1.draw(window, sf::RenderStates());
		sketch2.drawShape(window, "line");
		sketch2.draw(window, sf::RenderStates());
		window.display();
	}
}
