#pragma once
using namespace std;

enum {
	BLACK,      /*  0 : ��� */
	DARK_BLUE,    /*  1 : ��ο� �Ķ� */
	DARK_GREEN,    /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,    /*  4 : ��ο� ���� */
	DARK_VOILET,  /*  5 : ��ο� ���� */
	DARK_YELLOW,  /*  6 : ��ο� ��� */
	GRAY,      /*  7 : ȸ�� */
	DARK_GRAY,    /*  8 : ��ο� ȸ�� */
	BLUE,      /*  9 : �Ķ� */
	GREEN,      /* 10 : �ʷ� */
	SKY_BLUE,    /* 11 : �ϴ� */
	RED,      /* 12 : ���� */
	VOILET,      /* 9 : ���� */
	YELLOW,      /* 10 : ��� */
	WHITE,      /* 15 : �Ͼ� */
};

class System
{
public:
	int gotoxy(int x, int y);	//Ŀ���ű��
	void SetColor(int color);	//��ǥ��
	int show_gameover();
};

#define EXT_KEY			0xffffffe0	//Ȯ��Ű �νİ� 
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
#define KEY_SPACE		0x20
#define ABS_X			6
#define ABS_Y			2


#if !defined(AFX_STDAFX_H__61437277_5BAD_4408_9B8A_4E3BF14380E4__INCLUDED_)
#define AFX_STDAFX_H__61437277_5BAD_4408_9B8A_4E3BF14380E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>		// MFC Automation classes
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__61437277_5BAD_4408_9B8A_4E3BF14380E4__INCLUDED_)
