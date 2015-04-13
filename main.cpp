//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  None:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-12 21:04:09
// :ddddddddddhyyddddddddddd: Modified: 2015-04-13 00:44:33
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>
#include <SFML/Graphics.hpp>

#include <vector>

sf::RectangleShape *		make(sf::Rect<float> r)
{
	return new sf::RectangleShape(r.left, r.top, r.width, r.height);
}

int main(void)
{
	std::vector<char> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(rand() % 255);

	std::cout << "Hello WOrld" << std::endl;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return -1;

	sf::Texture Otex;
	if (!Otex.loadFromFile("O.png"))
		return -1;

	sf::Sprite sprite;
	sprite.setTexture(Otex);


	sf::RenderStates Otest(&Otex);

	int var = 10;

	// sf::Vertex vertices[] =
	// {
	// 	sf::Vertex(sf::Vector2f(  10,   10)), sf::Vertex(sf::Vector2f(  10, 200)),
	// 	sf::Vertex(sf::Vector2f(200, 200)), sf::Vertex(sf::Vector2f(200,   10))
	// 	,
	// 	sf::Vertex(sf::Vector2f(  10,   10)), sf::Vertex(sf::Vector2f(200,   10)),
	// 	sf::Vertex(sf::Vector2f(200, 200)), sf::Vertex(sf::Vector2f(  10, 200))
	// };

	// std::cout << vertices.length << std::endl;

	sf::CircleShape circle;
	circle.setRadius(150);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5);
	circle.setPosition(10, 20);

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					var++;
				else if (event.key.code == sf::Keyboard::Down)
					var--;
			}
		}
		sf::Text text(std::to_string(var), font, 50);
		// Clear screen
		window.clear();
		// Draw the string
		// window.draw(text);
		// window.draw(circle);
		// window.draw(vertices, 8, sf::Lines);

		window.draw(sprite);
		// Update the window
		window.display();
	}
}
