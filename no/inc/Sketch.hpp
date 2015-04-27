//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Sketch
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-26 17:31:23
// :ddddddddddhyyddddddddddd: Modified: 2015-04-27 18:13:05
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SKETCH_HPP
#define SKETCH_HPP

#include <NO.hpp>
#include <Interactible.hpp>
#include <Cookbook.hpp>

namespace no {

	template<typename Key, typename Val>
	class Sketch : public sf::Drawable, public Interactible<Key, Val> {
	public:
		/*! \brief Standard Sketch constructor
		 */
		Sketch(void);
		/*! \brief FromFile Sketch constructor
		 */
		Sketch(std::string);
		/*! \brief FromSketch Sketch constructor /!\ Indefined
		 */
		Sketch(Sketch const &);
		~Sketch(void);

		/*! \brief Standard Sketch assignator /!\ Indefined
		 */
		Sketch &					operator=(Sketch const &);

		/*! \brief Standard draw method
		 *
		 * mode can either be "fill" or "line". Everything else leads to "line".
		 */
		void			draw(sf::RenderTarget &, sf::RenderStates) const ;

		/*! \brief Debug draw method
		 *
		 * mode can either be "fill" or "line". Everything else leads to "line".\n
		 * status can either be "Local" or "Global". Everything else leads to "Global".
		 */
		void			drawShape(
							sf::RenderTarget &,
							std::string modem,
							sf::RenderStates states = sf::RenderStates::Default,
							std::string status = "Global"
						) const ;

		/*! \brief Texture Utility
		 */
		void			setTexture(sf::Texture);
		/*! \brief Texture Utility
		 */
		sf::Texture &	getTexture(void) ;
		/*! \brief Texture Utility
		 */
		std::string		getName(void) const ;
	private:
		std::string		_name;
		sf::Texture		_texture;

		sf::Rect<float>	getLocalShape(void) const ;
		sf::Rect<float>	getGlobalShape(void) const ;
	};

	template<typename Key, typename Val>
		Sketch<Key, Val>::Sketch(void) : _name("null")
		{
			Cookbook<Sketch<Key, Val> >::add(this);
		}
	template<typename Key, typename Val>
		Sketch<Key, Val>::Sketch(std::string texture_file) : _name(texture_file)
		{
			Cookbook<Sketch<Key, Val> >::add(this);
			_texture.loadFromFile(texture_file);
		}
	template<typename Key, typename Val>
		Sketch<Key, Val>::~Sketch(void) {}

	template<typename Key, typename Val>
		void				Sketch<Key, Val>::setTexture(sf::Texture _) { _texture = _; }
	template<typename Key, typename Val>
		sf::Texture &		Sketch<Key, Val>::getTexture(void) { return _texture; }
	template<typename Key, typename Val>
		std::string			Sketch<Key, Val>::getName(void) const { return _name; }

	template<typename Key, typename Val>
		void				Sketch<Key, Val>::draw(sf::RenderTarget & target, sf::RenderStates states) const
		{
			sf::Sprite	tmp(_texture);

			target.draw(tmp, states);
		}

	template<typename Key, typename Val>
		sf::Rect<float>		Sketch<Key, Val>::getLocalShape(void) const
		{
			sf::Sprite	tmp(_texture);

			return tmp.getLocalBounds();
		}

	template<typename Key, typename Val>
		sf::Rect<float>		Sketch<Key, Val>::getGlobalShape(void) const
		{
			sf::Sprite	tmp(_texture);

			return tmp.getGlobalBounds();
		}

	template<typename Key, typename Val>
		void				Sketch<Key, Val>::drawShape(sf::RenderTarget & target, std::string mode, sf::RenderStates states, std::string status) const
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

	template<typename Key, typename Val>
		std::ostream& operator<<(std::ostream& o, const no::Sketch<Key, Val> * x)
		{
			return o << x->getName() << "\n" << x->getMap();
		}

} // no


#endif
