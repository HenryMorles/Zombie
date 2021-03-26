#include "Header/Game.h"
#include <string>

Game::Game() {
	rand2 = rand() % 20;
	width = 30;
	game_over = true;
	new_game = true;
	bullet_number = 0;
}
void Col(int bg, int txt) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(bg << 4) | txt);
}
void setcur(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}
void Game::Logic_Game() {//Calling the logic of all objects
	for (int i = 0; i < 4; i++)
		arr_zombies[i].Logic(base, henry, arr_bullet, arr_fencing, zombie_king, robo_zombie, rand2);
	if (base.score > 1000)
		for (int i = 4; i < 8; i++)
			arr_zombies[i].Logic(base, henry, arr_bullet, arr_fencing, zombie_king, robo_zombie, rand2);
	for (int i = 0; i < 5; i++)
		arr_bullet[i].Logic(zombie_king, robo_zombie, arr_robo_b, width);
	henry.Logic();
	base.Logic(game_over);
	zombie_king.Logic(base, henry.kol_skill);
	robo_zombie.Logic(base, henry.kol_skill);
	for (int i = 0; i < 3; i++)
		arr_robo_b[i].Logic(i + 1, robo_zombie, base);
	for (int i = 0; i < 4; i++)
		arr_fencing[i].Logic();
}
void Game::Control() {//Control in game
	if (GetAsyncKeyState((unsigned short)'W') & 0x57)
		if (henry.y != 1)
			henry.y--;
	if (GetAsyncKeyState((unsigned short)'S') & 0x53)
		if (henry.y != 4)
			henry.y++;
	if (GetAsyncKeyState((unsigned short)'D') & 0x4B) {
		if (bullet_number == 0 && henry.recharge == 0)
			arr_bullet[0].Update(henry), bullet_number = 1;
		else if (bullet_number == 1 && henry.recharge == 0)
			arr_bullet[1].Update(henry), bullet_number = 2;
		else if (bullet_number == 2 && henry.recharge == 0)
			arr_bullet[2].Update(henry), bullet_number = 3;
		else if (bullet_number == 3 && henry.recharge == 0)
			arr_bullet[3].Update(henry), bullet_number = 4;
		else if (bullet_number == 4 && henry.recharge == 0)
			arr_bullet[4].Update(henry), bullet_number = 0;
	}
	if (GetAsyncKeyState((unsigned short)'M') & 0x4D) {
		base.open_menu = true;
		base.score_menu = true;
	}
}
void Game::Main_Menu() {//Main menu. Start game or exit
	system("cls");
	char str1[30];
	std::cout << "\t\t\t ZOMBIE GAME\n\n";
	std::cout << "1. Start the game\n" << "2. Exit\n";
	if (GetAsyncKeyState((unsigned short)'1') & 0x61) {
		std::cout << "Enter name: ";
		std::cin.get(str1, 30);
		henry.name = str1;
		game_over = false;
	}
	if (GetAsyncKeyState((unsigned short)'2') & 0x61)
		new_game = false;
}
void Game::Map() {//Rendering the map
	system("cls");
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == 6 - 1)
				std::cout << '#';
			else if (i != 0 && i != 6 - 1 && j == 3)
				std::cout << '|';
			else if (henry.x == j && henry.y == i)
				std::cout << '$';
			else if (arr_bullet[0].x == j && arr_bullet[0].y == i)
				std::cout << '.';
			else if (arr_bullet[1].x == j && arr_bullet[1].y == i)
				std::cout << '.';
			else if (arr_bullet[2].x == j && arr_bullet[2].y == i)
				std::cout << '.';
			else if (arr_bullet[3].x == j && arr_bullet[3].y == i)
				std::cout << '.';
			else if (arr_bullet[4].x == j && arr_bullet[4].y == i)
				std::cout << '.';
			else if (arr_zombies[0].x == j && arr_zombies[0].y == i)
				std::cout << '@';
			else if (arr_zombies[1].x == j && arr_zombies[1].y == i)
				std::cout << '@';
			else if (arr_zombies[2].x == j && arr_zombies[2].y == i)
				std::cout << '@';
			else if (arr_zombies[3].x == j && arr_zombies[3].y == i)
				std::cout << '@';
			else if (arr_zombies[4].x == j && arr_zombies[4].y == i)
				std::cout << '@';
			else if (arr_zombies[5].x == j && arr_zombies[5].y == i)
				std::cout << '@';
			else if (arr_zombies[6].x == j && arr_zombies[6].y == i)
				std::cout << '@';
			else if (arr_zombies[7].x == j && arr_zombies[7].y == i)
				std::cout << '@';
			else if (arr_fencing[0].x == j && arr_fencing[0].y == i)
				std::cout << '>';
			else if (arr_fencing[1].x == j && arr_fencing[1].y == i)
				std::cout << '>';
			else if (arr_fencing[2].x == j && arr_fencing[2].y == i)
				std::cout << '>';
			else if (arr_fencing[3].x == j && arr_fencing[3].y == i)
				std::cout << '>';
			else if (j == zombie_king.x1 && i == 1) {
				Col(0, 6); std::cout << "www"; Col(0, 7);
			}
			else if (j == zombie_king.x2 && i == 2) {
				Col(0, 2); std::cout << "(*_*)"; Col(0, 7);
			}
			else if (j == zombie_king.x3 && i == 3) {
				Col(0, 2); std::cout << "/(___)\\"; Col(0, 7);
			}
			else if (j == zombie_king.x4 && i == 4) {
				Col(0, 2); std::cout << "/   \\"; Col(0, 7);
			}
			else if (j == robo_zombie.x1 && i == 1)
				std::cout << "/\\/\\\\";
			else if (j == robo_zombie.x2 && i == 2)
				if (!robo_zombie.second_phase)
					std::cout << "(O_O)||";
				else
					std::cout << "(O_*)||";
			else if (j == robo_zombie.x3 && i == 3)
				std::cout << "=|__|\\\\";
			else if (j == robo_zombie.x4 && i == 4)
				std::cout << "//  \\\\";
			else if (j == arr_robo_b[0].bulletX && i == 1)
				std::cout << '*';
			else if (j == arr_robo_b[1].bulletX && i == 2)
				std::cout << '*';
			else if (j == arr_robo_b[2].bulletX && i == 3)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << "\n";
	}
	std::cout << "Score: " << base.score << "\n";
	Col(4, 7);
	setcur(2, 7); std::cout << "Base health: " << base.hp_base << "\t" << "Coins: " << base.coin << "\t";
	if (base.score_menu == 0)
		std::cout << "Open the menu:  'm'\n\n";
	if (base.score_menu == 1)
		std::cout << "Back to the game:  'm'\n\n";
	Col(0, 7);
	if (!zombie_king.dead) {
		if (zombie_king.restart_hp == 1)
			zombie_king.hp = 30, zombie_king.restart_hp = 0;
		std::cout << "\n\tZOMBIE KING \n \t";
		std::cout << "HP Zombie King: " << zombie_king.hp;
		std::cout << "\n";
	}
	if (!robo_zombie.dead) {
		if (robo_zombie.restart_hp == 1)
			robo_zombie.hp = 50, robo_zombie.restart_hp = 0;
		std::cout << "\n\tZOMBIE CYBORG \n \t";
		std::cout << "HP Zombie cyborg: " << robo_zombie.hp;
		std::cout << "\n";
	}
	if (base.open_menu) {
		Col(1, 7);
		setcur(2, 9); std::cout << "Profile - 'Z' \t Shop - 'X'\t Exit to the main menu - 'Q'\n";	Col(0, 7);
		if (base.profile_open) {
			Col(5, 0);
			setcur(2, 11); std::cout << "\tPlayer profile: " << henry.name << "\n";	Col(11, 0);
			std::cout << "Character level: " << henry.LVL << "\n";
			std::cout << "Zombie slain: " << henry.kill_zombie << "\n";
			std::cout << "Weapon level: " << henry.LVL_Gun << "\n";
			std::cout << "List of trophies: \n";
			if (zombie_king.boss_RIP) {
				Col(0, 6); std::cout << "www"; Col(0, 7); std::cout << "\t Zombie King Crown\n";
			}
			if (robo_zombie.boss_RIP)
				std::cout << "*\t Zombie cyborg eye\n";
			Col(0, 7);
		}
		if (base.shop_open) {
			Col(5, 0);
			setcur(2, 11); std::cout << "\t Shop:\n"; Col(11, 0);
			std::cout << "Replenish base health by 1 unit:\t 10 coins\t '1'\n";
			std::cout << "Upgrading weapons:   " << "Weapons level: " << henry.LVL_Gun << "  \t " << base.price_gun << " coins\t '2'\n";
			std::cout << "Build a safety fence:  \t  \t \t" << " 10 coins\t '3'\n"; Col(0, 7);
		}
	}
}
void Game::Setup() {//Returning objects to their original parameters for replaying
	base.Bases_Class::Bases_Class();
	for (int i = 0; i < 4; i++)
		arr_fencing[i].Bases_Class::Fencings::Fencings(i + 1);
	zombie_king.King_Zombies::King_Zombies();
	robo_zombie.Robo_Zombies::Robo_Zombies();
	for (int i = 0; i < 3; i++)
		arr_robo_b[i].Robo_Zombies::Robo_Bullet::Robo_Bullet();
	for (int i = 0; i < 4; i++)
		arr_zombies[i].Zombies_Class::Zombies_Class(i + 1);
	for (int i = 4; i < 8; i++)
		arr_zombies[i].Zombies_Class::Zombies_Class(i - 3);
	henry.Hero_Class::Hero_Class();
	for (int i = 0; i < 5; i++)
		arr_bullet[i].Hero_Class::Bullets::Bullets();
}
void Game::Start() {
	while (new_game) {
		Main_Menu();
		Setup();
		while (!game_over) {
			Map();
			Logic_Game();
			Control();
			while (base.open_menu) {
				Map();
				for (int i = 0; i < 4; i++)
					arr_fencing[i].Logic();
				base.Control_Menu(game_over, henry.LVL_Gun, henry.time_recharge, henry.y, arr_fencing);
			}
		}
	}
}