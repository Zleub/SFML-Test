//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Function
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-20 15:59:40
// :ddddddddddhyyddddddddddd: Modified: 2015-04-20 16:41:48
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

namespace no {

	template<typename T>
	class Function {
	public:
		Function(void);
		Function(T);
		Function(Function const &);
		~Function(void);

		Function &	operator=(Function const &);

		void			callFunction(void);
		T			getFunction(void) const ;
	private:
		void	(* _function)(void);
	};

	template<typename T>
		Function<T>::Function(void) : _function(NULL) {}
	template<typename T>
		Function<T>::Function(T p) : _function(p) {}
	template<typename T>
		Function<T>::Function(Function const & src) { *this = src; }
	template<typename T>
		Function<T>::~Function(void) {}
	template<typename T>
		Function<T> &	Function<T>::operator=(Function<T> const & rhs) { _function = rhs.getFunction(); return *this; }

	template<typename T>
		void			Function<T>::callFunction(void) { _function(); }
	template<typename T>
		T				Function<T>::getFunction(void) const { return _function; }

}
