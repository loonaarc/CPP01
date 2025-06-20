#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
	private:
		Weapon* weapon;
		std::string name;

	public:
		HumanB(const std::string& name);

		void setWeapon(Weapon& weapon);
		void attack();
};

#endif