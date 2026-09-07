#include "PmergeMe.hpp"
#include <sys/time.h> // Zdnaha 3la qbel gettimeofday

int main(int argc, char **argv) 
{
    if (argc < 2) 
	{
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    if (sorter.parseInput(argc, argv) == false) 
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


    sorter.printSequence("After:  ");
    int count = argc - 1; 
    
    std::cout << "Time to process a range of " << count << " elements with std::vector : " << time_v << " us" << std::endl;
    std::cout << "Time to process a range of " << count << " elements with std::deque  : " << time_d << " us" << std::endl;

    return 0;
}