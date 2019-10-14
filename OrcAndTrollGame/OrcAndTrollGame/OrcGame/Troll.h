#pragma once
#include"Character.h"

class Troll : public Character {
	public:
		Troll() = default;
		Troll(short t_health, short t_atk, short t_def, short t_dodge);
		short attack();
		short getHealth();
		void decreaseHealth(short t_value);
		void setStats(short t_health, short t_atk, short t_def, short t_dodge);
		void weakenShield(short t_value);
		short getShield();
		short getDodge();
		bool getAlive();
	private:
		short	health = 3;
		short	atkPower = 1;
		short	shield = 2;
		short	dodge = 2;
		bool	isAlive = true;
};


