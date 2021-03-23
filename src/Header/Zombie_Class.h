#include "Enemy_Class.h"
#include "Bases_Class.h"
#include "Hero_Class.h"
#ifndef ZOMBIE_H
#define ZOMBIE_H
class Zombies_Class : public Enemy_Class{
public:
	Zombies_Class(int Y);
	void Logic(Bases_Class &base, Hero_Class &henry, Hero_Class::Bullets arr_bullet[5], Bases_Class::Fencings arr_fencing[4], King_Zombies &zombie_king, Robo_Zombies &robo_zombie, int &rand2);
}; 
#endif