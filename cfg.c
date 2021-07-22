/******************************************************************************
BINIAX SETUP IMPLEMENTATIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

/******************************************************************************
INCLUDES
******************************************************************************/

#include "inc.h"


/******************************************************************************
FUNCTIONS
******************************************************************************/

#define _Cfg_Buffer 255

struct BNX_SETUP
{
	BNX_BOOL	sound;
	BNX_BOOL	music;
	BNX_BOOL	fullscreen;
} _Cfg;

BNX_BOOL cfgCheckRegistered( char * RegCode );

BNX_BOOL cfgInit()
{
	FILE	*f;
	char	buffer[ _Cfg_Buffer ];
	int		nTemp;

	_Cfg.sound = BNX_TRUE;
	_Cfg.music = BNX_TRUE;
	_Cfg.fullscreen = BNX_FALSE;

	f = fopen( "config.bnx2", "rt" );
	if ( f == 0 )
	{
		return BNX_FALSE;
	}

	fgets( buffer, _Cfg_Buffer, f );
	sscanf( buffer, "SOUND=%d", &nTemp );
	_Cfg.sound = (BNX_BOOL) nTemp;

	fgets( buffer, _Cfg_Buffer, f );
	sscanf( buffer, "MUSIC=%d", &nTemp );
	_Cfg.music = (BNX_BOOL) nTemp;

	fgets( buffer, _Cfg_Buffer, f );
	sscanf( buffer, "FULLSCREEN=%d", &nTemp );
	_Cfg.fullscreen = (BNX_BOOL) nTemp;

	fclose( f );

	return BNX_TRUE;
}

BNX_BOOL cfgGetSound()
{
	return _Cfg.sound;
}

BNX_BOOL cfgGetMusic()
{
	return _Cfg.music;
}

BNX_BOOL cfgGetFullscreen()
{
	return _Cfg.fullscreen;
}
