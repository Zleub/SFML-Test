//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Register
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-20 16:02:01
// :ddddddddddhyyddddddddddd: Modified: 2015-04-20 16:39:41
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

namespace no {

	template<typename I, typename T>
	class Register {
	public:
		Register(void);
		Register(I, no::Function<T>);
		Register(Register const &);
		~Register(void);

		Register &	operator=(Register const &) ;

		I	getEvent(void) const ;
		no::Function<T>		getFunction(void) const ;
	private:
		I	_event;
		no::Function<T>		_function;
	};

	template<typename I, typename T>
		Register<I, T>::Register(void) {} // Should throw an exception
	template<typename I, typename T>
		Register<I, T>::Register(I e, no::Function<T> f) : _event(e), _function(f) {}
	template<typename I, typename T>
		Register<I, T>::Register(Register const & src) { *this = src; }
	template<typename I, typename T>
		Register<I, T>::~Register(void) {}

	template<typename I, typename T>
		Register<I, T> &		Register<I, T>::operator=(Register<I, T> const & rhs) {
		_event = rhs.getEvent();
		_function = rhs.getFunction();
		return *this;
	}

	template<typename I, typename T>
		I	Register<I, T>::getEvent(void) const { return _event; }
	template<typename I, typename T>
		no::Function<T>			Register<I, T>::getFunction(void) const { return _function; }

	template<typename I, typename T>
		bool					operator==(const Register<I, T> * lhs, const I & rhs) {
		return (lhs->getEvent() == rhs);
	}

}
