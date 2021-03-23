#include "Boss_Class.h"
#include "Bases_Class.h"
#ifndef ZOMBIE_KING_H
#define ZOMBIE_KING_H
class King_Zombies : public Boss_Class {
public:
	King_Zombies();
	void Logic(Bases_Class &base, int &kol_skill);
};
#endif