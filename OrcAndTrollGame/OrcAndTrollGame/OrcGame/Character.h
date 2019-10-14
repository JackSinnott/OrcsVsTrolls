#pragma once
#include <iostream>
#include <ctime>
class Character
{
public:
	
	
	short randomizeAction();
	//Virtual
	virtual short attack() = 0; //pure virtual function
	virtual short getShield() = 0;
	virtual short getHealth() = 0;
	virtual short getDodge() = 0;
	virtual void setStats(short t_health, short t_atk, short t_def, short t_dodge) = 0;
	virtual void decreaseHealth(short t_value) = 0;
	virtual void weakenShield(short t_value) = 0;
	
	//Standard
	virtual bool getAlive();
	void changeAliveStatus();

private:
	bool  isAlive = true;
	
};




