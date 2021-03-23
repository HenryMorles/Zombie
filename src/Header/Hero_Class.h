#include <string>
#include "King_Zombies.h"
#include "Robo_Zombies.h"
#ifndef HERO_H
#define HERO_H
class Hero_Class {
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
	void SetName(std::string name);
	Hero_Class();
	void Logic();
	void LVL_UP();
	void Setup();
	class Bullets {
	public:
		int x;
		int y;
		bool active;
		Bullets();
		void Update(Hero_Class& henry);
		void Logic(King_Zombies& zombie_king, Robo_Zombies& robo_zombie, Robo_Zombies::Robo_Bullet* arr_robo_b, int& width);
	};
};
#endif