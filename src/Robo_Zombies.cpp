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
	can_not_see = -3004;
	second_phase = false;
}
void Robo_Zombies::Logic(Bases_Class& base, int& kol_skill) {
	if (base.score == 2000)//The second boss spawns when the score is 2000
		restart_hp = 1, dead = false, x1 = 30, x2 = 29, x3 = 29, x4 = 29;
	if ((!dead) && (x1 > 25 || second_phase) && (base.score % speed == 0))
		x1--, x2--, x3--, x4--;
	if (hp <= 25)//When the boss has less than half health, he goes into the second phase
		second_phase = true;
	if (!hp)
		dead = true, base.coin += 20, kol_skill += 70, boss_RIP = true, hp = 50;
	if (dead)
		x1 = x2 = x3 = x4 = can_not_see;
	if (x3 == 3)//If the boss reaches the base, it will take damage
		base.hp_base--;
}
Robo_Zombies::Robo_Bullet::Robo_Bullet() {
	can_not_see = -2300;
	bulletX = can_not_see;
	bulletY = can_not_see;
	activ = false;
}
void Robo_Zombies::Robo_Bullet::Logic(int Y, Robo_Zombies& robo_zombie, Bases_Class& base) {
	bulletY = Y;
	int RandZ = rand() % 10;
	if(robo_zombie.x2 == 27)//When the boss reaches coordinates 27, he starts shooting
		bulletX = robo_zombie.x1;
	if((bulletX == 3)&& (bulletY > 0 && bulletY < 5))//Damage base
		base.hp_base--, bulletX = can_not_see, activ = false;
	if (!robo_zombie.second_phase && activ == false && RandZ == rand() % 15)//Reuse
		activ = true, bulletX = robo_zombie.x1;
	if(!robo_zombie.second_phase&& base.score % 5 == 0)//Bullet speed
		bulletX--;
	if(robo_zombie.second_phase)//If the second phase of the boss is active, he does not shoot
		bulletX = can_not_see, bulletY = can_not_see;
}