/******************************************************************************
BINIAX QUICK TUTORIAL IMPLEMENTATIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2006-2007
******************************************************************************/

/******************************************************************************
INCLUDES
******************************************************************************/
#include <string.h>

#include "inc.h"
#include "lev.h"

/******************************************************************************
FUNCTIONS
******************************************************************************/
void showTutorial()
{
	BNX_GAME tutGame;

	tutGame.score[ cPlayer1 ]		= 0;
	tutGame.score[ cPlayer2 ]		= 0;
	tutGame.scroll					= cMaxScroll;
	tutGame.speed					= cMaxScroll;
	tutGame.message					= cTextIngameScore;
	tutGame.level					= cLevelInactive;
	tutGame.level_count				= cLevelInactive;
	tutGame.lines					= 0;
	tutGame.moment					= 0;
	tutGame.clears					= cClearInit;
	tutGame.ingame					= BNX_TRUE;
	tutGame.mode					= cModeRealtime;
	tutGame.best[ cModeRealtime ]	= 0;

	tutGame.player[ 0 ].e			= 1;
	tutGame.player[ cPlayer1 ].x	= 0;
	tutGame.player[ cPlayer1 ].y	= 0;

	tutGame.grid[0][0]=0;tutGame.grid[1][0]=0;tutGame.grid[2][0]=0;tutGame.grid[3][0]=0;tutGame.grid[4][0]=0;
	tutGame.grid[0][1]=0;tutGame.grid[1][1]=0;tutGame.grid[2][1]=0;tutGame.grid[3][1]=0;tutGame.grid[4][1]=0;
	tutGame.grid[0][2]=0;tutGame.grid[1][2]=0;tutGame.grid[2][2]=0;tutGame.grid[3][2]=0;tutGame.grid[4][2]=0;
	tutGame.grid[0][3]=(1<<4)+2;tutGame.grid[1][3]=(3<<4)+2;tutGame.grid[2][3]=0;tutGame.grid[3][3]=(3<<4)+1;tutGame.grid[4][3]=(1<<4)+2;
	tutGame.grid[0][4]=(2<<4)+3;tutGame.grid[1][4]=0;tutGame.grid[2][4]=4<<1+1;tutGame.grid[3][4]=(1<<4)+2;tutGame.grid[4][4]=(1<<4)+2;
	tutGame.grid[0][5]=(2<<4)+3;tutGame.grid[1][5]=(3<<4)+2;tutGame.grid[2][5]=0;tutGame.grid[3][5]=(3<<4)+1;tutGame.grid[4][5]=(3<<4)+1;
	tutGame.grid[0][6]=(3<<4)+1;tutGame.grid[1][6]=0;tutGame.grid[2][6]=4<<1+1;tutGame.grid[3][6]=(1<<4)+2;tutGame.grid[4][6]=(4<<4)+3;

	gfxRenderGame( &tutGame );

	while ( inpKeyUp() == BNX_FALSE )
	{
		gfxRenderGame( &tutGame );
		gfxUpdate();
		inpUpdate();
	}

	tutGame.grid;
}