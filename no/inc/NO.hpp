//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:NO
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-20 16:29:54
// :ddddddddddhyyddddddddddd: Modified: 2015-04-26 22:47:15
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-;
//      .+ydddddddddhs/.
//          .-::::-`

#include <SFML/Graphics.hpp>

#include <map>
#include <algorithm>
#include <iostream>

namespace no {

	/*! \brief Pointer to function used by Sketch
	 */
	typedef						void(* _fptr)(void);

	/*! \brief sf::Event::EventType Utility
	 */
	void			printEventType(sf::Event::EventType e);
	/*! \brief sf::Event::EventType Utility
	 */
	std::string		getEventType(sf::Event::EventType e);

}

