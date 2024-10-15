#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include <array>
#include "SpaceType.h"	// Include SpaceType



using namespace std;

class Levels {
private:
	vector<vector<MapSpace>> currentMap; // Current map as 2d vector
	int currentlevel = 1; // Tracks level number

	const array<vector<vector<SpaceType>>, 3> levels = { { // define array of all the maps 
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
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Exit, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall },
			{SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Player, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall}
		},
		{ // Level 3
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Exit, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall },
			{SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Player, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall}
		},
	} };
public: // Load the current level into currentmap
	void loadlevel() {
		if (currentlevel < 1 || currentlevel > 3) { // check to see if we are on a correct leve;
			cout << "Congratulations you have won!\n"; // notify player they won
			return;
		}

		currentMap.clear(); // clear the current map
		for (const auto& row : levels[currentlevel - 1]) { // copy current level to current map
			vector<MapSpace> mapRow; // create new rows
			for (const auto& SpaceType : row) {
				mapRow.emplace_back(MapSpace(SpaceType)); // Initialise symbols based on SpaceType definition 
			}
			currentMap.push_back(mapRow); // add new row to current map
		}
	}

	void displayMap() const { // display the current map in the console
		for (const auto& row : currentMap) { // iterate over each row
			for (const auto& space : row) { // iterate over each space
				cout << space.getSymbol(); // print the symbol for the space
			}
			cout << '\n'; // move to the next line
		}
	}

	bool nextLevel() { // advance to next level
		if (currentlevel >= 3) { // check if the player is at the last level
			cout << "Congratulations you have completed the levels\n"; // Notify player of completion
			return false; // False indicates no more levels
		}
		++currentlevel;	// increase current level
		return true; // true to indicate progression
	}

	void play() {	// main loop for playing
		while (true) {
			cout << "Loading level " << currentlevel << "....\n"; 
			loadlevel(); // load current level
			displayMap(); // display current level

			string input; // variable to store user input
			cout << "Level " << currentlevel; "completed! Would you like to continue?\n"; 
			getline(cin, input); // get user input
			transform(input.begin(), input.end(), input.begin(), ::tolower);

			if (input != "yes" || input != "Yes" || input != "Y" || input != "y") { // check if they want to continue
				cout << "Thanks for playing\n";
				return; // exit the loop
			}

			if (!nextLevel()) { // move to next level
				break;
			}
		}
	}
};