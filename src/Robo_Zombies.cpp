#include "Header/Robo_Zombies.h"
#include "Header/Bases_Class.h"
#include "Header/Hero_Class.h"
Robo_Zombies::Robo_Zombies() {
	dead = true;
	hp = 50;
	speed = 12;
	restart_hp = 0;
	boss_RIP = false;
	x1 = -433;
	x2 = -433;
	x3 = -433;
	x4 = -433;

	second_phase = false;
}
void Robo_Zombies::Logic(Bases_Class& base, int& kol_skill) {
	base.score == 2000 ? restart_hp = 1, dead = false, x1 = 30, x2 = 29, x3 = 29, x4 = 29 : 0;
	!dead ? x1 > 25 || second_phase ? base.score % speed == 0 ? x1--, x2--, x3--, x4-- : 0 : 0 : 0;
	hp <= 25 ? second_phase = true : 0;
	hp == 0 ? dead = true, base.coin += 20, kol_skill += 70, boss_RIP = true, hp = 50 : 0;
	dead ? x1 = -225, x2 = -224, x3 = -224, x4 = -225 : 0;
	x3 == 3 ? base.hp_base-- : 0;
}
Robo_Zombies::Robo_Bullet::Robo_Bullet() {
	bulletX = -1234;
	bulletY = 1234;
	activ = false;
}
void Robo_Zombies::Robo_Bullet::Logic(int Y, Robo_Zombies& robo_zombie, Bases_Class& base) {
	bulletY = Y;
	int RandZ = rand() % 10;
	robo_zombie.x2 == 27 ? bulletX = robo_zombie.x1 : 0;
	bulletX == 3 ? bulletY > 0 && bulletY < 5 ? base.hp_base--, bulletX = -2220, activ = false : 0 : 0;
	!robo_zombie.second_phase && activ == false && RandZ == rand() % 15 ? activ = true, bulletX = robo_zombie.x1 : 0;
	!robo_zombie.second_phase && base.score % 5 == 0 ? bulletX-- : 0;
	robo_zombie.second_phase ? bulletX = -2220, bulletY = 89186 : 0;
}