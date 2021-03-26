#ifndef BASES_CLASS_H_
#define BASES_CLASS_H_
class Bases_Class {//The evacuator class to defend
public:
	int hp_base;
	bool shop_open;
	bool shop_score;
	int price_gun;
	bool open_menu;
	int score_menu;
	bool profile_open;
	bool profile_score;
	int score;
	int coin;
	Bases_Class();
	void Logic(bool& game_over);
	class Fencings {//Safety fence class
	public:
		bool build;
		int x;
		int y;
		int can_not_see;
		Fencings(int Y);
		void Logic();
	};
	//Store management function
	void Control_Menu(bool& game_over, int& LVL_Gun, int& time_recharge,int &henry_y, Fencings* arr_fencing);
};
#endif