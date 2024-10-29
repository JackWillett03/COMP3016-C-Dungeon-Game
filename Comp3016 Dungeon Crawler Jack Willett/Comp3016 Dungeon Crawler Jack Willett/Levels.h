#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include <array>
#include "SpaceType.h"	// Include SpaceType
#include "Monster.h"
#include "Weapons.h"
#include "Player.h"


using namespace std;


class Levels {
private:
	vector<vector<MapSpace>> currentMap; // Current map as 2d vector
	int currentlevel = 1; // Tracks level number
	int countcoins = 0; // tracks coins
	int endlevelcoins = 0; // tracks coins at the end of a level
	int turncounter = 0; // tracks turn number
	vector<shared_ptr<Monster>> monsters;
	int Lives = 2;
	Player player = Player();
	Weapons currentweapon = Weapons("starter", 1);
	bool swordpossible = true;
	bool hasshield = false;
	int shieldhealth = 2;

	const array<vector<vector<SpaceType>>, 8> levels = { { // define array of all the maps 
		{ // Level 1
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Exit, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall },
			{SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Player, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall}
		},
		{ // Level 2
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Coin,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Exit,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Coin,SpaceType::Wall },
			{SpaceType::Wall,SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Player,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall}

		},
		{ // Level 3
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Player,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Coin,SpaceType::Coin,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Exit,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},


		},
		{ // Level 4
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Exit,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Coin,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::MonsterO,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Player,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
		},
		{ // Level 5
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Player,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterO,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Coin,SpaceType::Coin,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Exit,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::MonsterG,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Coin,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},

		},
		{	// Level 6
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Exit,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterG,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::MonsterG,SpaceType::Wall,SpaceType::Coin,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::MonsterO,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Player,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Coin,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},

		},
		{	// Level 7
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Exit,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::MonsterG,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Coin,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::MonsterO,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Player,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Coin,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::MonsterO,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::MonsterG,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},

		},
		{	// Level 8
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Exit,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Coin,SpaceType::Coin,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::EmptySpace,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::MonsterD,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::MonsterO,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Player,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::EmptySpace,SpaceType::Wall},
			{SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall,SpaceType::Wall},

		},
	}

};

