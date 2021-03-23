#include "Boss_Class.h"
#include "Bases_Class.h"
#ifndef ROBO_ZOMBIE_H
#define ROBO_ZOMBIE_H
class Robo_Zombies : public Boss_Class {
public:
	bool second_phase;
	int arr_xz[4]{ x1,x2,x3,x4 };
	Robo_Zombies();
	void Logic(Bases_Class &base, int &kol_skill);
	class Robo_Bullet {
	public:
		int bulletX;
		int bulletY;
		bool activ;
		Robo_Bullet();
		void Logic(int Y, Robo_Zombies& robo_zombie, Bases_Class& base);
	};
};
#endif