#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib> // atoi
#include <sys/time.h> // Bach n7sbou l'weqt (gettimeofday)

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		bool parseInput(int argc, char** argv);

		void printSequence(const std::string& message) const;

		void sortVector();
		void sortDeque();
};

#endif
