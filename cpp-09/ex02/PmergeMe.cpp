#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_deq = other._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int ac, char** av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::string arg = av[i];

		if (arg.empty())
		{
			std::cerr << "Error: empty argument found." << std::endl;
			return false;
		}
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (arg[j] < '0' || arg[j] > '9')
			{
				std::cerr << "Error: invalid character or negative number." << std::endl;
				return false;
			}
		}
		int num = std::atoi(arg.c_str());
		_vec.push_back(num);
		_deq.push_back(num);
	}
	return true;
}

void PmergeMe::printSequence(const std::string& message) const
{
	std::cout << message << " ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector()
{
}

void PmergeMe::sortDeque()
{
}
