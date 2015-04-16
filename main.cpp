//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  None:main
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-12 21:04:09
// :ddddddddddhyyddddddddddd: Modified: 2015-04-16 04:39:03
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

namespace no {

	typedef		void(* _fptr)(void);

	void		printEventType(sf::Event::EventType e)
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

	class Function {
	public:
		Function(void);
		Function(_fptr);
		Function(Function const &);
		~Function(void);

		Function &	operator=(Function const &);

		void			callFunction(void);
		_fptr			getFunction(void) const ;
	private:
		void	(* _function)(void);
	};

	Function::Function(void) : _function(NULL) {}
	Function::Function(_fptr p) : _function(p) {}
	Function::Function(Function const & src) { *this = src; }
	Function::~Function(void) {}
	Function &	Function::operator=(Function const & rhs) { _function = rhs.getFunction(); return *this; }

	void			Function::callFunction(void) { _function(); }
	_fptr			Function::getFunction(void) const { return _function; }

	class Register {
	public:
		Register(void);
		Register(sf::Event::EventType, no::Function);
		Register(Register const &);
		~Register(void);

		Register &	operator=(Register const &) ;

		sf::Event::EventType	getEvent(void) const ;
		no::Function			getFunction(void) const ;
	private:
		sf::Event::EventType	_event;
		no::Function			_function;
	};
	Register::Register(void) {} // Should throw an exception
	Register::Register(sf::Event::EventType e, no::Function f) : _event(e), _function(f) {}
	Register::Register(Register const & src) { *this = src; }
	Register::~Register(void) {}

	Register &				Register::operator=(Register const & rhs) {
		_event = rhs.getEvent();
		_function = rhs.getFunction();
		return *this;
	}

	bool					operator==(const Register * lhs, const sf::Event::EventType & rhs) {
		return (lhs->getEvent() == rhs);
	}
	// bool					Register::operator==(sf::Event const & rhs) {
	// 	return (_event == rhs.type);
	// }

	sf::Event::EventType	Register::getEvent(void) const { return _event; }
	no::Function			Register::getFunction(void) const { return _function; }

	class Registry {
	public:
		Registry(void);
		Registry(Registry const &);
		~Registry(void);

		Registry &	operator=(Registry const &);

		void		load(Register *);
		void		update(sf::Event);
	private:
		std::vector<no::Register *>		_vector;
	};

	Registry::Registry(void) {}
	Registry::~Registry(void) {}

	void		Registry::load(Register * r) {
		std::vector<no::Register *>::iterator it;

		it = find(_vector.begin(), _vector.end(), r->getEvent());
		if (it == _vector.end()) {
			_vector.push_back(r);
			std::cout << "push event : " ;
			printEventType(r->getEvent());
			std::cout << std::endl;
		}
		else
		{
			std::cout << "event already present : " ;
			printEventType(r->getEvent());
			std::cout << std::endl;
		}
	}
	void		Registry::update(sf::Event e) {
		(void)e;
		std::vector<no::Register *>::iterator it;

		it = find(_vector.begin(), _vector.end(), e.type);
		if (it == _vector.end()) {
			// std::cout << "no such event : " ;
			// printEventType(e.type);
			// std::cout << std::endl;
		}
		else {
			std::cout << "event called: ";
			printEventType(e.type);
			std::cout << std::endl;
			(*it)->getFunction().callFunction();
		}
	}

} // no

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
	no::Registry	reg;

	reg.load(new no::Register(sf::Event::KeyPressed, Hello));
	reg.load(new no::Register(sf::Event::KeyPressed, Hello));
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

// int main(void)
// {
// 	std::vector<char> v;
// 	for (int i = 0; i < 10; ++i)
// 		v.push_back(rand() % 255);

// 	std::cout << "Hello WOrld" << std::endl;

// 	sf::Font font;
// 	if (!font.loadFromFile("arial.ttf"))
// 		return -1;

// 	sf::Texture Otex;
// 	if (!Otex.loadFromFile("O.png"))
// 		return -1;

// 	sf::Sprite sprite(Otex);
// 	sprite.setPosition(100, 100);

// 	sf::RenderStates Otest(&Otex);

// 	int var = 0;

// 	// sf::Vertex vertices[] =
// 	// {
// 	// 	sf::Vertex(sf::Vector2f( 150, 150), sf::Vector2f( 100, 100)),
// 	// 	sf::Vertex(sf::Vector2f( 100,  50), sf::Vector2f( 100,   0)),
// 	// 	sf::Vertex(sf::Vector2f(  50,  50), sf::Vector2f(   0,   0)),
// 	// 	sf::Vertex(sf::Vector2f(  50, 100), sf::Vector2f(   0, 100))
// 	// };

// 	// std::cout << vertices.length << std::endl;

// 	sf::CircleShape circle;
// 	circle.setRadius(150);
// 	circle.setOutlineColor(sf::Color::Red);
// 	circle.setOutlineThickness(5);
// 	circle.setPosition(10, 20);

// 	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
// 	while (window.isOpen())
// 	{
// 		// Process events
// 		sf::Event event;
// 		while (window.pollEvent(event))
// 		{
// 			// Close window: exit
// 			if (event.type == sf::Event::Closed)
// 				window.close();
// 			if (event.type == sf::Event::KeyPressed)
// 			{
// 				if (event.key.code == sf::Keyboard::Up)
// 					var += 2;
// 				else if (event.key.code == sf::Keyboard::Down)
// 					var -= 2;
// 				else if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift)
// 					std::cout << "Shift" << std::endl;
// 			}
// 			if (event.type == sf::Event::TextEntered)
// 				std::cout << "TextEntered : " << event.text.unicode << std::endl;
// 		}
// 		sf::Text text(std::to_string(var), font, 50);
// 		// Clear screen
// 		window.clear();
// 		// Draw the string
// 		// window.draw(text);
// 		// window.draw(circle);

// 		sprite.setRotation(var);

// 		float x, y;
// 		sf::Vector2i i = sf::Mouse::getPosition(window);
// 		x = i.x;
// 		y = i.y;
// 		sprite.setPosition(x, y);

// 	sf::Vertex vertices[] =
// 	{
// 		sf::Vertex(sf::Vector2f( 300 + x, 300 + y), sf::Vector2f( 100, 100)),
// 		sf::Vertex(sf::Vector2f( 300, 200), sf::Vector2f( 100,   0)),
// 		sf::Vertex(sf::Vector2f( 200, 200), sf::Vector2f(   0,   0))
// 		,
// 		sf::Vertex(sf::Vector2f( 200, 300), sf::Vector2f(   0, 100))
// 	};

// 		// sf::RectangleShape * caca = make(sprite.getGlobalBounds());
// 		// window.draw(*caca);
// 		// window.draw(sprite);

// 		window.draw(vertices, 4, sf::Quads);
// 		// Update the window
// 		window.display();
// 	}
// }
