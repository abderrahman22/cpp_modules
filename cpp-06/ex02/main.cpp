#include "Base.hpp"
#include <iostream>

int main() 
{
    std::cout << "--- Test 1 ---" << std::endl;
    Base* obj1 = generate();
    identify(obj1);
    identify(*obj1);
    delete obj1;

    std::cout << "\n--- Test 2 ---" << std::endl;
    Base* obj2 = generate();
    identify(obj2);
    identify(*obj2);
    delete obj2;

    std::cout << "\n--- Test 3 ---" << std::endl;
    Base* obj3 = generate();
    identify(obj3);
    identify(*obj3);
    delete obj3;

    std::cout << "\n--- Test 4 (Testing Unknown) ---" << std::endl;
    Base unknownObj;
    identify(&unknownObj);
    identify(unknownObj);

    return 0;
}