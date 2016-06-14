#pragma once
#include "HexaManage.h"
#include "system.h"

class Draw 
{
public:
	int show_cur_block(int* shape, int x, int y);	//���� �������� ��ǥ��
	int show_next_block(int* shape);		//�������� �� ǥ��
	int show_total_block();	//�׿����ִ� ���� ȭ�鿡 ǥ���Ѵ�.
	int show_gamestat();
	int show_logo();
	int input_data();
	int make_new_block(int* shape);
	int ani_del_block(int block_arr[21][10]);		//���� ���� ã������ �ִϸ��̼�
	int del_block(int block_arr[21][10], int combo);	

	HexaManage manage;
	System gamesystem;
};