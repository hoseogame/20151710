#pragma once
#include "HexaManage.h"
#include "Draw.h"

class Action 
{
public:
	int init();					//�������� �ʱ�ȭ
	int move_down(int* x, int* y);	//���� �ٴڿ� �������
	int find_fair(int combo);		//¦�� �´°��� ã��
	int HEXA();
	 
	System gamesystem;
	HexaManage manage;
	Draw draw;

};