#pragma once
#include "Orc.h"
#include <iostream>
using namespace std;




Orc::Orc(int four)
{
}

short Orc::attack()
{ 
	return atkPower;
}

short Orc::getHealth()
{
	return health;
}

void Orc::decreaseHealth(short t_value)
{
	health = health - t_value;
}

void Orc::increaseStats(short t_health, short t_atk, short t_def, short t_dodge)
{
}

void Orc::setStats(short t_health, short t_atk, short t_def, short t_dodge)
{
	health = t_health;
	atkPower = t_atk;
	defence = t_def;
	dodge = t_dodge;
}

void Orc::weakenShield(short t_value)
{
	if (defence > 0)
		defence = defence - t_value;
}

bool Orc::getAlive()
{
	if (health > 0)
	{
		isAlive = true;
	}
	else
	{
		isAlive = false;
	}
	return isAlive;
}

short Orc::getShield()
{
	return defence;
}

short Orc::getDodge()
{
	return dodge;
}