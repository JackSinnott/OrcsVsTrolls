#pragma once
#include "Character.h" 

class Orc : public Character {
public:
	Orc(int four);
	short attack();
	short getHealth();
	bool getAlive();
	void decreaseHealth(short t_value);
	void increaseStats(short t_health, short t_atk, short t_def, short t_dodge);
	void setStats(short t_health, short t_atk, short t_def, short t_dodge);
	short getShield();
	short getDodge();
	void weakenShield(short t_value);
private:
	short	health = 10;
	short	atkPower = 3;
	short	dodge = 2;
	short	defence = 5;
	bool	isAlive = true;
};


