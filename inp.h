/******************************************************************************
BINIAX INPUT-RELATED DEFINITIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

#ifndef _BNX_INP_H
#define _BNX_INP_H

/******************************************************************************
INCLUDES
******************************************************************************/

#include "inc.h"

#define cInpKeyEnter		SDLK_RETURN
#define cInpKeyBackspace	SDLK_BACKSPACE

/******************************************************************************
LOCAL INPUT DATA (KEY FLAGS, POINTERS, ETC.)
******************************************************************************/

typedef struct BNX_INP
{

	BNX_BOOL	keyUp;
	BNX_BOOL	keyDown;
	BNX_BOOL	keyLeft;
	BNX_BOOL	keyRight;
	BNX_BOOL	keyAltUp;
	BNX_BOOL	keyAltDown;
	BNX_BOOL	keyAltLeft;
	BNX_BOOL	keyAltRight;
	BNX_BOOL	keyPageUp;
	BNX_BOOL	keyPageDown;
	BNX_BOOL	keyA;
	BNX_BOOL	keyB;
	BNX_BOOL	keyC;
	BNX_BOOL	keyQuit;
	BNX_BOOL	keyDel;
	char		letter;

	BNX_UINT32	moment;

} BNX_INP;

BNX_INP _Inp;

/******************************************************************************
FUNCTIONS
******************************************************************************/

BNX_BOOL inpInit();

void inpUpdate();

BNX_BOOL inpKeyLeft();
BNX_BOOL inpKeyRight();
BNX_BOOL inpKeyUp();
BNX_BOOL inpKeyDown();
BNX_BOOL inpKeyAltLeft();
BNX_BOOL inpKeyAltRight();
BNX_BOOL inpKeyAltUp();
BNX_BOOL inpKeyAltDown();
BNX_BOOL inpKeyPageUp();
BNX_BOOL inpKeyPageDown();
BNX_BOOL inpKeyA();
BNX_BOOL inpKeyB();
BNX_BOOL inpKeyC();
BNX_BOOL inpKeyDel();
BNX_BOOL inpExit();

char inpGetChar();

BNX_INP *inpDirect();


#endif
