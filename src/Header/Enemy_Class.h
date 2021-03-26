#pragma once
#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H
class Enemy_Class {
public:
	int hp;
	int x;
	int y;
	bool dead;
	int speed;
	int can_not_see;//If the object should not be displayed on the map, these coordinates are assigned to it
};
#endif