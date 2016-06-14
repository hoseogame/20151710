#pragma once
#include "HexaManage.h"
#include "Draw.h"

class Action 
{
public:
	int init();					//각종변수 초기화
	int move_down(int* x, int* y);	//블럭이 바닥에 닿았을때
	int find_fair(int combo);		//짝이 맞는것을 찾음
	int HEXA();
	 
	System gamesystem;
	HexaManage manage;
	Draw draw;

};