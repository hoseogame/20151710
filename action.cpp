#include "action.h"


int Action::init()
{
	int i, j;
	manage.cur_x = 4;
	manage.cur_y = -2;
	manage.max_combo = 0;
	manage.stage_data[0].speed = 40;
	manage.stage_data[0].clear_block = 60;
	manage.stage_data[0].triple_rate = 8;
	manage.stage_data[1].speed = 37;
	manage.stage_data[1].clear_block = 70;
	manage.stage_data[1].triple_rate = 7;
	manage.stage_data[2].speed = 33;
	manage.stage_data[2].clear_block = 75;
	manage.stage_data[2].triple_rate = 6;
	manage.stage_data[3].speed = 30;
	manage.stage_data[3].clear_block = 80;
	manage.stage_data[3].triple_rate = 4;
	manage.stage_data[4].speed = 27;
	manage.stage_data[4].clear_block = 90;
	manage.stage_data[4].triple_rate = 2;
	manage.stage_data[5].speed = 22;
	manage.stage_data[5].clear_block = 100;
	manage.stage_data[5].triple_rate = 1;
	manage.stage_data[6].speed = 18;
	manage.stage_data[6].clear_block = 110;
	manage.stage_data[6].triple_rate = 1;
	manage.stage_data[7].speed = 10;
	manage.stage_data[7].clear_block = 99999;
	manage.stage_data[7].triple_rate = 1;
	for (i = 0; i<21; i++)
		for (j = 0; j<10; j++)
			manage.total_block[i][j] = 0;
	for (i = 0; i<21; i++)
	{
		manage.total_block[i][0] = 9;
		manage.total_block[i][9] = 9;
	}
	for (i = 0; i<10; i++)
	{
		manage.total_block[20][i] = 9;
	}
	//���� seed�� �ֱ�
	srand((unsigned)time(NULL));

	draw.make_new_block(manage.cur_block);
	draw.make_new_block(manage.next_block);
	draw.show_total_block();
	draw.show_next_block(manage.next_block);
	draw.show_gamestat();

	return 0;
}

int Action::move_down(int* x, int* y)
{
	int j;
	if (manage.total_block[*y + 3][*x] != 0)		//���� �ٴڿ� �������
	{
		for (j = 0; j<3; j++)
		manage.total_block[*y + j][*x] = manage.cur_block[j];
		manage.cur_block[0] = manage.next_block[0];
		manage.cur_block[1] = manage.next_block[1];
		manage.cur_block[2] = manage.next_block[2];
		draw.make_new_block(manage.next_block);
		draw.show_total_block();
		draw.show_next_block(manage.next_block);
		*x = 4;
		*y = -2;
		return 1;
	}
	else {
		(*y)++;
		return 0;
	}

}

int Action::find_fair(int combo)
{
	int fair_num = 0;
	int i = 0, j = 1, k = 0, l = 1;
	int tmp_shape;
	int tmp_x, tmp_y;
	int fair_arr[21][10];
	int is_del_block = 0;

	for (i = 0; i<21; i++)		//fair_arr �ʱ�ȭ
		for (j = 0; j<10; j++)
			fair_arr[i][j] = 0;

	for (i = 0; i<20; i++)			//����
	{
		for (j = 1; j<9; j++)		//����
		{
			tmp_shape = manage.total_block[i][j];

			if (tmp_shape == 0)	//��ĭ�ϰ�� �������� ����ĭ���� �ű�
				continue;

			for (k = 0; k<4; k++)	//����
			{
				tmp_y = i;
				tmp_x = j;
				fair_num = 0;
				for (l = 1; l<5; l++)	//����
				{
					switch (k)
					{
					case 0:		//���������� ���� �Ʒ� �밢�� ������
						tmp_y++;
						tmp_x--;
						break;
					case 1:		//���������� �Ʒ� ����
						tmp_y++;
						break;
					case 2:		//���������� ������ �Ʒ� �밢�� ����
						tmp_y++;
						tmp_x++;
						break;
					case 3:		//���������� ������ ����
						tmp_x++;
						break;
					}
					if (tmp_x <1 || tmp_x >12 || tmp_y > 20)
						break;
					if (manage.total_block[tmp_y][tmp_x] == tmp_shape)
						fair_num++;
					else
						break;
				}
				if (fair_num >= 2)
				{
					is_del_block = 1;
					tmp_y = i;
					tmp_x = j;
					for (l = 0; l <= fair_num; l++)
					{
						fair_arr[tmp_y][tmp_x] = 1;
						switch (k)
						{
						case 0:		//���������� ���� �Ʒ� �밢�� ������
							tmp_y++;
							tmp_x--;
							break;
						case 1:		//���������� �Ʒ� ����
							tmp_y++;
							break;
						case 2:		//���������� ������ �Ʒ� �밢�� ����
							tmp_y++;
							tmp_x++;
							break;
						case 3:		//���������� ������ ����
							tmp_x++;
							break;
						}
					}
				}

			}
		}
	}
	if (is_del_block == 1)	//3���̻��� ���޾� ������
	{
		combo++;
		draw.ani_del_block(fair_arr);
		draw.del_block(fair_arr, combo);
		draw.show_total_block();

		if (combo > manage.score)
			manage.max_combo = combo;

		find_fair(combo);
		return 1;
	}
	return 0;
}

