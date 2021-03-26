#include "Header/King_Zombies.h"
#include "Header/Bases_Class.h"
King_Zombies::King_Zombies() {
	dead = true;
	hp = 30;
	speed = 15;
	can_not_see = -3700;
	x1 = can_not_see;
	x2 = can_not_see;
	x3 = can_not_see;
	x4 = can_not_see;
	restart_hp = 0;
	boss_RIP = false;
}
void King_Zombies::Logic(Bases_Class& base, int& kol_skill) {
	if (base.score == 1000)//The first boss spawns when the score is 1000
		restart_hp = 1, dead = false, x1 = 30, x2 = 29, x3 = 29, x4 = 30;
	if (!dead)//If the boss is alive he moves
		if (base.score % speed == 0)
			x1--, x2--, x3--, x4--;
	if (hp == 0)
		dead = true, base.coin += 10, kol_skill += 50, boss_RIP = true, hp = 30;
	if (dead) x1 = x2 = x3 = x4 = can_not_see;
	if (x2 == 3)//If the boss reaches the base, it will take damage
		base.hp_base--;
}