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
	std::cout << message;
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::mergeSortPairsVector(std::vector<std::pair<int, int> >& pairs, int left, int right)
{
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSortPairsVector(pairs, left, mid);
	mergeSortPairsVector(pairs, mid + 1, right);

	std::vector<std::pair<int, int> > temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (pairs[i].first <= pairs[j].first)
			temp.push_back(pairs[i++]);
		else
			temp.push_back(pairs[j++]);
	}
	while (i <= mid)
		temp.push_back(pairs[i++]);
	while (j <= right)
		temp.push_back(pairs[j++]);

	for (int k = 0; k < (int)temp.size(); k++)
	{
		pairs[left + k] = temp[k];
	}
}

void PmergeMe::mergeSortPairsDeque(std::deque<std::pair<int, int> >& pairs, int left, int right)
{
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSortPairsDeque(pairs, left, mid);
	mergeSortPairsDeque(pairs, mid + 1, right);

	std::deque<std::pair<int, int> > temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (pairs[i].first <= pairs[j].first)
			temp.push_back(pairs[i++]);
		else
			temp.push_back(pairs[j++]);
	}
	while (i <= mid)
		temp.push_back(pairs[i++]);
	while (j <= right)
		temp.push_back(pairs[j++]);

	for (int k = 0; k < (int)temp.size(); k++)
		pairs[left + k] = temp[k];
}

void PmergeMe::sortVector()
{
	if (_vec.size() < 2) return;

	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	if (_vec.size() % 2 != 0)
	{
		straggler = _vec.back();
		hasStraggler = true;
		_vec.pop_back();
	}

	for (size_t i = 0; i < _vec.size(); i += 2)
	{
		if (_vec[i] > _vec[i+1])
			pairs.push_back(std::make_pair(_vec[i], _vec[i+1]));
		else
			pairs.push_back(std::make_pair(_vec[i+1], _vec[i]));
	}

	if (!pairs.empty())
		mergeSortPairsVector(pairs, 0, pairs.size() - 1);

	std::vector<int> main_chain;
	std::vector<int> pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	if (!pend.empty())
	{
		main_chain.insert(main_chain.begin(), pend[0]);
	}
	int jacob[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
	size_t jacob_idx = 1;
	size_t last_inserted = 1;

	while (last_inserted < pend.size())
	{
		size_t current_jacob = jacob[jacob_idx];
		if (current_jacob > pend.size())
		{
			current_jacob = pend.size();
		}
		for (size_t i = current_jacob; i > last_inserted; --i)
		{
			int to_insert = pend[i - 1];
			std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), to_insert);
			main_chain.insert(pos, to_insert);
		}
		last_inserted = current_jacob;
		jacob_idx++;
	}
	if (hasStraggler)
	{
		std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
		main_chain.insert(pos, straggler);
	}
	_vec = main_chain;
}

void PmergeMe::sortDeque()
{
	if (_deq.size() < 2) return;

	std::deque<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	if (_deq.size() % 2 != 0)
	{
		straggler = _deq.back();
		hasStraggler = true;
		_deq.pop_back();
	}

	for (size_t i = 0; i < _deq.size(); i += 2)
	{
		if (_deq[i] > _deq[i+1])
			pairs.push_back(std::make_pair(_deq[i], _deq[i+1]));
		else
			pairs.push_back(std::make_pair(_deq[i+1], _deq[i]));
	}
	if (!pairs.empty())
		mergeSortPairsDeque(pairs, 0, pairs.size() - 1);

	std::deque<int> main_chain, pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	if (!pend.empty())
		main_chain.insert(main_chain.begin(), pend[0]);

	int jacob[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
	size_t jacob_idx = 1, last_inserted = 1;

	while (last_inserted < pend.size())
	{
		size_t current_jacob = jacob[jacob_idx];
		if (current_jacob > pend.size()) current_jacob = pend.size();

		for (size_t i = current_jacob; i > last_inserted; --i)
		{
			int to_insert = pend[i - 1];
			std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), to_insert);
			main_chain.insert(pos, to_insert);
		}
		last_inserted = current_jacob;
		jacob_idx++;
	}

	if (hasStraggler)
	{
		std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
		main_chain.insert(pos, straggler);
	}
	_deq = main_chain;
}
