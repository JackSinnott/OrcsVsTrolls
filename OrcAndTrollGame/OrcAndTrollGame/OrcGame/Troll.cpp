#pragma once
#include "Troll.h"
#include <iostream>
using namespace std;

Troll::Troll(short t_health, short t_atk, short t_def, short t_dodge)	:
	health{ t_health },
	atkPower{ t_atk },
	shield{ t_def },
	dodge{ t_dodge }

{
}


short Troll::attack()
{
	return atkPower;
}



short Troll::getHealth()
{
	return health;
}

void Troll::decreaseHealth(short t_value)
{
	health = health - t_value;
}

void Troll::setStats(short t_health, short t_atk, short t_def, short t_dodge)
{
	health =  t_health;
	atkPower =  t_atk;
	shield =  t_def;
	dodge =  t_dodge;
}

void Troll::weakenShield(short t_value)
{
	if (shield > 0)
		shield = shield - t_value;
}

bool Troll::getAlive()
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

short Troll::getShield()
{
	return shield;
}

short Troll::getDodge()
{
	return dodge;
}