#include"print.h"

int Print::make_food()
{
	manege.food_y = rand() % 20;
	manege.food_x = rand() % 35;
	while (manege.strike_check(manege.food_x, manege.food_y) == 1)
	{
		manege.food_y = rand() % 20;
		manege.food_x = rand() % 35;
	}

	gamesystem.gotoxy(77, 23);		//화면 깨짐을 막기위함
	fflush(stdout);

	gamesystem.SetColor(RED);
	gamesystem.gotoxy(manege.food_x * 2 + manege.abs_x, manege.food_y + manege.abs_y);
	cout << "◆";
	gamesystem.SetColor(BLACK);
	return 0;
}

int Print::move_snake(int dir)
{
	int tmp_x, tmp_y;
	int i;
	struct BODY *tmp_body;


	tmp_x = manege.snake_head->x;
	tmp_y = manege.snake_head->y;
	switch (manege.direction)
	{
	case 1:
		tmp_y--;
		break;
	case 2:
		tmp_x--;
		break;
	case 3:
		tmp_x++;
		break;
	case 4:
		tmp_y++;
		break;
	}
	i = manege.strike_check(tmp_x, tmp_y);
	if (i == 1)	//충돌할때
	{
		return 1;
	}

	gamesystem.gotoxy((manege.snake_tail->x * 2) + manege.abs_x, manege.snake_tail->y + manege.abs_y);	//이동후의 잔상지우기
	cout << "  ";



	gamesystem.gotoxy(77, 23);		//화면 깨짐을 막기위함
	fflush(stdout);

	gamesystem.SetColor(GRAY);
	gamesystem.gotoxy((manege.snake_head->x * 2) + manege.abs_x, manege.snake_head->y + manege.abs_y);	//이동후의 머리모양 잔상지우기
	cout << "○";
	gamesystem.gotoxy(tmp_x * 2 + manege.abs_x, tmp_y + manege.abs_y);	//머리모양 프린트하기
	cout << "●";
	gamesystem.gotoxy(77, 23);		//화면 깨짐을 막기위함
	gamesystem.SetColor(BLACK);


	tmp_body = (struct BODY *)malloc(sizeof(struct BODY));	//머리부분의 새로운 노드만들기
	tmp_body->x = tmp_x;
	tmp_body->y = tmp_y;
	tmp_body->next = manege.snake_head;
	manege.snake_head = tmp_body;


	while (tmp_body->next != manege.snake_tail)		//꼬리노드 지우기
		tmp_body = tmp_body->next;

	tmp_body->next = NULL;
	free(manege.snake_tail);
	manege.snake_tail = tmp_body;
	return i;
}

int Print::make_tail(int dir)
{
	int tmp_x, tmp_y;
	int i;
	struct BODY *tmp_body;


	tmp_x = manege.snake_head->x;
	tmp_y = manege.snake_head->y;
	switch (manege.direction)
	{
	case 1:
		tmp_y--;
		break;
	case 2:
		tmp_x--;
		break;
	case 3:
		tmp_x++;
		break;
	case 4:
		tmp_y++;
		break;
	}
	i = manege.strike_check(tmp_x, tmp_y);
	if (i == 1)	//충돌할때
	{
		return 1;
	}





	gamesystem.gotoxy(77, 23);		//화면 깨짐을 막기위함
	fflush(stdout);

	gamesystem.SetColor(GRAY);
	gamesystem.gotoxy((manege.snake_head->x * 2) + manege.abs_x, manege.snake_head->y + manege.abs_y);	//이동후의 머리모양 잔상지우기
	cout << "○";
	gamesystem.gotoxy(tmp_x * 2 + manege.abs_x, tmp_y + manege.abs_y);	//머리모양 프린트하기
	cout << "●";
	gamesystem.gotoxy(77, 23);		//화면 깨짐을 막기위함
	gamesystem.SetColor(BLACK);


	tmp_body = (struct BODY *)malloc(sizeof(struct BODY));	//머리부분의 새로운 노드만들기
	tmp_body->x = tmp_x;
	tmp_body->y = tmp_y;
	tmp_body->next = manege.snake_head;
	manege.snake_head = tmp_body;



	return i;
}

int Print::show_game_frame()
{
	int i;
	gamesystem.SetColor(GRAY);
	system("cls");
	gamesystem.gotoxy(0, 1);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	for (i = 2; i<22; i++)
	{
		gamesystem.gotoxy(0, i);
		cout << "┃";
		gamesystem.gotoxy(72, i);
		cout << "┃";
	}
	gamesystem.gotoxy(0, 20 + manege.abs_y);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	for (i = 4; i<20; i += 2)
	{
		gamesystem.gotoxy(76, i);
		cout << "○";
	}

	for (i = 5; i<20; i += 2)
	{
		gamesystem.gotoxy(75, i);
		cout << "○";
	}
	gamesystem.gotoxy(75, 2);
	cout << "Ｙ";
	gamesystem.gotoxy(75, 3);
	cout << "●";

	gamesystem.gotoxy(4, 0);
	cout << "Snake Ver 0.1                                    Made By Jae-Dong";
	return 0;
}

int Print::SNAKE()
{
	int i;
	char keytemp;
	int return_tmp = 0;


	manege.init();
	while (1)
	{
		gamesystem.gotoxy(77, 23);
		cout << " \b";
		show_game_frame();
		make_food();
		for (i = 1; 1; i++)
		{
			if (kbhit())
			{
				keytemp = getche();

				if (keytemp == EXT_KEY)
				{
					cout << "\b";
					keytemp = getche();
					switch (keytemp)
					{
					case KEY_UP:
						if (manege.last_direction != 4)
							manege.direction = 1;

						break;
					case KEY_LEFT:
						if (manege.last_direction != 3)
							manege.direction = 2;
						break;
					case KEY_RIGHT:
						if (manege.last_direction != 2)
							manege.direction = 3;

						break;
					case KEY_DOWN:
						if (manege.last_direction != 1)
							manege.direction = 4;
						break;
					}
				}
			}
			if (i%manege.speed == 0)
			{
				if (return_tmp == 2)	//꼬리가 늘어남
				{
					return_tmp = make_tail(manege.direction);
				}
				else {
					fflush(stdin);

					return_tmp = move_snake(manege.direction);	//단순히 이동
				}
				manege.last_direction = manege.direction;
				if (return_tmp == 1)		//충돌할때
				{
					manege.show_gameover();
					manege.free_all();
					break;
				}
				if (return_tmp == 2)		//먹이를 먹었을때
				{
					if (manege.length % 5 == 0)
						manege.speed--;

					if (manege.speed<1)
						manege.speed = 1;

					manege.length++;
					make_food();
					i = 1;	//스피드관련 변수 초기화
				}
			}
			gamesystem.SetColor(BLACK);
			gamesystem.gotoxy(77, 23);
			Sleep(10);
			gamesystem.SetColor(BLACK);
			gamesystem.gotoxy(77, 23);
		}
		manege.init();
	}
	return 0;
}