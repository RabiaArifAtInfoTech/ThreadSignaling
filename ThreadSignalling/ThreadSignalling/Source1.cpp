#include <boost/signals2/signal.hpp>
#include <iostream>

void hello() { std::cout << "Hello"; }
void world() { std::cout << ", world!\n"; }


int main()
{
	boost::signals2::signal<void()> s;
	//s.connect([] {std::cout << "Hello, world!\n"; });
	//s.connect(0, [] {std::cout << "Hello, worldD!\n"; });

	s.connect(hello);
	s.connect(world);
	s.disconnect(world);
	s.connect(world);
	std::cout << s.num_slots() << '\n';

	s();

	s.disconnect_all_slots();
	std::cout << s.num_slots() << '\n';
	if (!s.empty()) {
		std::cout <<"Inside if scope\n";
		s();
	}

	boost::signals2::signal<int()> s1;
	s1.connect([] { return 1; });
	s1.connect([] { return 2; });
	std::cout << *s1() << '\n';
	boost::signals2::connection c = s.connect([] { std::cout << "Hello, world!\n"; });
	s();
}
