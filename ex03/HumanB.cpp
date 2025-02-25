#include "HumanB.hpp"

#include <string>
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name) {}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}