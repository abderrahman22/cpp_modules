#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try
	{
		std::cout << "vector container" << std::endl;
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::list<int> lista;
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);

	try
	{
		std::cout << "list container" << std::endl;
		std::list<int>::iterator it = easyfind(lista, 3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
