#include "Header/Zombie_Class.h"
#include "Header/Bases_Class.h"
#include "Header/King_Zombies.h"
Zombies_Class::Zombies_Class(int Y) {
	dead = true;
	hp = 2;
	speed = 10;
	x = 30;
	y = Y;
	can_not_see = -2200;
}
void Zombies_Class::Logic(Bases_Class& base, Hero_Class& henry, Hero_Class::Bullets* arr_bullet, Bases_Class::Fencings* arr_fencing, King_Zombies& zombie_king, Robo_Zombies& robo_zombie, int& rand2) {
	if (base.score % speed == 0)
		this->x--;
	for (int i = 0; i < 5; i++)//Interaction with player bullets
		if (x == arr_bullet[i].x && y == arr_bullet[i].y)
			hp--, arr_bullet[i].x = arr_bullet[i].can_not_see;
	for (int i = 0; i < 5; i++)
		if (x == arr_bullet[i].x + 1 && y == arr_bullet[i].y)
			hp--, arr_bullet[i].x = arr_bullet[i].can_not_see;
	if (this->x == 3 && base.score % 10 == 0) base.hp_base--;//Damage base
	if (this->hp == 0)
		dead = true, base.coin++, henry.kol_skill += 5, henry.kill_zombie++, hp = 2;
	if (dead)//Zombie death
		x = can_not_see;
	if (dead == true && rand2 == rand() % 20)//Zombie respawn
		x = 30, dead = false;
	if (x == 0)//Respawn a zombie if it reaches the base
		dead = true, hp = 2;
	for (int i = 0; i < 4; i++)//Interaction with fences
		if (x == arr_fencing[i].x && y == arr_fencing[i].y)
			dead = true, base.coin++, henry.kill_zombie++, arr_fencing[i].build = false;
	if (!zombie_king.dead || !robo_zombie.dead)//If there is a boss fight, zombies will not spawn
		x = rand() % 10 + 30;
}
