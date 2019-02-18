#pragma once

#include <string>

// 使用函数指针来替代 virtual function 实现多态

// base class - 游戏角色
class GameCharacter {
public:
	typedef void (*BattleCryFunc)(const GameCharacter&);
	GameCharacter(const std::string &name, BattleCryFunc bcf = nullptr) : name_(name), battle_cry_func_(bcf) {}

	void Show() const {
		if (battle_cry_func_)
			battle_cry_func_(*this);
	}

	const std::string& GetName() const {
		return name_; 
	}

private:
	std::string name_;
	BattleCryFunc battle_cry_func_;	// 战吼
};
