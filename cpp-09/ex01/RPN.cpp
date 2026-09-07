#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
	*this = other;
}
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}
	RPN::~RPN() {}

void RPN::calculate(const std::string& expression)
{
	// std::cout << "DEBUG: Input => [" << expression << "]" << std::endl;
	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		if (c == ' ')
			continue;
		else if (c >= '0' && c <= '9')
			_stack.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			int v2 = _stack.top();
			_stack.pop();
			int v1 = _stack.top();
			_stack.pop();
			int result = 0;
			if (c == '+') result = v1 + v2;
			else if (c == '-') result = v1 - v2;
			else if (c == '*') result = v1 * v2;
			else if (c == '/')
			{
				if (v2 == 0)
				{
					std::cerr << "Error" << std::endl;
					return;
				}
				result = v1 / v2;
			}
			_stack.push(result);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		std::cerr << "Error" << std::endl;
}
