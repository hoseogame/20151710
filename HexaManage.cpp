#include "HexaManage.h"

int HexaManage::show_gameover()
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

	Sleep(1000);

	getche();
	fflush(stdin);
	fflush(stdout);
	system("cls");
	return 0;
}