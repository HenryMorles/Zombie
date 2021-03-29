#include "Header/King_Zombies.h"
#include "Header/Bases_Class.h"
#include <iostream>
#include <windows.h>
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
void King_Zombies::Drawing_on_the_map(int X, int Y, Bases_Class& base) {
	if (X == x1 && Y == 1) {
		base.Col(0, 6); std::cout << "www"; base.Col(0, 7);
	}
	if (X == x2 && Y == 2) {
		base.Col(0, 2); std::cout << "(*_*)"; base.Col(0, 7);
	}
	if (X == x3 && Y == 3) {
		base.Col(0, 2); std::cout << "/(___)\\"; base.Col(0, 7);
	}
	if (X == x4 && Y == 4) {
		base.Col(0, 2); std::cout << "/   \\"; base.Col(0, 7);
	}
}
void King_Zombies::Logic(Bases_Class& base, int& kol_skill) {
	if (base.score == 1000)//The first boss spawns when the score is 1000
		restart_hp = 1, dead = false, x1 = 30, x2 = 29, x3 = 29, x4 = 30;
	if (hp == 0)
		dead = true, base.coin += 10, kol_skill += 50, boss_RIP = true, hp = 30;
	if (dead)
		x1 = x2 = x3 = x4 = can_not_see;
	else //If the boss is alive he moves
		if (base.score % speed == 0)
			x1--, x2--, x3--, x4--;
	if (x2 == 3)//If the boss reaches the base, it will take damage
		base.hp_base--;
}