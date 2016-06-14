#pragma once

#include "system.h"
#include "SnakeManage.h"

class Print 
{
public:
	int make_food();
	int move_snake(int dir);
	int make_tail(int dir);
	int show_game_frame();
	int SNAKE();
	
	SnakeManage manege;
	System gamesystem;
};