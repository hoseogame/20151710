#include "print.h"
#include "action.h"

int main()
{
	int i = 0;
	Action HEXAGame;
	Print SNAKEGame;
	cout << "무슨 게임을 하시겠습니까?" << endl;
	cout << "1.HEXA" << endl;
	cout << "2.Snake" << endl;
	cin >> i;
	switch (i)
	{
	case 1: 
		HEXAGame.HEXA();
		break;
	case 2:
		SNAKEGame.SNAKE();
		break;
	default:
		cout << "잘못고르셨습니다." << endl;
		break;
	}
}
