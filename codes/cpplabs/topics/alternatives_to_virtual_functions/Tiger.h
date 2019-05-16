#pragma once

#include "GameCharacter.h"
#include <iostream>

class Tiger : public GameCharacter {
	static void BattleCry(const GameCharacter&);
public:
	Tiger(const std::string &name, BattleCryFunc bcf = BattleCry) : GameCharacter(name, bcf) {}
};

void Tiger::BattleCry(const GameCharacter& game_cha) {
	std::cout << "WOW~~~ Tiger comming!!! My name is " << game_cha.GetName() << std::endl;
}
