#include "Header/Hero_Class.h"
#include "Header/King_Zombies.h"
#include "Header/Robo_Zombies.h"
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
void Hero_Class::Bullets::Update(Hero_Class& henry) {
	int tempX;
	int tempY;
	active = true, tempX = henry.x, tempY = henry.y, x = tempX, y = tempY, henry.recharge = henry.time_recharge;
}
void Hero_Class::Logic() {
	if(kol_skill < 50)
		LVL = 1;
	else if(kol_skill > 50 && kol_skill < 100)
		LVL = 2;
	else if(kol_skill > 100 && kol_skill < 200)
		LVL = 3;
	else if(kol_skill > 200 && kol_skill < 400) 
		LVL = 4;
	else if(kol_skill > 400 && kol_skill < 700)
		LVL = 5;
	else if(kol_skill > 700 && kol_skill < 1100) 
		LVL = 6;
	else if(kol_skill > 1100 && kol_skill < 1600 ) 
		LVL = 7;
	else if(kol_skill > 1600 && kol_skill < 2200 ) 
		LVL = 8;
	else if(kol_skill > 2200 && kol_skill < 2900 ) 
		LVL = 9;
	else if(kol_skill > 2900 && kol_skill < 3700 ) 
		LVL = 9;
	else if(kol_skill > 3700)
		LVL = 10;
	if (recharge)
		recharge--;
}
void Hero_Class::SetName(std::string name) {
	this->name = name;
}
Hero_Class::Bullets::Bullets() {
	x = 1100;
	y = 1100;
	active = false;
}
void Hero_Class::Bullets::Logic(King_Zombies& zombie_king, Robo_Zombies &robo_zombie, Robo_Zombies::Robo_Bullet* arr_robo_b, int& width) {
	if(zombie_king.x1 == x || zombie_king.x2 == x || zombie_king.x3 == x || zombie_king.x4 == x)
		zombie_king.hp--, x = 11100;
	if(robo_zombie.x1 == x || robo_zombie.x2 == x || robo_zombie.x3 == x || robo_zombie.x4 == x)
		robo_zombie.hp--, x = 11100;
	for (int i = 0; i < 4; i++)
			if(robo_zombie.arr_xz[i] == x)
				robo_zombie.hp--, x = 100;
	for (int i = 0; i < 3; i++)
		if(arr_robo_b[i].bulletX == x && arr_robo_b[i].bulletY == y) 
			arr_robo_b[i].bulletX = 1234, x = 11100, arr_robo_b[i].activ = false;
	this->active ? x++ : 0;//Bullet movement
	if(this->x == width)
		this->active = false;
}