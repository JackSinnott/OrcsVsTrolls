#pragma once
#include "Character.h"
#include <iostream>
using namespace std;



 short Character::randomizeAction()
 {
	 std::srand(std::time(0));
	 short random = rand() % 3;
	 return random;
 }


 bool Character::getAlive()
 { 
	 return isAlive;
 }

 void Character::changeAliveStatus()
 {
	 if (isAlive == true) 
	 { 
		 isAlive = false;
	 }
	 else
	 {
		 isAlive = true;
	 }
 }

 short Character::getHealth()
 {
	 return 0;
 }

 
