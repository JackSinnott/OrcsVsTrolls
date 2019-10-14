#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
#include "Structs.h"

using namespace std;

void runTextInfo(short t_bossNum, Character *t_char[]);				// Function declarations
void runTextBattle(short t_bossNum);
short runAttack(Character *t_char[]);
short runDefence(Character *t_char[]);
short runDodge(Character *t_char[]);
void runLevelUp(LootTable *itemPointers, Character *t_char[]);
void runBattle(short t_bossNum, Character *t_char[] );

int main()
{
	
	LootTable item;								// Loot table and pointer
	LootTable *itemPointers = &item;
	Character *gameCharacters[2];						// Pointer to an array of characters
	Character **gameCharactersArrPnt = gameCharacters;		// Pointer to a pointer of the array
	gameCharacters[0] = &Orc(1);									// Declaring the characters
	gameCharacters[1] = &Troll(4, 2, 2, 0);
	std::cout << "You've been on the road for days.... You're tired and hungry when you hear \na muffled noise from behind you. " << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Your hp: " << gameCharacters[0]->getHealth() 
				<< " Atk: " << gameCharacters[0]->attack()
				<< " Def: " << gameCharacters[0]->getShield() 
				<< " Dodge: " << gameCharacters[0]->getDodge() << std::endl;

	// Orc **superPTR = &player;  // Example of a pointer to pointer
	short bossNum = 1;
	cout << "You turn to face a pack of hideous trolls as they run at you ready for battle" << endl;
	system("PAUSE");
	while (gameCharacters[0]->getAlive() == true)
	{
		runTextInfo(bossNum, gameCharactersArrPnt);								// Setting current boss stats and outputting their info

		std::cout << "Enemy Stats hp: " << gameCharacters[1]->getHealth() 
				<< " Atk: " << gameCharacters[1]->attack()
				<< " Def: " << gameCharacters[1]->getShield() 
				<< " Dodge: " << gameCharacters[1]->getDodge() << std::endl;

		runBattle(bossNum, gameCharactersArrPnt);					// Battle loop, passing the double pointer and current boss number
		
		if (gameCharacters[0]->getAlive() == false)				// Checking if you have died
		{
			break;
		}
		runLevelUp(itemPointers, gameCharacters);			// run to the loot chest

		bossNum++;												// Next boss
	}
	
	std::cout << "Game Over" << std::endl;
	system("PAUSE");
}
void runBattle(short t_bossNum, Character *t_char[])
{
	bool battle = true;
	short input = 0;
	short stringReturn{ 0 };
	
	std::cout << "-----------------------------------------------------------------" << std::endl;
	while (battle == true)
	{
		cout << "What action do you take?" << endl;
		cout << "1: Attack, 2: Shield 3: Dodge" << endl;
		cin >> input;

		if (input == 1)
		{
			stringReturn = runAttack(t_char);					// Swaps to the specific function based on the user's input
		}
		else if (input == 2)
		{
			stringReturn = runDefence(t_char);
		}
		else if (input == 3)
		{
			stringReturn = runDodge(t_char);

		}
		runTextBattle(stringReturn);					// Battle info
		std::cout << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;
	
		std::cout << "Your health left: " << t_char[0]->getHealth() << std::endl;
		if (t_char[1]->getHealth() > 0) {													// Enemy health
			std::cout << "Enemys health left: " << t_char[1]->getHealth() << std::endl;
		}
		if (t_char[1]->getAlive() == false)					// Characters alive?
		{
			battle = false;
			system("PAUSE");
		}
		if (t_char[0]->getAlive() == false)
		{
			break;
		}
	}
}
short runAttack(Character *t_char[])
{
	short enemyMove = t_char[1]->randomizeAction();				// Randomize enemy action

	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		t_char[0]->decreaseHealth(t_char[1]->attack());
		t_char[1]->decreaseHealth(t_char[0]->attack());
		stringDecider = 0;
	}
	else if (enemyMove == 1)	// Shields
	{
		if (t_char[1]->getShield() >= t_char[0]->attack())			// If the shield is strong
		{
			t_char[0]->decreaseHealth(1);
			t_char[1]->weakenShield(t_char[0]->attack());
			stringDecider = 1;
		}
		else
		{
			t_char[1]->decreaseHealth(t_char[0]->attack() - t_char[1]->getShield());		// IF the shield is broken
			stringDecider = 9;
		}
		
	}
	else if (enemyMove == 2)	// Dodges
	{
		if (rand() % t_char[0]->getDodge() + 1 < t_char[1]->getDodge())
		{
			t_char[0]->decreaseHealth(1);
			stringDecider = 2;
		}
		else
		{
			t_char[1]->decreaseHealth(t_char[0]->attack() * 0.5);
			stringDecider = 10;
		}

	}
	return stringDecider;
}


