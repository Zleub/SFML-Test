//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  None:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-12 21:04:09
// :ddddddddddhyyddddddddddd: Modified: 2015-04-20 16:51:56
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
#include "Function.hpp"
#include "Register.hpp"
#include "Registry.hpp"

void		no::printEventType(sf::Event::EventType e)
{
	if (e == sf::Event::Closed)
		std::cout << "Event::Closed";
	if (e == sf::Event::Resized)
		std::cout << "Event::Resized";
	if (e == sf::Event::LostFocus)
		std::cout << "Event::LostFocus";
	if (e == sf::Event::GainedFocus)
		std::cout << "Event::GainedFocus";
	if (e == sf::Event::TextEntered)
		std::cout << "Event::TextEntered";
	if (e == sf::Event::KeyPressed)
		std::cout << "Event::KeyPressed";
	if (e == sf::Event::KeyReleased)
		std::cout << "Event::KeyReleased";
	if (e == sf::Event::MouseWheelMoved)
		std::cout << "Event::MouseWheelMoved";
	if (e == sf::Event::MouseButtonPressed)
		std::cout << "Event::MouseButtonPressed";
	if (e == sf::Event::MouseButtonReleased)
		std::cout << "Event::MouseButtonReleased";
	if (e == sf::Event::MouseMoved)
		std::cout << "Event::MouseMoved";
	if (e == sf::Event::MouseEntered)
		std::cout << "Event::MouseEntered";
	if (e == sf::Event::MouseLeft)
		std::cout << "Event::MouseLeft";
	if (e == sf::Event::JoystickButtonPressed)
		std::cout << "Event::JoystickButtonPressed";
	if (e == sf::Event::JoystickButtonReleased)
		std::cout << "Event::JoystickButtonReleased";
	if (e == sf::Event::JoystickMoved)
		std::cout << "Event::JoystickMoved";
	if (e == sf::Event::JoystickConnected)
		std::cout << "Event::JoystickConnected";
	if (e == sf::Event::JoystickDisconnected)
		std::cout << "Event::JoystickDisconnected";
}

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
