#include "Base.hpp"
#include <iostream>

int main()
{
	Base* obj1 = generate();
	identify(obj1);
	identify(*obj1);
	delete obj1;

	std::cout << std::endl;
	Base* obj2 = generate();
	identify(obj2);
	identify(*obj2);
	delete obj2;

	std::cout << std::endl;
	Base* obj3 = generate();
	identify(obj3);
	identify(*obj3);
	delete obj3;

	std::cout << std::endl;
	Base unknownObj;
	identify(&unknownObj);
	identify(unknownObj);

	return 0;
}
