#include "HexaManage.h"

int HexaManage::show_gameover()
{
	SetColor(RED);
	gotoxy(15, 8);
	cout << "旨收收收收收收收收收收收收收旬";
	gotoxy(15, 9);
	cout << "早**************************早";
	gotoxy(15, 10);
	cout << "早*        GAME OVER       *早";
	gotoxy(15, 11);
	cout << "早**************************早";
	gotoxy(15, 12);
	cout << "曲收收收收收收收收收收收收收旭";

	Sleep(1000);

	getche();
	fflush(stdin);
	fflush(stdout);
	system("cls");
	return 0;
}