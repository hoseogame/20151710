#pragma once
#include "HexaManage.h"
#include "system.h"

class Draw 
{
public:
	int show_cur_block(int* shape, int x, int y);	//현재 진행중인 블럭표시
	int show_next_block(int* shape);		//다음나올 블럭 표시
	int show_total_block();	//쌓여져있는 블럭을 화면에 표시한다.
	int show_gamestat();
	int show_logo();
	int input_data();
	int make_new_block(int* shape);
	int ani_del_block(int block_arr[21][10]);		//없앨 블럭을 찾았을때 애니메이션
	int del_block(int block_arr[21][10], int combo);	

	HexaManage manage;
	System gamesystem;
};