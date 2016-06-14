#pragma once

#include "system.h"

struct STAGE {		//각 스테이지마다의 난이도 설정
	int	speed;	//숫자가 낮을수록 속도가 빠르다
	int triple_rate;		//3개가 같은 모양이 나오는 확률 0~99  , 99는 100%로 나옴, 일반적인 확률은 3임
	int clear_block;
};

class HexaManage :public System
{
private:
	int cur_block[3];
	int next_block[3];
	int cur_x, cur_y;
	int level;
	int blocks;
	int max_combo;
	double score;
	int total_block[21][10];
	STAGE stage_data[8];

public:
	int show_gameover();
	friend class Draw;
	friend class Action;
};