#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: You must provide a sequence of positive integers." << std::endl;
		return 1;
	}

	PmergeMe sorter;
	if (!sorter.parseInput(ac, av))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	sorter.printSequence("Before: ");

	struct timeval start_v, end_v;
	gettimeofday(&start_v, NULL);
	sorter.sortVector();
	gettimeofday(&end_v, NULL);
	double time_v = (end_v.tv_sec - start_v.tv_sec) * 1000000.0 + (end_v.tv_usec - start_v.tv_usec);

	struct timeval start_d, end_d;
	gettimeofday(&start_d, NULL);
	sorter.sortDeque();
	gettimeofday(&end_d, NULL);
	double time_d = (end_d.tv_sec - start_d.tv_sec) * 1000000.0 + (end_d.tv_usec - start_d.tv_usec);


	sorter.printSequence("After: ");

	int count = ac - 1;
	std::cout << "Time to process a range of " << count
		<< " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << time_v << " us" << std::endl;


	std::cout << "Time to process a range of " << count
		<< " elements with std::deque  : "
		<< std::fixed << std::setprecision(5) << time_d << " us" << std::endl;

	return 0;
}
