#pragma once

#include "GameCharacter.h"
#include <iostream>

class Monkey : public GameCharacter {
	static void BattleCry(const GameCharacter&);
public:
	Monkey(const std::string &name, BattleCryFunc bcf = BattleCry, int attack_power = 100) : GameCharacter(name, bcf), attack_power_(attack_power) {}

private:
	int attack_power_;	// 攻击力
};

void Monkey::BattleCry(const GameCharacter& game_cha) {
	const Monkey& monkey = (const Monkey&)game_cha;

	std::cout << "WOW~~~ Monkey comming!!! My name is " << monkey.GetName() << ". My attack power is: " << monkey.attack_power_ << std::endl;
}
