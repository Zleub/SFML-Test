//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Sketch
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-26 17:31:23
// :ddddddddddhyyddddddddddd: Modified: 2015-04-26 22:44:11
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SKETCH_HPP
#define SKETCH_HPP

#include <Interactible.hpp>
#include <NO.hpp>

namespace no {

	class Sketch : public sf::Drawable, public Interactible<sf::Event::EventType, _fptr> {
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

} // no

std::ostream &		operator<<(std::ostream& os, const no::Sketch &);
std::ostream &		operator<<(std::ostream& os, const no::Sketch *);

#endif
