#pragma once
#include <string>
#include "SpaceType.h"

class Monster {
private:
	SpaceType type; // stores type of monster
	int health; // to store monster health

	int MonsterHealth(SpaceType monsterType) { // determins health based on type
		switch (monsterType) {
		case SpaceType::MonsterG: // G has 2 health
			return 2;
		case SpaceType::MonsterO: // O has 4 health
			return 4;
		default:
			return 0;
		}
	}
public:
	Monster(SpaceType monsterType) : type(monsterType), health(MonsterHealth(monsterType)) {} // Inilitalise monster with type and health

	SpaceType CheckHealth() const { // checks current health and if its 0 or less
		if (health <= 0) {
			return SpaceType::EmptySpace; // replace with empty space
		}
	return type; // if above 0 return monster
	}

	void ReduceHealth(int damage) { // function to reduce health by damage amount
		health -= damage;
	}

	int getMhealth() const { // retrieve current health
		return health;
	}
};