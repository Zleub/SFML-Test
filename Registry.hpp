//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SFML-Test:Registry
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-04-20 16:03:04
// :ddddddddddhyyddddddddddd: Modified: 2015-04-20 16:32:34
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

namespace no {

	template<typename I, typename T>
	class Registry {
	public:
		Registry(void);
		Registry(Registry const &);
		~Registry(void);

		Registry &	operator=(Registry const &);

		void		load(Register<I, T> *);
		void		update(sf::Event);
	private:
		typename std::vector<no::Register<I, T> *>		_vector;
	};

	template<typename I, typename T>
		Registry<I, T>::Registry(void) {}
	template<typename I, typename T>
		Registry<I, T>::~Registry(void) {}

	template<typename I, typename T>
		void		Registry<I, T>::load(Register<I, T> * r) {
		typename std::vector<no::Register<I, T> *>::iterator it;

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

	template<typename I, typename T>
		void		Registry<I, T>::update(sf::Event e) {
		(void)e;
		typename std::vector<no::Register<I, T> *>::iterator it;

		it = find(_vector.begin(), _vector.end(), e.type);
		if (it == _vector.end()) {
			std::cout << "no such event : " ;
			printEventType(e.type);
			std::cout << std::endl;
		}
		else {
			std::cout << "event called: ";
			printEventType(e.type);
			std::cout << std::endl;
			(*it)->getFunction().callFunction();
		}
	}

}
