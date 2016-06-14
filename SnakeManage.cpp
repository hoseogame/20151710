#include "SnakeManage.h"

int SnakeManage::init()
{
	srand(time(NULL));

	//�������� �ʱ�ȭ
	length = 1;
	abs_x = 2;
	abs_y = 2;
	speed = 25;
	direction = 3;
	last_direction = direction;

	//���ʱⰪ �Է�
	snake_tail = (struct BODY *)malloc(sizeof(struct BODY));
	snake_tail->x = 5;
	snake_tail->y = 3;
	snake_head = snake_tail;
	snake_tail = (struct BODY *)malloc(sizeof(struct BODY));
	snake_tail->x = 4;
	snake_tail->y = 3;
	snake_tail->next = NULL;
	snake_head->next = snake_tail;
	return 0;
}

int SnakeManage::free_all()
{
	struct BODY *tmp1, *tmp2;

	tmp1 = snake_head;
	tmp2 = snake_head->next;
	while (tmp2 != NULL)
	{
		free(tmp1);
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	return 0;
}

int SnakeManage::strike_check(int x, int y)
{
	struct BODY *tmp_body;
	if (x<0 || x>34 || y<0 || y>19)		//�Ӹ��� ���� �δ�ħ
		return 1;
	tmp_body = snake_head;
	while (tmp_body != NULL)
	{
		if ((tmp_body->x == x) && (tmp_body->y == y))
			return 1;
		tmp_body = tmp_body->next;
	}
	if (food_x == x && food_y == y)	//���̸� ������
		return 2;
	return 0;
}

int SnakeManage::show_gameover()
{
	SetColor(RED);
	gotoxy(15, 8);
	cout << "������������������������������";
	gotoxy(15, 9);
	cout << "��**************************��";
	gotoxy(15, 10);
	cout << "��*        GAME OVER       *��";
	gotoxy(15, 11);
	cout << "��**************************��";
	gotoxy(15, 12);
	cout << "������������������������������";
	fflush(stdin);
	Sleep(1000);

	getche();
	system("cls");
	return 0;
}