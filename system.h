#pragma once
using namespace std;

enum {
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VOILET,      /* 9 : 보라 */
	YELLOW,      /* 10 : 노랑 */
	WHITE,      /* 15 : 하양 */
};

class System
{
public:
	int gotoxy(int x, int y);	//커서옮기기
	void SetColor(int color);	//색표현
	int show_gameover();
};

#define EXT_KEY			0xffffffe0	//확장키 인식값 
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
