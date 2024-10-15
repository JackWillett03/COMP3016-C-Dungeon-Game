#pragma once
#include <string>
#include <map>
#include <iostream>

enum class SpaceType {
	Wall,
	EmptySpace,
	Player,
	Exit,
	Coin,
	MonsterO,
	MonsterG
};

class MapSpace {
private:
	SpaceType type; // this is the name type of the space
	std::string symbol; // this is the symbol/charcter used to display whats on the space

public:
	MapSpace(SpaceType type) : type(type), symbol(getSymbolForType(type)) {}
	static std::string getSymbolForType(SpaceType type) {	// getSymbolForType returns the symbol for each spacetype
		static const std::map < SpaceType, std::string> symbols = { // maps each spacetype to its correct symbol
			{SpaceType::Wall, "#"},
			{SpaceType::EmptySpace, "."},
			{SpaceType::Player, "@"},
			{SpaceType::Exit, "D"},
			{SpaceType::Coin, "C"},
			{SpaceType::MonsterO, "O"},
			{SpaceType::MonsterG, "G"},
		};
		return symbols.at(type); // returns the symbol associated with the spacetype
	}
	std::string getSymbol() const {
		return symbol;
	}
};