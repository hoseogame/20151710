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
	int length;			//꼬리의 길이
	int direction;		//현재 뱀의 머리가 향하는 방향. (멈춤:0, 위:1,왼쪽:2,오른쪽:3,아래:4)
	int last_direction;	//이전 스템에서 움직인 방향	//한스템에서 방향을 두번바꿀시 충돌 디버깅을 위함
	char screen[20][35];
	struct BODY *snake_head;
	struct BODY *snake_tail;

public:
	int free_all();		//프로그램을 끝내기전 할당된 메모리를 모두 해제한다.
	int strike_check(int x, int y);	//이동하려는 좌표
	int init();
	int show_gameover();
	friend class Print;
};