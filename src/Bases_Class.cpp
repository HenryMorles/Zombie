#include "Header/Bases_Class.h"
#include <Windows.h>
Bases_Class::Bases_Class() {
	hp_base = 10;
	shop_open = false;
	shop_score = false;
	price_gun = 10;
	open_menu = false;
	score_menu = 0;
	profile_open = false;
	profile_score = false;
	score = 0;
	coin = 0;
}
void Bases_Class::Logic(bool& game_over) {
	score++;
	if (hp_base <= 0)
		game_over = true;
}
//Control in game
void Bases_Class::Control_Menu(bool& game_over, int& LVL_Gun, int& time_recharge, int& henry_y, Fencings* arr_fencing) {
	if (GetAsyncKeyState((unsigned short)'M') & 0x4D) {//Open the menu
		open_menu = false;
		profile_open = false;
		shop_open = false;
		score_menu = false;
	}
	if (GetAsyncKeyState((unsigned short)'Z') & 0x51) {//If the menu is open open the profile
		profile_open = true;
		shop_open = false;
		shop_score = false;
	}
	if (GetAsyncKeyState((unsigned short)'X') & 0x51) {//Open the shop
		if (!shop_open)
			shop_open = true;
		profile_open = false;
		profile_score = false;
	}
	if (GetAsyncKeyState((unsigned short)'Q') & 0x51) {//Exit to the main menu
		game_over = true;
		open_menu = false;
	}
	if (GetAsyncKeyState((unsigned short)'1') & 0x51) {//Replenish base health
		if (shop_open)
			if (coin >= 10 && hp_base <= 9)
				hp_base++, coin -= 10;
	}
	if (GetAsyncKeyState((unsigned short)'2') & 0x51) {//Increase weapon level
		if (shop_open) {
			if (coin >= price_gun && LVL_Gun <= 9) {
				if (LVL_Gun % 2 == 0)
					time_recharge--;
				LVL_Gun++;
				coin -= price_gun;
				price_gun += 10;
			}
		}
	}
	if (GetAsyncKeyState((unsigned short)'3') & 0x51) {//Install protective spikes
		if (shop_open) {
			if (coin >= 10) {
				int j = 1;
				for (int i = 0; i < 4; i++, j++)
					if (henry_y == j && !arr_fencing[i].build)
						arr_fencing[i].build = true, arr_fencing[i].y = j, coin -= 10;
			}
		}
	}
}
Bases_Class::Fencings::Fencings(int Y) {
	 build = false;
	 can_not_see = -7200;
	 x = 100;
	 y = Y;
}
void Bases_Class::Fencings::Logic() {
	build ? x = 4 : x = can_not_see;
}