#include "Boss_Class.h"
#include "Bases_Class.h"
#ifndef ZOMBIE_KING_H
#define ZOMBIE_KING_H
class King_Zombies : public Boss_Class { //First boss
public:
	King_Zombies();
	void Drawing_on_the_map(int X, int Y, Bases_Class& base);
	void Logic(Bases_Class &base, int &kol_skill);
};
#endif