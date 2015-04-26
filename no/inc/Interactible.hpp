//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Interactible
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-24 20:53:12
// :ddddddddddhyyddddddddddd: Modified: 2015-04-26 22:42:16
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef INTERACTIBLE_HPP
#define INTERACTIBLE_HPP

#include <sstream>
#include <map>

#include <NO.hpp>

namespace no {

	template<typename Key, typename Val>
	class Interactible {
	public:
		/*! \brief Standard Interactible constructor
		 */
		Interactible(void);
		/*! \brief FromInteractible Interactible constructor
		 */
		Interactible(Interactible const &);
		~Interactible(void);

		/*! \brief Standard Interactible assignator
		 */
		Interactible<Key, Val> &	operator=(Interactible<Key, Val> const &);
		/*! \brief Standard Val indexator
		 *
		 * Used to access the function's pointer in Interactible::_registry
		 */
		Val &						operator[](const Key &);

		std::string					getMap(void) const;
	private:
		std::map<Key, Val>			_registry;
	};

	template<typename Key, typename Val>
		Interactible<Key, Val>::Interactible(void) {}

	template<typename Key, typename Val>
		Interactible<Key, Val>::~Interactible(void) {}

	template<typename Key, typename Val>
		Val &	Interactible<Key, Val>::operator[](const Key & key)
		{
			return _registry[key];
		}

	template<typename Key, typename Val>
		std::string		Interactible<Key, Val>::getMap(void) const
		{
			std::stringstream	ss;
			for (typename std::map<Key, Val>::const_iterator it = _registry.begin() ; it != _registry.end(); ++it)
				ss << '\t' << getEventType(it->first) << ":" << reinterpret_cast<void*>(it->second);
			ss << '\n';
			return ss.str();
		}
} // no

#endif