public: // Load the current level into currentmap
	void loadlevel() {
		if (currentlevel < 1 || currentlevel > 8) { // check to see if we are on a correct leve;
			return;
		}
		currentMap.clear(); // clear the current map
		monsters.clear();
		int rowindex = 0;
		for (const auto& row : levels[currentlevel - 1]) { // copy current level to current map
			vector<MapSpace> mapRow; // create new rows
			int columnindex = 0;
			for (const auto& spaceType : row) {
				mapRow.emplace_back(MapSpace(spaceType)); // Initialise symbols based on SpaceType definition 
				if (spaceType == SpaceType::MonsterG) { // Initialise the monsterG
					monsters.push_back(make_shared <Monster>(SpaceType::MonsterG, make_pair(rowindex, columnindex)));
				}
				if (spaceType == SpaceType::MonsterO) { // Initialise the monsterO
					monsters.push_back(make_shared <Monster>(SpaceType::MonsterO, make_pair(rowindex, columnindex)));
				}
				if (spaceType == SpaceType::MonsterD) { // Initialise the monsterD
					monsters.push_back(make_shared <Monster>(SpaceType::MonsterD, make_pair(rowindex, columnindex)));
				}
				columnindex++;
			}
			currentMap.push_back(mapRow); // add new row to current map
			rowindex++;
		}
		player.findPlayerPosition(currentMap);
		if (currentlevel == 1) { // when starting the game set player health to 2
			player.setplayerHealth(2);
		}
	}

	void displayMap() const { // display the current map in the console
		for (const auto& row : currentMap) { // iterate over each row
			for (const auto& space : row) { // iterate over each space
				cout << space.getSymbol(); // print the symbol for the space
			}
			cout << '\n'; // move to the next line
		}
		cout << "Health: " << player.getplayerHealth() << '\n';
		cout << "Coins: " << countcoins << '\n';
		cout << "Lives: " << Lives << '\n';
		cout << "Turn: " << turncounter << '\n';
		if (hasshield == true) {
			cout << "Shield equipped \n";
		}
	}

	bool nextLevel() { // advance to next level
		if (currentlevel >= 8) { // check if the player is at the last level
			clearconsole();
			cout << "Congratulations you have completed the levels\n"; // Notify player of completion
			cout << "You have " << player.getplayerHealth() << " health, " << Lives << " lives and " << countcoins << " coins remaining. \n";
			cout << "You completed the game in: " << turncounter << " turns \n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears inputs
			return false; // False indicates no more levels
		}
		++currentlevel;	// increase current level
		shop(); // Opens the shop
		return true; // true to indicate progression
	}

	void shop() {
		int choice;
		while (true) { // shop will keep running until you choose to exit
			cout << "\n  Shop: \n";
			cout << "Current health: " << player.getplayerHealth() << ", Coins: " << countcoins << ", Lives: " << Lives << '\n'; // list current coins health and lives
			cout << "1. Health potion (+1hp, max 3) - 3 coins \n";
			cout << "2. Extra life (max 2) - 8 coins \n";
			if (swordpossible && hasshield == false) {
				cout << "3. Sword (2 damage) - 6 coins \n";
				cout << "4. Shield (-2 damage) - 5 coins \n";
				cout << "5. Exit shop \n";
			}
			else if (swordpossible && hasshield == true) {
				cout << "3. Sword (2 damage) - 6 coins \n";
				cout << "4. Exit shop \n";
			}
			else if (hasshield == false && !swordpossible) {
				cout << "3. Shield (-2 damage) - 5 coins \n";
				cout << "4. Exit shop \n";
			}
			else {
				cout << "3. Exit shop \n";
			}
			cin >> choice;

			if (choice == 1) { // choose health 
				if (countcoins >= 3) { // check they have the coins
					if (player.getplayerHealth() < 3) { // check they are not at max health
						countcoins -= 3; // take away coins
						endlevelcoins -= 3;
						player.increaseplayerHealth(1); // add health
						clearconsole();
						cout << "You have successfully bought a Health potion, you now have " << player.getplayerHealth() << " health" << '\n';
					}
					else { // if at max health don't add more
						clearconsole();
						cout << "You have the maximum amount of health \n";
					}
				}
				else { // if not enough coins don't allow purchase
					clearconsole();
					cout << "You don't have enough coins for that. You need " << 3 - countcoins << " more coins. \n";
				}
			}
			else if (choice == 2) { // choose lives
				if (countcoins >= 8) { // check coins
					if (Lives == 1) { // check current lives
						countcoins -= 8;
						endlevelcoins -= 8;
						Lives += 1;
						clearconsole();
						cout << "You have purchased another life. Lives = " << Lives << '\n';
					}
					else {
						clearconsole();
						cout << "You have the maximum amount of lives \n";
					}
				}
				else {
					clearconsole();
					cout << "You don't have enough coins for that. You need " << 8 - countcoins << " more coins. \n";
				}
			}
			else if (choice == 3 && swordpossible) { // checks if the sword is available
				if (countcoins >= 6) {
					countcoins -= 6;
					endlevelcoins -= 6;
					currentweapon = Weapons("Sword", 2); // sets current weapon to the new one
					swordpossible = false; // makes it so you can no longer buy the sword
					clearconsole();
					cout << "You have purchased a new weapons. Now destroy those monsters!";
				}
				else {
					clearconsole();
					cout << "You don't have enough coins for that. You need " << 6 - countcoins << " more coins. \n"; // need more coins
				}
			}
			else if (choice == 3 && !swordpossible && hasshield == false) { // if they have a better sword but no shield
				if (countcoins >= 5) {
					countcoins -= 5;
					endlevelcoins -= 5;
					hasshield = true;
					shieldhealth = 2;
					clearconsole();
					cout << "You have purchased a shield. \n";
				}
				else
				{
					clearconsole();
					cout << "You don't have enough coins for that. You need " << 5 - countcoins << " more coins \n";
				}
			}
			else if (choice == 3 && swordpossible == false && hasshield == true) { // exit shop
				clearconsole();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears inputs
				cout << "Leaving shop \n";
				break; // breaks loop so shop can be left
			}
			else if (choice == 4 && swordpossible && hasshield == false) // if neither have a shield or sword
			{
				if (countcoins >= 5) {
					countcoins -= 5;
					endlevelcoins -= 5;
					hasshield = true;
					shieldhealth = 2;
					clearconsole();
					cout << "You have purchased a shield. \n";
				}
				else
				{
					clearconsole();
					cout << "You don't have enough coins for that. You need " << 5 - countcoins << " more coins \n";
				}
			}
			else if (choice == 4 && swordpossible && hasshield == true) {
				clearconsole();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears inputs
				cout << "Leaving shop \n";
				break; // breaks loop so shop can be left
			}
			else if (choice == 4 && !swordpossible && hasshield == false) {
				clearconsole();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears inputs
				cout << "Leaving shop \n";
				break; // breaks loop so shop can be left
			}
			else if (choice == 5) { // exit shop
				clearconsole();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears inputs
				cout << "Leaving shop \n";
				break; // breaks loop so shop can be left
			}
			else {
				clearconsole();
				cout << "Invalid choice \n";
			}
		}
	}

	bool isvalidmove(int newRow, int newColumn) { // checks if the new position is valid
		if (newRow < 0 || newRow >= currentMap.size() || newColumn < 0 || newColumn >= currentMap[newRow].size()) { // checks if its outside the map boundries
			return false;
		}
		SpaceType targetType = MapSpace::getTypeForSymbol(currentMap[newRow][newColumn].getSymbol()); // checks if the space is a wall or monster
		if (targetType == SpaceType::Wall || targetType == SpaceType::MonsterG || targetType == SpaceType::MonsterO || targetType == SpaceType::MonsterD) {
			return false;
		}
		return true;
	}

	void moveplayer(int newRow, int newColumn) { // moves player to new position
		SpaceType typeofspace = MapSpace::getTypeForSymbol(currentMap[newRow][newColumn].getSymbol()); 

		if (typeofspace == SpaceType::Coin) { // checks if the space is a C
			++countcoins; // adds 1 to the coin counter
		}

		if (typeofspace == SpaceType::Exit) { // if the space is the exit proceed to the next level
			currentMap[player.findPlayerPosition(currentMap).first][player.findPlayerPosition(currentMap).second] = MapSpace(SpaceType::EmptySpace); // Allows the player to step onto the exit and move to the next level
			currentMap[newRow][newColumn] = MapSpace(SpaceType::Player);
			player.findPlayerPosition(currentMap) = { newRow, newColumn };
			endlevelcoins = countcoins;

			if (!nextLevel()) {
				cout << "Congratualtions you have completed all of the levels\n";
					return;
			}
			loadlevel();
			return;
		}

		SpaceType currentSpaceType = MapSpace::getTypeForSymbol(currentMap[player.findPlayerPosition(currentMap).first][player.findPlayerPosition(currentMap).second].getSymbol()); // clear the current players position
			if (currentSpaceType == SpaceType::EmptySpace || currentSpaceType == SpaceType::Player) {
				currentMap[player.findPlayerPosition(currentMap).first][player.findPlayerPosition(currentMap).second] = MapSpace(SpaceType::EmptySpace);
			}

		currentMap[newRow][newColumn] = MapSpace(SpaceType::Player); // move player to new position
		turncounter++; // increase turn counter by 1
		player.findPlayerPosition(currentMap) = { newRow, newColumn };

		clearconsole();
		displayMap();

		if (turncounter % 3 == 0) {
			MonsterGattack();
			MonsterOattack();
			MonsterDattack();
		}
	}

	void PlayerDeaths() {
		--Lives; // take away 1 life
		if (Lives >= 1) {
			clearconsole();
			countcoins = endlevelcoins; // resets coins to what they were at the start of the level to prevent cheating
			cout << "You died! Restarting the level\n";
			cout << "Press enter to continue\n";
			player.setplayerHealth(2); // reset health
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears inputs
			loadlevel(); // if more then 1 life restart the level
			displayMap();
		}
		else if (Lives <= 0)  {
			clearconsole();
			cout << "Game over\n";
			cout << "You have used all lives, restarting\n";
			cout << "Press enter to continue\n";
			currentlevel = 1; // if no lives restart the game
			countcoins = 0; // resets coins
			turncounter = 0; // reset turns
			Lives = 2; // reset lives
			endlevelcoins = 0; // Resets secondary coin count
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears inputs
			loadlevel(); 
			displayMap();
		}
	}

	void clearconsole() { // function to clear console
#ifdef _WIN32
		system("cls"); // for windows
#else
		system("clear"); // for linux and others
#endif
	}

	void MonsterGattack() {
		for (const auto& monster : monsters) { // iterate each monster in the list
			if (monster->CheckHealth() == SpaceType::MonsterG) { // check the halth matches the monsters
				int monsterRow = monster->getPosition().first;	// get current psotion
				int monsterColumn = monster->getPosition().second;

				vector<pair<int, int>>  adjPositions = { // define the adjacent spaces
					{monsterRow - 1, monsterColumn},
					{monsterRow + 1, monsterColumn},
					{monsterRow, monsterColumn - 1},
					{monsterRow, monsterColumn + 1},
				};

				for (auto& pos : adjPositions) { // check each adjacent position
					int adjRow = pos.first;
					int adjColumn = pos.second;

					if (adjRow >= 0 && adjRow < currentMap.size() && adjColumn >= 0 && adjColumn < currentMap[adjRow].size()) {
						if (player.findPlayerPosition(currentMap) == make_pair(adjRow, adjColumn)) { // check if the player is adjacent 
							if (hasshield == false) {
								player.decreaseplayerHealth(1); // do 1 damage
								clearconsole();
								displayMap();
								cout << "You have been attacked, your health is now " << player.getplayerHealth() << '\n'; // tell the player they have been hit
								cout << "Press enter to continue \n";
								cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pause until input to allow for player to read message
								clearconsole();
								displayMap();
								if (player.getplayerHealth() <= 0) {
									PlayerDeaths();
								}
								return;
							}
							else {
								if (shieldhealth >= 2)
								{
									shieldhealth = 1;
									cout << "Your shield has taken damage \n";
									cout << "Press enter to continue \n";
									cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pause until input to allow for player to read message
								}
								else if (shieldhealth == 1)
								{
									hasshield = false; // removes shield
									shieldhealth = 0;
									cout << "Your shield has been destroyed \n";
									cout << "Press enter to continue \n";
									cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pause until input to allow for player to read message
								}
								clearconsole();
								displayMap();
								clearconsole();
								displayMap();
								return;
							}
						}
					}
				}
			}
		}
	}

	void MonsterOattack() {
		for (const auto& monster : monsters) { // iterate each monster in the list
			if (monster->CheckHealth() == SpaceType::MonsterO) { // check the health matches the monsters
				int monsterRow = monster->getPosition().first;
				int monsterColumn = monster->getPosition().second;

				vector<pair<int, int>> adjacentPositions = { // define the adjacent spaces
					{monsterRow - 1, monsterColumn},
					{monsterRow + 1, monsterColumn},
					{monsterRow, monsterColumn - 1},
					{monsterRow, monsterColumn + 1},
				};

				bool playeradjacent = false;

				for (auto& pos : adjacentPositions) { // check each adjacent position
					int adjRow = pos.first;
					int adjColumn = pos.second;

					if (adjRow >= 0 && adjRow < currentMap.size() && adjColumn >= 0 && adjColumn < currentMap[adjRow].size()) {
						if (player.findPlayerPosition(currentMap) == make_pair(adjRow, adjColumn)) {
							playeradjacent = true;
							if (!hasshield) {
								player.decreaseplayerHealth(2);
								clearconsole();
								displayMap();
								cout << "You have been attacked, your health is now " << player.getplayerHealth() << '\n';
								cout << "Press enter to continue \n";
								cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pause until input to allow for player to read message
								clearconsole();
								displayMap();
								if (player.getplayerHealth() <= 0) { // checks if player has health
									PlayerDeaths();
								}
								return;
							}
							else {
								if (shieldhealth >= 2)
								{
									hasshield = false; // removes shield
									clearconsole();
									displayMap();
									cout << "Your shield has been destroyed \n";
									cout << "Press enter to continue \n";
									cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pause until input to allow for player to read message
								}
								else if (shieldhealth == 1) {
									hasshield = false; // removes shield
									player.decreaseplayerHealth(1);
									clearconsole();
									displayMap();
									cout << "Your shield has been destroyed and you have been hit, your health is now " << player.getplayerHealth() << '\n';
									cout << "Press enter to continue \n";
									cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pause until input to allow for player to read message
								}
								clearconsole();
								displayMap();
								if (player.getplayerHealth() <= 0) { // checks if player has health
									PlayerDeaths();
								}
								return;
							}
						}
					}
				}

				if (!playeradjacent) { // if not adjacent move close
					pair<int, int> bestMove = { monsterRow, monsterColumn };
					int shortestdistance = abs(player.findPlayerPosition(currentMap).first - monsterRow) + abs(player.findPlayerPosition(currentMap).second - monsterColumn); // calculate distance to player

					for (auto& pos : adjacentPositions) { // check adjacent spaces for possible moves
						int adjRow = pos.first;
						int adjColumn = pos.second;
						if (adjRow >= 0 && adjRow < currentMap.size() && adjColumn >= 0 && adjColumn < currentMap[adjRow].size()) { // ensure its within the map
							if (currentMap[adjRow][adjColumn].getTypeForSymbol(currentMap[adjRow][adjColumn].getSymbol()) == SpaceType::EmptySpace) { // calculate positions distance to player
								int distance = abs(player.findPlayerPosition(currentMap).first - adjRow) + abs(player.findPlayerPosition(currentMap).second - adjColumn); // if it would make the monster close updates the shortest distance and best move
								if (distance < shortestdistance) {
									shortestdistance = distance;
									bestMove = { adjRow, adjColumn };
								}
							}
						}
					}

					if (bestMove != make_pair(monsterRow, monsterColumn)) { // if a better move has been found update the position on the map
						currentMap[monsterRow][monsterColumn] = SpaceType::EmptySpace; // make the previous space an empty space
						monster->setPosition(bestMove); // update position
						currentMap[bestMove.first][bestMove.second] = SpaceType::MonsterO; // move the monster to new position
					}
				}
			}
		}
	}

	void MonsterDattack() {
		for (const auto& monster : monsters) { // iterate each monster in the list
			if (monster->CheckHealth() == SpaceType::MonsterD) { // check the health matches the monsters
				int monsterRow = monster->getPosition().first;	// get current position
				int monsterColumn = monster->getPosition().second;

				vector<pair<int, int>>  adjPositions = { // define the adjacent spaces
					{monsterRow - 1, monsterColumn},
					{monsterRow + 1, monsterColumn},
					{monsterRow, monsterColumn - 1},
					{monsterRow, monsterColumn + 1},
				};

				for (auto& pos : adjPositions) { // check each adjacent position
					int adjRow = pos.first;
					int adjColumn = pos.second;

					if (adjRow >= 0 && adjRow < currentMap.size() && adjColumn >= 0 && adjColumn < currentMap[adjRow].size()) {
						if (player.findPlayerPosition(currentMap) == make_pair(adjRow, adjColumn)) { // check if the player is adjacent 
							player.decreaseplayerHealth(3);
							shieldhealth -= 2;
							clearconsole();
							displayMap();
							cout << "You have been burnt to death by the dragon.\n"; // tell the player they have been hit
							cout << "Press enter to continue \n";
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pause until input to allow for player to read message
							clearconsole();
							displayMap();
							return;
						}
					}
				}
			}
		}
	}

	void damageMonster() {
		int row = player.findPlayerPosition(currentMap).first; // retrieves players position
		int Column = player.findPlayerPosition(currentMap).second;

		vector < pair<int, int>> adjacentPositions = { // checks the 4 spaces around the player
			{row - 1, Column}, // up
			{row + 1, Column}, // down
			{row, Column - 1}, // left
			{row, Column + 1}, // right
		};

		vector<shared_ptr<Monster>> adjacentMonsters; // stores monsters adjacent to player

		for (auto& pos : adjacentPositions) { // iterate through the adjacent positions
			int adjRow = pos.first;
			int adjColumn = pos.second;


			if (adjRow >= 0 && adjRow < currentMap.size() && adjColumn >= 0 && adjColumn < currentMap[adjRow].size()) { // checks the space is in the map
				string symbol = currentMap[adjRow][adjColumn].getSymbol();
				SpaceType spaceType = MapSpace::getTypeForSymbol(symbol);

				if (spaceType == SpaceType::MonsterG || spaceType == SpaceType::MonsterO || spaceType == SpaceType::MonsterD) { // check if the adjacent space is a monster
					for (auto& monster : monsters) { // find the monster in the list
						if (monster->getPosition() == make_pair(adjRow, adjColumn)) {
							adjacentMonsters.push_back(monster); // add the monster to the list of targets
							break;
						}
					}
				}
			}
		}

		if (adjacentMonsters.empty()) { // if no monsters are found stop looking
			clearconsole();
			displayMap();
			cout << "No monster adjacent \n";
			return;
		}

		sort(adjacentMonsters.begin(),adjacentMonsters.end(), [](const shared_ptr<Monster>& a, const shared_ptr<Monster>& b) { // sort monsters by health
			return a->getMhealth() < b->getMhealth();
		});

		auto& targetMonster = adjacentMonsters.front(); // target the one with lowest health
		targetMonster->ReduceHealth(currentweapon.getDamage()); // deal damage based on weapons damage
		turncounter++;

		int targetRow = targetMonster->getPosition().first;
		int targetColumn = targetMonster->getPosition().second;

		if (targetMonster->getMhealth() <= 0) { // checks if its health is 0 removes it if so
			currentMap[targetRow][targetColumn] = MapSpace(SpaceType::EmptySpace);
			monsters.erase(remove(monsters.begin(), monsters.end(), targetMonster), monsters.end());
			clearconsole();
			displayMap();
			cout << "You killed a monster \n";
		}
		else { // display message if above 0 health
			clearconsole();
			displayMap();
			cout << "You hit a monster \n";
		}
		if (turncounter % 3 == 0) {
			MonsterGattack();
			MonsterOattack();
			MonsterDattack();
		}
	}

	void play() {	// main loop for playing
		while (true) {
			cout << "Loading level " << currentlevel << "....\n"; 
			loadlevel(); // load current level
			displayMap(); // display current level

			if (currentMap[player.findPlayerPosition(currentMap).first][player.findPlayerPosition(currentMap).second].getSymbol() == "E") { // if at an exit move to the next level
				cout << "You are at the exit, next level\n";
				if (!nextLevel()) {
					return;
				}
				break;
			}

			while (true) {
				string input;
				cout << "Enter your move";
				getline(cin, input); // read player input

				transform(input.begin(), input.end(), input.begin(), ::tolower); // convert input to lowercase

				if (input == "exit") {
					cout << "Thanks for playing\n";
					return;
				}

				if (input.empty() || input != "w" && input != "a" && input != "d" && input != "s" && input != " ") { // check input for anything other then wasd commands
					cout << "Invalid input\n";
					continue;
				}

				if (input == " ") { // when input is space call damageMonster
					damageMonster();
					continue;
				}

				int newRow = player.findPlayerPosition(currentMap).first; // determines new position based on input
				int newColumn = player.findPlayerPosition(currentMap).second;

				if (input == "w") newRow -= 1; // move up
				if (input == "a") newColumn -= 1; // move left
				if (input == "s") newRow += 1; // more down
				if (input == "d") newColumn += 1; // move right

				if (!isvalidmove(newRow, newColumn)) { // checks move is valid
					clearconsole();
					displayMap();
					cout << "you can't move there\n";
					continue;
				}

				moveplayer(newRow, newColumn); // move the player

				if (player.getplayerHealth() <= 0) {
					PlayerDeaths();
					break;
				}

				clearconsole(); // calls function so it clears console so maps aren't repeatedly printed
				displayMap(); // show updated map
			}
		}
	}
};