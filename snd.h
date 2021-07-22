/******************************************************************************
BINIAX SOUND-RELATED DEFINITIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

#ifndef _BNX_SND_H
#define _BNX_SND_H

/******************************************************************************
INCLUDES
******************************************************************************/

#include <SDL/SDL_mixer.h>

#include "inc.h"

/******************************************************************************
CONSTANTS
******************************************************************************/

#define cSndChannels	8
#define cSndMaxMusic	8
#define cSndMenu		7

enum _BNX_Sounds {
	cSndNone =	0,
	cSndTake,
	cSndFail,
	cSndScroll,
	cSndShake,
	cSndSweep,
	cSndLast,
};

/******************************************************************************
LOCAL SOUND DATA (WAV SAMPLES, ETC.)
******************************************************************************/

typedef struct BNX_SND {

	BNX_INT32	curMusic;
	Mix_Chunk	*sounds[ cSndLast ];
	Mix_Music	*music[ cSndMaxMusic ];

} BNX_SND;

/******************************************************************************
FUNCTIONS
******************************************************************************/

BNX_BOOL sndInit();

void sndUpdate();

void sndPlay( BNX_GAME *game );

void sndPlayMusic( BNX_INT16 index );

void sndUpdateMusic( BNX_GAME *game, BNX_BOOL change );

//void sndPlay( BNX_INT16 index );

#endif
