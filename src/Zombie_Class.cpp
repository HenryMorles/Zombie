#include "Header/Zombie_Class.h"
#include "Header/Bases_Class.h"
#include "Header/King_Zombies.h"
Zombies_Class::Zombies_Class(int Y) {
	dead = true;
	hp = 2;
	speed = 10;
	x = 30;
	y = Y;

}
void Zombies_Class::Logic(Bases_Class& base, Hero_Class& henry, Hero_Class::Bullets* arr_bullet, Bases_Class::Fencings* arr_fencing, King_Zombies& zombie_king, Robo_Zombies& robo_zombie, int& rand2) {
	if (base.score % speed == 0)
		this->x--;
	for (int i = 0; i < 5; i++)
		x == arr_bullet[i].x && y == arr_bullet[i].y ? hp--, arr_bullet[i].x = 111000 : 0;
	for (int i = 0; i < 5; i++)
		x == arr_bullet[i].x + 1 && y == arr_bullet[i].y ? hp--, arr_bullet[i].x = 111000 : 0;
	this->x == 3 && base.score % 6 == 0 ? base.hp_base-- : 0;
	this->hp == 0 ? dead = true, base.coin++, henry.kol_skill += 5, henry.kill_zombie++, hp = 2 : 0;
	dead ? x = 100 : 0;
	dead == true && rand2 == rand() % 20 ? x = 30, dead = false : 0;
	x == 0 ? dead = true, hp = 2 : 0;
	for (int i = 0; i < 4; i++)
		x == arr_fencing[i].x && y == arr_fencing[i].y ? dead = true, base.coin++, henry.kill_zombie++, arr_fencing[i].build = false : 0;
	!zombie_king.dead || !robo_zombie.dead ? x = rand() % 10 + 30 : 0;
}
