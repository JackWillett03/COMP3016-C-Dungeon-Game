#pragma once
#include <string>
#include <vector>
#include <utility>
#include "SpaceType.h"

using namespace std;

class Player {
private:
	pair<int, int> playerPosition;
	int playerHealth = 2;
	int Lives = 2;
public:
	Player() {}

	pair<int, int> findPlayerPosition(vector<vector<MapSpace>> currentMap) { // finds current position in current map
		for (int row = 0; row < currentMap.size(); ++row) {
			for (int Column = 0; Column < currentMap[row].size(); ++Column) {
				if (currentMap[row][Column].getSymbol() == "@") { // if the current space is the player update the position
					playerPosition = { row, Column };
					return playerPosition;
				}
			}
		}
	}

	int getplayerHealth() const {
		return playerHealth;
	}
	
	void setplayerHealth(int newplayerHealth) {
		playerHealth = newplayerHealth;
	}

	void increaseplayerHealth(int increase) {
		playerHealth += increase;
	}
	void decreaseplayerHealth(int decrease) {
		playerHealth -= decrease;
	}
};