#include "Draw.h"


int Draw::make_new_block(int* shape)
{
	int i;
	int rtn_tmp;
	rtn_tmp = rand() % 100;
	if (manage.stage_data[manage.level].triple_rate > rtn_tmp)	//트리플 확률로 트리플이 나올때
	{
		rtn_tmp = rand() % 5 + 1;
		shape[0] = rtn_tmp;
		shape[1] = rtn_tmp;
		shape[2] = rtn_tmp;
		return 0;
	}
	for (i = 0; i<3; i++)
	{
		shape[i] = rand() % 5 + 1;
	}
	return 0;
}

int Draw::show_cur_block(int* shape, int x, int y)
{
	int i;
	for (i = 0; i<3; i++)
	{
		if (y + i <0)		//화면 위쪽의 블럭은 보여주지 않음
			continue;

		gamesystem.gotoxy((x * 2) + ABS_X, y + i + ABS_Y);
		cout << "  \b\b";
		switch (shape[i])
		{
		case 0:
			gamesystem.SetColor(GRAY * 16);
			cout <<"  ";
			break;
		case 1:
			gamesystem.SetColor(BLUE | WHITE * 16);
			cout <<"●";
			break;
		case 2:
			gamesystem.SetColor(SKY_BLUE | WHITE * 16);
			cout <<"◆";
			break;
		case 3:
			gamesystem.SetColor(BLACK | WHITE * 16);
			cout<<"■";
			break;
		case 4:
			gamesystem.SetColor(GREEN | WHITE * 16);
			cout<<"♥";
			break;
		case 5:
			gamesystem.SetColor(RED | WHITE * 16);
			cout<< "★";
			break;
		}
	}
	return 0;
}

int Draw::show_next_block(int* shape)
{
	int i, j;
	//SetColor(((level+1)%6+1)|GRAY*16);
	for (i = 2; i<7; i++)
	{
		gamesystem.gotoxy(28, i);
		for (j = 0; j<5; j++)
		{
			if (i == 2 || i == 6 || j == 0 || j == 4)
			{
				gamesystem.SetColor(((manage.level + 1) % 6 + 1));
				cout<<"■";
			}
			else {
				gamesystem.SetColor(GRAY * 16);
				cout<<"  ";
			}

		}
	}
	show_cur_block(shape, 13, 1);
	return 0;
}

int Draw::show_gamestat()
{
	static int printed_text = 0;
	gamesystem.SetColor(GRAY);
	if (printed_text == 0)
	{
		gamesystem.gotoxy(29, 7);
		cout<<"STAGE";

		gamesystem.gotoxy(29, 9);
		cout<<"SCORE";

		gamesystem.gotoxy(29, 12);
		cout<<"BLOCKS";

		gamesystem.gotoxy(29, 15);
		cout<<"MAX COMBO";

	}
	gamesystem.gotoxy(35, 7);
	cout <<"%d"<< manage.level + 1;
	gamesystem.gotoxy(29, 10);
	cout<<"%10d"<<(int)manage.score;
	gamesystem.gotoxy(29, 13);
	cout<<"%10d"<< manage.stage_data[manage.level].clear_block - manage.blocks;
	gamesystem.gotoxy(29, 16);
	cout<<"%10d"<< manage.max_combo;
	return 0;
}

int Draw::show_total_block()
{
	int i, j;
	for (i = 0; i<21; i++)
	{
		for (j = 0; j<10; j++)
		{
			gamesystem.gotoxy(j * 2 + ABS_X, i + ABS_Y);
			switch (manage.total_block[i][j])
			{
			case 0:
				gamesystem.SetColor(GRAY | GRAY * 16);
				cout<<"  ";
				break;
			case 1:
				gamesystem.SetColor(BLUE | DARK_GRAY * 16);
				cout<<"●";
				break;
			case 2:
				gamesystem.SetColor(SKY_BLUE | DARK_GRAY * 16);
				cout<<"◆";
				break;
			case 3:
				gamesystem.SetColor(BLACK | DARK_GRAY * 16);
				cout<<"■";
				break;
			case 4:
				gamesystem.SetColor(GREEN | DARK_GRAY * 16);
				cout<<"♥";
				break;
			case 5:
				gamesystem.SetColor(RED | DARK_GRAY * 16);
				cout<<"★";
				break;
			case 9:
				gamesystem.SetColor(((manage.level % 6) + 1) * 16);
				cout<<"  ";
				break;
			}
		}
	}

	return 0;
}

