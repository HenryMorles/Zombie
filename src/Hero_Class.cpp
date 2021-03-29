#include "Header/Hero_Class.h"
#include "Header/King_Zombies.h"
#include "Header/Robo_Zombies.h"
#include <iostream>
Hero_Class::Hero_Class() {
	LVL = 1;
	kol_skill = 0;
	x = 1;
	y = 3;
	recharge = 0;
	time_recharge = 10;
	kill_zombie = 0;
	LVL_Gun = 1;
}
void Hero_Class::Bullets::Update(Hero_Class& henry) {//Reusing bullets
	int tempX;
	int tempY;
	active = true, tempX = henry.x, tempY = henry.y, x = tempX, y = tempY, henry.recharge = henry.time_recharge;
}
void Hero_Class::Logic() {
	//LVL up
	if (kol_skill < 50)
		LVL = 1;
	else if (kol_skill > 50 && kol_skill < 100)
		LVL = 2;
	else if (kol_skill > 100 && kol_skill < 200)
		LVL = 3;
	else if (kol_skill > 200 && kol_skill < 400)
		LVL = 4;
	else if (kol_skill > 400 && kol_skill < 700)
		LVL = 5;
	else if (kol_skill > 700 && kol_skill < 1100)
		LVL = 6;
	else if (kol_skill > 1100 && kol_skill < 1600)
		LVL = 7;
	else if (kol_skill > 1600 && kol_skill < 2200)
		LVL = 8;
	else if (kol_skill > 2200 && kol_skill < 2900)
		LVL = 9;
	else if (kol_skill > 2900 && kol_skill < 3700)
		LVL = 9;
	else if (kol_skill > 3700)
		LVL = 10;
	if (recharge)
		recharge--;
}
void Hero_Class::Drawing_on_the_map(int X, int Y) {
	if (x == X && y == Y)
		std::cout << '$';
}
Hero_Class::Bullets::Bullets() {
	x = 1100;
	y = 1100;
	active = false;
	can_not_see = -1000;
}
void Hero_Class::Bullets::Logic(King_Zombies& zombie_king, Robo_Zombies& robo_zombie, Robo_Zombies::Robo_Bullet* arr_robo_b, int& width) {
	if (zombie_king.x1 == x || zombie_king.x2 == x || zombie_king.x3 == x || zombie_king.x4 == x)//Interaction with the first boss
		zombie_king.hp--, x = can_not_see;
	if (robo_zombie.x1 == x || robo_zombie.x2 == x || robo_zombie.x3 == x || robo_zombie.x4 == x)//Interaction with the second boss
		robo_zombie.hp--, x = can_not_see;
	for (int i = 0; i < 3; i++)//Interaction of boss bullets and player bullets
		if (arr_robo_b[i].bulletX == x && arr_robo_b[i].bulletY == y)
			arr_robo_b[i].bulletX = arr_robo_b[i].can_not_see, x = can_not_see, arr_robo_b[i].activ = false;
	active ? x++ : 0;//Bullet movement
	if (x == width)//If the bullet reaches the end of the map, it is removed
		active = false;
}