#pragma once
#include <string>

using namespace std;

class Weapons {
private:
	string name;
	int damage;

public:
	Weapons(const string& weaponname, int weapondamage) : name(weaponname), damage(weapondamage) {} // initialise weapon with name and damage values

	string getName() const { // gets the name
		return name;
	}

	int getDamage() const { // gets the damage
		return damage;
	}
};

// The different weapons the player can have (more can easily be added)
const Weapons standardweapon("standard", 1);
const Weapons Sword("Sword", 2);