int Draw::show_logo()
{
	int i, j;
	int cur_color = 0;
	gamesystem.gotoxy(13, 3);
	cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━┓";
	Sleep(100);
	gamesystem.gotoxy(13, 4);
	cout<<"┃★      ★  ★★★★★  ★      ★     ★★   ┃";
	Sleep(100);
	gamesystem.gotoxy(13, 5);
	cout<<"┃★      ★  ★            ★  ★     ★    ★ ┃";
	Sleep(100);
	gamesystem.gotoxy(13, 6);
	cout<<"┃★★★★★  ★★★★★      ★      ★★★★★┃";
	Sleep(100);
	gamesystem.gotoxy(13, 7);
	cout<<"┃★      ★  ★            ★  ★    ★      ★┃";
	Sleep(100);
	gamesystem.gotoxy(13, 8);
	cout<<"┃★      ★  ★★★★★  ★      ★  ★      ★┃";
	Sleep(100);
	gamesystem.gotoxy(13, 9);
	cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━┛";
	gamesystem.gotoxy(13, 10);
	cout<<" Ver 0.1                         Made By Jae-Dong  ";


	gamesystem.gotoxy(28, 20);
	cout<<"Please Press Any Key~!";

	for (i = 0; i >= 0; i++)
	{
		if (i % 8 == 0)
		{
			gamesystem.gotoxy(20, 19);
			for (j = 0; j<37; j++)
			{
				gamesystem.SetColor((cur_color + j) % 16 * 16);
				cout<<" ";
				//cur_color = (cur_color+j)%16;
			}
			if (cur_color >0)
				cur_color--;
			else
				cur_color = 15;
			//Sleep(100);
		}
		if (kbhit())
			break;
		Sleep(10);
	}

	getche();
	gamesystem.SetColor(GRAY);
	system("cls");

	return 0;
}

int Draw::input_data()
{
	int i = 0;
	gamesystem.SetColor(GRAY);
	gamesystem.gotoxy(10, 7);
	cout<<"┏━━━━<GAME KEY>━━━━━┓";
	Sleep(10);
	gamesystem.gotoxy(10, 8);
	cout<<"┃ UP   : Rotate Block        ┃";
	Sleep(10);
	gamesystem.gotoxy(10, 9);
	cout<<"┃ DOWN : Move One-Step Down  ┃";
	Sleep(10);
	gamesystem.gotoxy(10, 10);
	cout<<"┃ SPACE: Move Bottom Down    ┃";
	Sleep(10);
	gamesystem.gotoxy(10, 11);
	cout<<"┃ LEFT : Move Left           ┃";
	Sleep(10);
	gamesystem.gotoxy(10, 12);
	cout<<"┃ RIGHT: Move Right          ┃";
	Sleep(10);
	gamesystem.gotoxy(10, 13);
	cout<<"┗━━━━━━━━━━━━━━┛";


	while (i<1 || i>8)
	{
		gamesystem.gotoxy(10, 3);
		cout<<"Select Start level[1-8]:       \b\b\b\b\b\b\b";
		cin >> i;
	}


	manage.level = i - 1;
	system("cls");
	return 0;
}

int Draw::ani_del_block(int block_arr[21][10])
{
	int i, j, k;

	for (k = 0; k<6; k++)
	{
		for (i = 0; i<21; i++)
		{
			for (j = 1; j<9; j++)
			{
				if (block_arr[i][j] == 0)
					continue;

				gamesystem.gotoxy(j * 2 + ABS_X, i + ABS_Y);
				switch (manage.total_block[i][j])
				{
				case 1:
					gamesystem.SetColor(BLUE | (DARK_GRAY + (k % 2)) * 16);
					cout<<"●";
					break;
				case 2:
					gamesystem.SetColor(SKY_BLUE | (DARK_GRAY + (k % 2)) * 16);
					cout << "◆";
					break;
				case 3:
					gamesystem.SetColor(BLACK | (DARK_GRAY + (k % 2)) * 16);
					cout << "■";
					break;
				case 4:
					gamesystem.SetColor(GREEN | (DARK_GRAY + (k % 2)) * 16);
					cout << "♥";
					break;
				case 5:
					gamesystem.SetColor(RED | (DARK_GRAY + (k % 2)) * 16);
					cout << "★";
					break;
				}


				Sleep(24);
			}

		}

	}
	return 0;
}

int Draw::del_block(int block_arr[21][10], int combo)
{
	int i, j, k;
	int block_num = 0;		//없애는 블럭의 개수
	for (i = 19; i >= 0; i--)
	{
		for (j = 1; j<9; j++)
		{

			if (block_arr[i][j] == 1)
			{
				manage.total_block[i][j] = 0;
				block_num++;
				manage.blocks++;

			}

		}
	}
	for (i = 0; i<20; i++)
	{
		for (j = 1; j<9; j++)
		{
			if (manage.total_block[i][j] != 0)
				continue;

			for (k = i; k >= 0; k--)	//블럭을비운 빈공간을 위에 있는 블럭으로 채운다.
			{
				if (k == 0)
				{
					manage.total_block[k][j] = 0;

				}
				else {
					manage.total_block[k][j] = manage.total_block[k - 1][j];

				}
			}

		}
	}

	//점수 계산
	manage.score += combo*1.3*(block_num * 12);
	return 0;
}