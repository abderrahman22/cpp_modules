#ifndef HumanA_HPP
# define HumanA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon& sla7;
	public:
		HumanA(std::string name, Weapon& sla7);
		void attack();
};

#endif
