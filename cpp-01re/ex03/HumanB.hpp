#ifndef HumanB_HPP
# define HumanB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *sla7;
	public:
		HumanB(std::string name);
		void setWeapon(Weapon& sla7);
		void attack();
};

#endif
