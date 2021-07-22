/******************************************************************************
BINIAX SETUP IMPLEMENTATIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2006-2007
******************************************************************************/

/******************************************************************************
INCLUDES
******************************************************************************/
#include <string.h>
#include "inc.h"
#include <psppower.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspkernel.h>
#include <psputility.h>

#define chCursor '_'
#define chSpace ' '

BNX_HALL	Hof;

/******************************************************************************
FUNCTIONS
******************************************************************************/
void hofAddLetter( BNX_INT16 pos, char a, char *name );
void hofBlinkCursor( BNX_INT16 pos, char *name );
void hofResetCursor( BNX_INT16 pos, char *name );


void hofAddLetter( BNX_INT16 pos, char a, char *name )
{
	if ( pos < cHofNameLen-1 )
	{
		name[ pos ] = a;
	}
}

void hofBlinkCursor( BNX_INT16 pos, char *name )
{
	static BNX_INT16 delayer = 0;

	if ( pos < cHofNameLen-1 )
	{
		if ( (delayer & 1) == 0 )
		{
			if ( name[ pos ] == chSpace )
			{
				name[ pos ] = chCursor;
			}
			else
			{
				name[ pos ] = chSpace;
			}
			delayer = 0;
		}
		delayer ++;
	}
}

void hofResetCursor( BNX_INT16 pos, char *name )
{
	if ( pos < cHofNameLen-1 )
	{
		name[ pos ] = chSpace;
	}
}


BNX_BOOL hofInit()
{
	FILE		*file;
	BNX_INT16	i;
	

	for ( i = 0; i < cHofEntries; ++i )
	{
		strcpy( Hof.arcade[ i ].name, "JORDAN                       " );
		Hof.arcade[ i ].score = (cHofEntries - i) * cHofInitScore;

		strcpy( Hof.tactic[ i ].name, "JORDAN                       " );
		Hof.tactic[ i ].score = (cHofEntries - i) * cHofInitScore;
	}

	file = fopen( "hof.bnx2", "rb" );

	if ( file == (FILE *) NULL )
		return BNX_FALSE;

	fread( &Hof, 1, sizeof( BNX_HALL ), file );

	fclose( file );

	return BNX_TRUE;
}

BNX_BOOL hofSave()
{
	FILE		*file;

	file = fopen( "hof.bnx2", "wb" );

	if ( file == (FILE *) NULL )
		return BNX_FALSE;

	fwrite( &Hof, 1, sizeof( BNX_HALL ), file );

	fclose( file );

	return BNX_TRUE;
}

BNX_BOOL hofEnter( BNX_GAME *game )
{
	BNX_INT32		startTime;
	BNX_INT16		curPos = 0;
	BNX_INT16		i, j;
	char			cChar = 0;
	BNX_HALL_ENTRY	*recEntry = 0;

	switch ( game->mode )
	{
		case cModeRealtime:
			for ( i = 0; i < cHofEntries; ++i )
			{
				if ( Hof.arcade[ i ].score < game->score[ cPlayer1 ] )
				{
					recEntry = &Hof.arcade[ i ];
					break;
				}
			}
			for ( j = cHofEntries-1; j > i; --j )
			{
				strcpy( Hof.arcade[ j ].name, Hof.arcade[ j-1 ].name );
				Hof.arcade[ j ].score = Hof.arcade[ j-1 ].score;
			}
			break;
		case cModeTurn:
			for ( i = 0; i < cHofEntries; ++i )
			{
				if ( Hof.tactic[ i ].score < game->score[ cPlayer1 ] )
				{
					recEntry = &Hof.tactic[ i ];
					break;
				}
			}
			for ( j = cHofEntries-1; j > i; --j )
			{
				strcpy( Hof.tactic[ j ].name, Hof.tactic[ j-1 ].name );
				Hof.arcade[ j ].score = Hof.tactic[ j-1 ].score;
			}
			break;
		default:
			return BNX_TRUE;
	}

	if ( recEntry == 0 )
	{
		return BNX_FALSE;
	}
	
	char sVal[18];
        sceUtilityGetSystemParamString(PSP_SYSTEMPARAM_ID_STRING_NICKNAME,&sVal, 17);
	sprintf(recEntry->name," %-29s",sVal);
	//strcpy( recEntry->name, "                             " );
	//strcpy( recEntry->name, "                             " );
	recEntry->score = game->score[ cPlayer1 ];
	inpInit();
	do
	{
		startTime = sysGetTime();

		cChar = inpGetChar();
		if ( cChar > 0 )
		{
			hofAddLetter( curPos, cChar, recEntry->name );
			if ( curPos < cHofNameLen - 1 )
			{
				curPos++;
			}
		}
		if ( inpKeyDel() == BNX_TRUE )
		{
			hofResetCursor( curPos, recEntry->name );
			if ( curPos > 0 )
			{
				curPos--;
			}
		}
		hofBlinkCursor( curPos, recEntry->name );

		inpUpdate();
		gfxRenderHof( &Hof );
		gfxUpdate();
		sndUpdate();
		sysUpdate();

		// Synchronize with the clock
		while ( sysGetTime() - startTime < cDeltaTime )
		{
			sysUpdate();
		}
	}
	while ( inpKeyA() == BNX_FALSE && inpKeyB() == BNX_FALSE );
	hofResetCursor( curPos, recEntry->name );

	return BNX_TRUE;
}

void hofView()
{
	BNX_INT32	startTime;

	inpInit();
	do
	{
		startTime = sysGetTime();

		inpUpdate();
		gfxRenderHof( &Hof );
		gfxUpdate();
		sndUpdate();
		sysUpdate();

		// Synchronize with the clock
		while ( sysGetTime() - startTime < cDeltaTime )
		{
			sysUpdate();
		}
	}
	while ( inpKeyA() == BNX_FALSE );
}

BNX_HALL *hofGet()
{
	return (BNX_HALL *) &Hof;
}
