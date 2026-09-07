#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

		void mergeSortPairsVector(std::vector<std::pair<int, int> >& pairs, int left, int right);
    	void mergeSortPairsDeque(std::deque<std::pair<int, int> >& pairs, int left, int right);

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
