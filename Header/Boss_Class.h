#pragma once
#include "Enemy_Class.h"
#ifndef BOSS_CLASS_H
#define BOSS_CLASS_H
class Boss_Class : public Enemy_Class {
public:
	int restart_hp;
	bool boss_RIP;
	int x1;
	int x2;
	int x3;
	int x4;
};
#endif