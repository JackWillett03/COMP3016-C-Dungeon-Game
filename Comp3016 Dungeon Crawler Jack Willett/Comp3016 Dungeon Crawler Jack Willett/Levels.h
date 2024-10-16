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
	pair<int, int> playerPosition;
	int countcoins = 0;
	int playerHealth = 2; // players health starts at 2
	int deathcounter = 0; // Tracks deaths
	int endlevelcoins = 0; // tracks coins at the end of a level

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
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Exit, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall },
			{SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::EmptySpace,  SpaceType::Player, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Wall, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::EmptySpace, SpaceType::Coin, SpaceType::Wall},
			{SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall, SpaceType::Wall}
		},
	}
};

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
		findPlayerPosition();
		if (currentlevel == 1) { // when starting the game set player health to 2
			playerHealth = 2;
		}
	}

	void displayMap() const { // display the current map in the console
		for (const auto& row : currentMap) { // iterate over each row
			for (const auto& space : row) { // iterate over each space
				cout << space.getSymbol(); // print the symbol for the space
			}
			cout << '\n'; // move to the next line
		}
		cout << "Health: " << playerHealth << '\n';
		cout << "Coins: " << countcoins << '\n';
	}

	bool nextLevel() { // advance to next level
		if (currentlevel >= 3) { // check if the player is at the last level
			cout << "Congratulations you have completed the levels\n"; // Notify player of completion
			return false; // False indicates no more levels
		}
		++currentlevel;	// increase current level
		return true; // true to indicate progression
	}

	void findPlayerPosition() { // finds current position in current map
		for (int row = 0; row < currentMap.size(); ++row) {
			for (int collumn = 0; collumn < currentMap[row].size(); ++collumn) {
				if (currentMap[row][collumn].getSymbol() == "@") { // if the current space is the player update the position
					playerPosition = { row, collumn };
					return;
				}
			}
		}
	}

	bool isvalidmove(int newRow, int newCollumn) { // checks if the new position is valid
		if (newRow < 0 || newRow >= currentMap.size() || newCollumn < 0 || newCollumn >= currentMap[newRow].size()) { // checks if its outside the map boundries
			return false;
		}
		SpaceType targetType = MapSpace::getTypeForSymbol(currentMap[newRow][newCollumn].getSymbol()); // checks if the space is a wall or monster
		if (targetType == SpaceType::Wall || targetType == SpaceType::MonsterG || targetType == SpaceType::MonsterO) {
			return false;
		}
		return true;
	}

	void moveplayer(int newRow, int newCollumn) { // moves player to new position
		SpaceType typeofspace = MapSpace::getTypeForSymbol(currentMap[newRow][newCollumn].getSymbol()); 

		if (typeofspace == SpaceType::Coin) { // checks if the space is a C
			++countcoins; // adds 1 to the coin counter
		}

		if (typeofspace == SpaceType::Exit) { // if the space is the exit proceed to the next level
			currentMap[playerPosition.first][playerPosition.second] = MapSpace(SpaceType::EmptySpace); // Allows the player to step onto the exit and move to the next level
			currentMap[newRow][newCollumn] = MapSpace(SpaceType::Player);
			playerPosition = { newRow, newCollumn };
			endlevelcoins = countcoins;

			if (!nextLevel()) {
				cout << "Congratualtions you have completed all of the levels\n";
					return;
			}
			loadlevel();
			return;
		}

		SpaceType currentSpaceType = MapSpace::getTypeForSymbol(currentMap[playerPosition.first][playerPosition.second].getSymbol()); // clear the current players position
			if (currentSpaceType == SpaceType::EmptySpace || currentSpaceType == SpaceType::Player) {
				currentMap[playerPosition.first][playerPosition.second] = MapSpace(SpaceType::EmptySpace);
			}

		currentMap[newRow][newCollumn] = MapSpace(SpaceType::Player); // move player to new position
		playerPosition = { newRow, newCollumn };
	}

	void PlayerDeaths() {
		++deathcounter; // add 1 to the counter
		if (deathcounter == 1) {
			clearconsole();
			countcoins = endlevelcoins; // resets coins to what they were at the start of the level to prevent cheating
			cout << "You died! Restarting the level\n";
			playerHealth = 2; // reset health
			loadlevel(); // if only 1 death restart the level
		}
		else if (deathcounter == 2)  {
			clearconsole();
			cout << "Game over\n";
			cout << "You have used all lives, restarting\n";
			currentlevel = 1; // if 2 deaths restart the game
			countcoins = 0; // resets coins
			deathcounter = 0; // reset death counter
			endlevelcoins = 0; // Resets secondary coin count
			loadlevel(); 
		}
	}

	void clearconsole() { // function to clear console
		system("cls");
	}

	void play() {	// main loop for playing
		while (true) {
			cout << "Loading level " << currentlevel << "....\n"; 
			loadlevel(); // load current level
			displayMap(); // display current level

			if (currentMap[playerPosition.first][playerPosition.second].getSymbol() == "D") { // if at an exit move to the next level
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

				if (input.empty() || input != "w" && input != "a" && input != "d" && input != "s") { // check input for anything other then wasd commands
					cout << "Invalid input\n";
					continue;
				}

				int newRow = playerPosition.first; // determines new position based on input
				int newCollumn = playerPosition.second;

				if (input == "w") newRow -= 1; // move up
				if (input == "a") newCollumn -= 1; // move left
				if (input == "s") newRow += 1; // more down
				if (input == "d") newCollumn += 1; // move right

				if (!isvalidmove(newRow, newCollumn)) { // checks move is valid
					cout << "you can't move there\n";
					continue;
				}

				moveplayer(newRow, newCollumn); // move the player

				if (playerHealth <= 0) {
					PlayerDeaths();
					break;
				}

				clearconsole(); // calls function so it clears console so maps aren't repeatedly printed

				displayMap(); // show updated map
			}
		}
	}
};