//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Cookbook
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-26 18:37:47
// :ddddddddddhyyddddddddddd: Modified: 2015-04-26 22:47:52
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef COOKBOOK_HPP
#define COOKBOOK_HPP

#include <iostream>
#include <vector>
#include <Interactible.hpp>

namespace no {

	template<typename I>
	class Cookbook {
	public:
		/*! \brief Add some \<I\> to the \<I *\> vector
		 */
		static void					add(I *);
		/*! \brief Print the actual cookbook for given types
		 */
		static void					print(void);
	private:
		Cookbook(void);
		Cookbook(Cookbook const &);
		~Cookbook(void);

		Cookbook &	operator=(Cookbook const &);

		static std::vector<I *>		_book;
	};

	template<typename I>
		void				Cookbook<I>::add(I * i)
		{
			Cookbook<I>::_book.push_back(i);
		}

	template<typename I>
		void				Cookbook<I>::print(void)
		{
			for (typename std::vector<I *>::iterator it = Cookbook::_book.begin() ; it != Cookbook::_book.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
		}

	template<typename I>
		std::vector<I *>	Cookbook<I>::_book;


} // no

#endif
