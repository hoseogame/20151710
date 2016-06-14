#pragma once
#include "system.h"

struct BODY {
	int	x;
	int y;
	struct BODY * next;
};

class SnakeManage :public System
{

private:
	int abs_x, abs_y;
	int food_x, food_y;
	int speed;
	int score;
	int length;			//������ ����
	int direction;		//���� ���� �Ӹ��� ���ϴ� ����. (����:0, ��:1,����:2,������:3,�Ʒ�:4)
	int last_direction;	//���� ���ۿ��� ������ ����	//�ѽ��ۿ��� ������ �ι��ٲܽ� �浹 ������� ����
	char screen[20][35];
	struct BODY *snake_head;
	struct BODY *snake_tail;

public:
	int free_all();		//���α׷��� �������� �Ҵ�� �޸𸮸� ��� �����Ѵ�.
	int strike_check(int x, int y);	//�̵��Ϸ��� ��ǥ
	int init();
	int show_gameover();
	friend class Print;
};