short runDefence(Character *t_char[])
{
	short enemyMove = t_char[1]->randomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		if (t_char[0]->getShield() >= t_char[1]->attack())
		{
			t_char[1]->decreaseHealth(2);
			if (t_char[1]->getAlive() == true)
			{
				t_char[0]->weakenShield(t_char[1]->attack());
			}
			stringDecider = 3;
		}
		else
		{
			t_char[0]->decreaseHealth(t_char[1]->attack() - t_char[0]->getShield());
			stringDecider = 11;
		}
	}
	else if (enemyMove == 1)	// Shields
	{
		stringDecider = 4;
	}
	else if (enemyMove == 2)	// Dodges
	{
		stringDecider = 5;
	}
	return stringDecider;
}
short runDodge(Character *t_char[])
{
	short enemyMove = t_char[1]->randomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		if (rand() % (t_char[0]->getDodge()) + 1 < t_char[0]->getDodge())
		{
			t_char[0]->decreaseHealth(2);
			stringDecider = 6;
		}
		else
		{
			t_char[0]->decreaseHealth(t_char[0]->attack() * 0.5);
			stringDecider = 12;
		}
		
	}
	else if (enemyMove == 1)	// Shields
	{
		stringDecider = 7;
	}
	else if (enemyMove == 2)	// Dodges
	{
		stringDecider = 8;
	}
	return stringDecider;
}
void runLevelUp(LootTable *itemPointers, Character *t_char[])
{
	short input = 0;
	short newStats = 0;
	cout << "The pitiful creature is dead and you notice that he seemed to be protecting loot" << endl;
	cout << "Which stat would you like to increase?" << endl;
	cout << "Loot upgrades are randomised" << endl;
	cout << "1: Attack, 2: Shield 3: Dodge 4: Hp" << endl;
	cin >> input;
	while (input < 1 && input > 4)
	{
		cout << "1: Attack, 2: Shield 3: Dodge 4: Hp" << endl;
		cin >> input;
	}
	if (input == 1)				// Randomizes the loot based on the user's input and increases the player's stats based on that
	{
		newStats = itemPointers->returnAtk();
		t_char[0]->setStats(t_char[0]->getHealth(),t_char[0]->attack()+newStats, t_char[0]->getShield(), t_char[0]->getDodge());
	}
	else if (input == 2)
	{
		newStats = itemPointers->returnDef();
		t_char[0]->setStats(t_char[0]->getHealth(), t_char[0]->attack(), t_char[0]->getShield() + newStats, t_char[0]->getDodge());
	}
	else if (input == 3)
	{
		newStats = itemPointers->returnDodge();
		t_char[0]->setStats(t_char[0]->getHealth(), t_char[0]->attack(), t_char[0]->getShield(), t_char[0]->getDodge() + newStats);
	}
	else if (input == 4)
	{
		newStats = itemPointers->returnHP();
		t_char[0]->setStats(t_char[0]->getHealth() + newStats, t_char[0]->attack(), t_char[0]->getShield(), t_char[0]->getDodge());
	}
	std::cout << "Your stat has been increased" << std::endl;
	std::cout << "Your hp: " << t_char[0]->getHealth() << " Atk: " << t_char[0]->attack()  
						<< " Def: " << t_char[0]->getShield() << " Dodge: " << t_char[0]->getDodge() << std::endl;
}

void runTextInfo(short t_bossNum, Character *t_char[])
{
	switch (t_bossNum)
	{
	case 1:
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "A pitiful creature is this troll, best put it out of it's misery.... permanently" << std::endl;
		t_char[1]->setStats(4,2,2,0);
		break;
	case 2:
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "Fat but muscular, you get the feel that while slow a hit could be costly" << std::endl;
		t_char[1]->setStats(3,6,4,1);
		break;
	case 3:
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "Lithe and grinning, you may have your work cut out for you fighting this one!" << std::endl;
		t_char[1]->setStats(4,3,5,2);
		break;
	case 4:
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "The gleaming sword in his hands indicates a high rank... don't be wreckless" << std::endl;
		t_char[1]->setStats(8,3,6,2);
		break;
	case 5:
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "Is this a troll? It looks more like a giant!! God be good you may be dead... at least \n it'll be quick" << std::endl;
		t_char[1]->setStats(12,7,8,3);
		break;
	}
}

void runTextBattle(short t_bossNum)
{
	switch (t_bossNum)
	{
	case 0:
		std::cout << "You both cut chunks from each others armour" << std::endl;
		break;
	case 1:
		std::cout << "You feel a pain in your shoulder as your weapon strikes their shield" << std::endl;
		break;
	case 2:
		std::cout << "The enemy deftly avoids your swing and leaves you feeling pretty stupid" << std::endl;
		break;
	case 3:
		std::cout << "Wood flies from your shield but you feel you've gained the upper hand" << std::endl;
		break;
	case 4:
		std::cout << "You both hide behind your shields and wait.... and wait" << std::endl;
		break;
	case 5:
		std::cout << "A near miss.. but a miss nonetheless" << std::endl;
		break;
	case 6:
		std::cout << "You dive out of the way of the enemy.. his follow through connects with his knees" << std::endl;
		break;
	case 7:
		std::cout << "You dodge expecting an attack while your enemy holds up their shield..... kinda embarrassing" << std::endl;
		break;
	case 8:
		std::cout << "You both parry in opposite directions" << std::endl;
		break;
	case 9:
		std::cout << "Their shield shatters into splinters... The pain in your arm is getting almost unbearable" << std::endl;
		break;
	case 10:
		std::cout << "The enemy tries to dodge but you make contact" << std::endl;
		break;
	case 11:
		std::cout << "Your shield is late and you take damage from their swing" << std::endl;
		break;
	case 12:
		std::cout << "To slow you feel their weapon connect with you tearing skin" << std::endl;
		break;
	}
}