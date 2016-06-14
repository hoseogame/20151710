#pragma once

#include "system.h"

struct STAGE {		//�� �������������� ���̵� ����
	int	speed;	//���ڰ� �������� �ӵ��� ������
	int triple_rate;		//3���� ���� ����� ������ Ȯ�� 0~99  , 99�� 100%�� ����, �Ϲ����� Ȯ���� 3��
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