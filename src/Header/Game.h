#pragma once
#include <iostream>
#include <Windows.h>
#include "Bases_Class.h"
#include "Hero_Class.h"
#include "King_Zombies.h"
#include "Robo_Zombies.h"
#include "Zombie_Class.h"
#ifndef GAME_H
#define GAME_H
class Game {
	int test;
	int rand2;
	int width;
	bool game_over;
	bool new_game;
	int bullet_number;
	Bases_Class base;
	Bases_Class::Fencings arr_fencing[4];
	King_Zombies zombie_king;
	Robo_Zombies robo_zombie;
	Robo_Zombies::Robo_Bullet arr_robo_b[3];
	Zombies_Class arr_zombies[8]{ 1,2,3,4,1,2,3,4 };
	Hero_Class henry;
	Hero_Class::Bullets arr_bullet[5];
	void Logic_Game();
	void Map();
	void Control();
public:
	Game();
	void Start();
};
#endif