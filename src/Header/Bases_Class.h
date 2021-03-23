#ifndef BASES_CLASS_H_
#define BASES_CLASS_H_
class Bases_Class {
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
	void Setup();
	class Fencings {
	public:
		bool build;
		int x;
		int y;
		Fencings();
		void Logic(int Y);
	};
	void Control_Menu(bool& game_over, int& LVL_Gun, int& time_recharge,int &henry_y, Fencings* arr_fencing);
};
#endif