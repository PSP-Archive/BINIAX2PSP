/******************************************************************************
BINIAX SYSTEM-RELATED IMPLEMENTATIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

/******************************************************************************
INCLUDES
******************************************************************************/

#include <stdlib.h>

#include "inc.h"

/******************************************************************************
FUNCTIONS
******************************************************************************/

BNX_BOOL sysInit()
{
	atexit( SDL_Quit );
	sysRandInit( sysGetTime() );

	return BNX_TRUE;
}

BNX_INT32 sysRand( BNX_INT32 max )
{
	return ( BNX_INT32 ) rand() % max;
}

void sysRandInit( BNX_UINT32 init )
{
	srand( init );
}

BNX_UINT32 sysGetTime()
{
	return ( BNX_UINT32 ) SDL_GetTicks();
}

void sysUpdate()
{
	SDL_Delay( 1 );
}

