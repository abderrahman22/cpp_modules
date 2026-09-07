#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: You must provide a sequence of positive integers." << std::endl;
		return 1;
	}

	PmergeMe sorter;
	if (sorter.parseInput(ac, av))
	{
		sorter.printSequence("Before:");
		// sorter.sortVector();
		// sorter.printSequence("After:");
	}

	return 0;
}
