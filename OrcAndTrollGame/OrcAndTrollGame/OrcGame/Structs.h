#pragma once
#include "Orc.h"
#include "Troll.h"


struct LootTable
{
	
	short axe = 2;
	short sword = 4;
	short lance = 6;
	short lightsaber = 10;

	short steak = 10;
	short ale = 5;

	short shield = 4;
	short heavyArmour = 8;

	short lightArmour = 6;
	short smokeBomb = 3;

	short returnAtk() {
		std::srand(std::time(0));
		short random = rand() % 4 + 1;
		short toRet = 0;
		if (random == 1)
		{
			toRet = axe;
			std::cout << "You have recieved the Axe" << std::endl;
		}
		else if (random == 2)
		{
			toRet = sword;
			std::cout << "You have recieved the Sword" << std::endl;
		}
		else if (random == 3)
		{
			toRet = lance;
			std::cout << "You have recieved the Lance" << std::endl;
		}
		else if (random == 4)
		{
			toRet = lightsaber;
			std::cout << "You have recieved a lightsaber" << std::endl;
		}
		return toRet;
	};

	short returnDef() {
		std::srand(std::time(0));
		short random = rand() % 2 + 1;
		short toRet = 0;
		if (random == 1)
		{
			toRet = shield;
			std::cout << "You have recieved the Shield" << std::endl;
		}
		else if (random == 2)
		{
			toRet = heavyArmour;
			std::cout << "You have recieved some heavy armour of good quality" << std::endl;
		}
		
		return toRet;
	};

	short returnHP() {
		std::srand(std::time(0));
		short random = rand() % 2 + 1;
		short toRet = 0;
		if (random == 1)
		{
			toRet = steak;
			std::cout << "You have recieved steak" << std::endl;
		}
		else if (random == 2)
		{
			toRet = ale;
			std::cout << "You have recieved ale" << std::endl;
		}

		return toRet;
	};
	short returnDodge() {
		std::srand(std::time(0));
		short random = rand() % 2 + 1;
		short toRet = 0;
		if (random == 1)
		{
			toRet = lightArmour;
			std::cout << "You have recieved lightarmour" << std::endl;
		}
		else if (random == 2)
		{
			toRet = smokeBomb;
			std::cout << "You have recieved the SmokeBomb" << std::endl;
		}

		return toRet;
	};

};