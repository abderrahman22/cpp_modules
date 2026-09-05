#include "iter.hpp"

template <typename T>
void printElement(const T &element) {
	std::cout << element << std::endl;
}

int main()
{
	int intArray[] = {0, 1, 2, 3, 4, 42, 42, 42, 42, 42};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;
	std::string strArray[] = {"hello", "world", "42"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;
	const double doubleArray[] = {3.14, 2.71, 1.61};
	size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);
	::iter(doubleArray, doubleLen, printElement<double>);

	return 0;
}
