#include <string>
#include "King_Zombies.h"
#include "Robo_Zombies.h"
#ifndef HERO_H
#define HERO_H
class Hero_Class {//Player class
public:
	std::string name;
	int LVL;
	int kol_skill;
	int x;
	int y;
	int recharge;
	int time_recharge;
	int kill_zombie;
	int LVL_Gun;
	Hero_Class();
	void Logic();
	class Bullets {//The class of bullets that the player shoots
	public:
		int x;
		int y;
		bool active;
		int can_not_see;
		Bullets();
		void Update(Hero_Class& henry);//Using bullets in a circle
		void Logic(King_Zombies& zombie_king, Robo_Zombies& robo_zombie, Robo_Zombies::Robo_Bullet* arr_robo_b, int& width);
	};
};
#endif