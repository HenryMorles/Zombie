#include "Header/King_Zombies.h"
#include "Header/Bases_Class.h"
King_Zombies::King_Zombies() {
	dead = true;
	hp = 30;
	speed = 15;
	x1 = 120;
	x2 = 120;
	x3 = 120;
	x4 = 120;
	restart_hp = 0;
	boss_RIP = false;
}
void King_Zombies::Logic(Bases_Class &base, int &kol_skill) {
	base.score == 1000 ? restart_hp = 1, dead = false, x1 = 30, x2 = 29, x3 = 29, x4 = 30 : 0;
	if (!dead)
		base.score% speed == 0 ? x1--, x2--, x3--, x4-- : 0;
	hp == 0 ? dead = true, base.coin += 10, kol_skill += 50, boss_RIP = true, hp = 30 : 0;
	dead ? x1 = 125, x2 = 124, x3 = 124, x4 = 125 : 0;
	x2 == 3 ? base.hp_base-- : 0;
}