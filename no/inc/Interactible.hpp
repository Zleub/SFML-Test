//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Interactible
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-24 20:53:12
// :ddddddddddhyyddddddddddd: Modified: 2015-04-24 21:19:53
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef INTERACTIBLE_HPP
#define INTERACTIBLE_HPP

#include <NO.hpp>

namespace no {

	class Interactible {
	public:
		Interactible(void);
		Interactible(Interactible const &);
		~Interactible(void);

		Interactible &	operator=(Interactible const &);
	};

} // no

#endif