int Action::HEXA()
{
	int i;
	char keytemp;
	int is_gameover;
	int shape_tmp;
	int blank_block[3] = { 0,0,0 };
	int return_tmp;
	draw.show_logo();
	while (1)
	{
		gamesystem.gotoxy(77, 23);		//ȭ�� �ܻ��� ���ֱ� ����
		cout << "  \b\b";
		draw.input_data();
		init();
		for (i = 1; 1; i++)
		{
			gamesystem.gotoxy(77, 23);		//ȭ�� �ܻ��� ���ֱ� ����
			cout << " \b";

			if (kbhit())
			{
				keytemp = getche();
				if (keytemp == EXT_KEY)
				{
					keytemp = getche();
					draw.show_cur_block(blank_block, manage.cur_x, manage.cur_y);	//�̵��ϱ��� ��ġ�� �� ����������
					switch (keytemp)
					{
					case KEY_UP:		//ȸ���ϱ�
						shape_tmp = manage.cur_block[2];
						manage.cur_block[2] = manage.cur_block[1];
						manage.cur_block[1] = manage.cur_block[0];
						manage.cur_block[0] = shape_tmp;

						break;
					case KEY_LEFT:		//�������� �̵�
						if (manage.cur_x>1)
						{
							if (manage.total_block[manage.cur_y + 2][manage.cur_x - 1] == 0)
								manage.cur_x--;
						}
						break;
					case KEY_RIGHT:		//���������� �̵�
						if (manage.cur_x<8)
						{
							if (manage.total_block[manage.cur_y + 2][manage.cur_x + 1] == 0)
								manage.cur_x++;
						}
						break;
					case KEY_DOWN:		//�Ʒ��� �̵�
						return_tmp = move_down(&manage.cur_x, &manage.cur_y);
						if (return_tmp == 1)		//���� �ٴڿ� �������
						{
							if ((manage.cur_y<0) && (manage.total_block[manage.cur_y + 3][manage.cur_x] != 0))
							{
								is_gameover = 1;
							}
							else {

								find_fair(0);
								draw.show_total_block();
								draw.show_gamestat();
							}
						}
						break;
					}
				}
				if (keytemp == KEY_SPACE)	//�����̽��ٸ� ��������
				{
					return_tmp = 0;
					while (return_tmp == 0)
						return_tmp = move_down(&manage.cur_x, &manage.cur_y);

					if ((manage.cur_y<0) && (manage.total_block[manage.cur_y + 3][manage.cur_x] != 0))
					{
						is_gameover = 1;
					}
					else {

						find_fair(0);
						draw.show_total_block();
						draw.show_gamestat();
					}

				}

				draw.show_cur_block(manage.cur_block, manage.cur_x, manage.cur_y);
			}

			if (i%manage.stage_data[manage.level].speed == 0)
			{
				if (manage.blocks>manage.stage_data[manage.level].clear_block)
					if (manage.level <7)
					{
						manage.level++;
						manage.blocks = 0;
					}
				draw.show_cur_block(blank_block, manage.cur_x, manage.cur_y);	//�̵��ϱ��� ��ġ�� �� ����������
				return_tmp = move_down(&manage.cur_x, &manage.cur_y);		//���� �̵��Ѵ�.

				if (return_tmp == 1)		//���� �ٴڿ� �������	
				{
					if ((manage.cur_y<0) && (manage.total_block[manage.cur_y + 3][manage.cur_x] != 0))
					{
						is_gameover = 1;
					}
					else {

						find_fair(0);
						draw.show_total_block();
						draw.show_gamestat();
					}
				}
				draw.show_cur_block(manage.cur_block, manage.cur_x, manage.cur_y);
			}
			if (is_gameover == 1)
			{
				manage.show_gameover();
				gamesystem.SetColor(GRAY);
				break;
			}
			Sleep(13);
		}
	}
	return 0;
}
