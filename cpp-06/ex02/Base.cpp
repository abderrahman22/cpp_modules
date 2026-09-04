#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base * generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	int randomnum = std::rand() % 3;
	if (randomnum == 0)
	{
		std::cout << "Generated: A" << std::endl;
		return new A();
	}
	else if (randomnum == 1)
	{
		std::cout << "Generated: B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated: C" << std::endl;
		return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
			std::cout << "Pointer identified as: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer identified as: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer identified as: C" << std::endl;
	else
		std::cout << "Pointer identified as: Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference identified as: A" << std::endl;
		return;
	}
	catch (const std::exception& e) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference identified as: B" << std::endl;
		return;
	}
	catch (const std::exception& e) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference identified as: C" << std::endl;
		return;
	}
	catch (const std::exception& e) {}
	std::cout << "Reference identified as: Unknown" << std::endl;
}
