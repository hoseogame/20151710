#include "print.h"
#include "action.h"

int main()
{
	int i = 0;
	Action HEXAGame;
	Print SNAKEGame;
	cout << "���� ������ �Ͻðڽ��ϱ�?" << endl;
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
		cout << "�߸����̽��ϴ�." << endl;
		break;
	}
}
