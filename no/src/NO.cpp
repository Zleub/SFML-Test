//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:NO
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-21 14:30:22
// :ddddddddddhyyddddddddddd: Modified: 2015-04-26 22:38:44
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include "NO.hpp"

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

std::string	no::getEventType(sf::Event::EventType e)
{
	if (e == sf::Event::Closed)
		return "Event::Closed";
	if (e == sf::Event::Resized)
		return "Event::Resized";
	if (e == sf::Event::LostFocus)
		return "Event::LostFocus";
	if (e == sf::Event::GainedFocus)
		return "Event::GainedFocus";
	if (e == sf::Event::TextEntered)
		return "Event::TextEntered";
	if (e == sf::Event::KeyPressed)
		return "Event::KeyPressed";
	if (e == sf::Event::KeyReleased)
		return "Event::KeyReleased";
	if (e == sf::Event::MouseWheelMoved)
		return "Event::MouseWheelMoved";
	if (e == sf::Event::MouseButtonPressed)
		return "Event::MouseButtonPressed";
	if (e == sf::Event::MouseButtonReleased)
		return "Event::MouseButtonReleased";
	if (e == sf::Event::MouseMoved)
		return "Event::MouseMoved";
	if (e == sf::Event::MouseEntered)
		return "Event::MouseEntered";
	if (e == sf::Event::MouseLeft)
		return "Event::MouseLeft";
	if (e == sf::Event::JoystickButtonPressed)
		return "Event::JoystickButtonPressed";
	if (e == sf::Event::JoystickButtonReleased)
		return "Event::JoystickButtonReleased";
	if (e == sf::Event::JoystickMoved)
		return "Event::JoystickMoved";
	if (e == sf::Event::JoystickConnected)
		return "Event::JoystickConnected";
	if (e == sf::Event::JoystickDisconnected)
		return "Event::JoystickDisconnected";
	return "Event::TOOMANYCOOKIE";
}
