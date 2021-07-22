/******************************************************************************
BINIAX GRAPHICS-RELATED DEFINITIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

#ifndef _BNX_GFX_H
#define _BNX_GFX_H

/******************************************************************************
INCLUDES
******************************************************************************/

#include "inc.h"

//#include <SDL.h>
#include <SDL/SDL_image.h>

/******************************************************************************
GRAPHICS CONSTANTS
******************************************************************************/

#define cGfxScreenX	 	640	
#define cGfxScreenY	 	480	
#define cGfxColorDepth 32

#define cGfxZeroX	25	
#define cGfxZeroY	421	
#define cGfxNextPlusX	38
#define cGfxShieldPlusX	0

#define cGfxPairPlusX	102
#define cGfxPairPlusY	-51

#define cGfxPlayerPlusX 19	
#define cGfxMarkerPlusX 56	
#define cGfxMarkerPlusY	-51

#define cGfxFontSizeX	13
#define cGfxFontSizeY	26	
#define cGfxFontTileX	14
#define cGfxFontTileY	28

#define cGfxInfoBar		24 	//30	
#define cGfxSpraySize	5
#define cGfxSpray		300

#define cGfxScoreX	 	24 	//30	
#define cGfxScoreY		43	//54 
#define cGfxBestX		264	//330
#define cGfxBestY		43	//54
#define cGfxScore1X		24 	//30	
#define cGfxScore1Y		22	//28
#define cGfxScore2X	 	24 	//30	
#define cGfxScore2Y		54	//68

#define cGfxMoveCX		552  	//690
#define cGfxMoveCY		148  	//185 
#define cGfxLegendX		546	//683	
#define cGfxLegendY		120	//150

#define cGfxOptionX		265	//332
#define cGfxOptionY		192	//240
#define cGfxOptionDY		29	//36
#define cGfxMenuEffect	500
#define cGfxMessageX	75
#define cGfxMessageY	168		//210	
#define cGfxRunsLeftX	( cGfxScreenX >> 1 )
#define cGfxRunsLeftY	456	//570
#define cGfxClearsAX	547	//684 
#define cGfxClearsAY	264	//330 
#define cGfxClearsTX	547	//684
#define cGfxClearsTY	436	//545

#define cGfxHelpX		( cGfxScreenX >> 1 )
#define cGfxHelpY		7
#define cGfxHelpDY		24	
#define cGfxHelpLines	(( cGfxScreenY - cGfxHelpY ) / cGfxHelpDY)
#define cGfxHelpPage	(cGfxHelpLines >> 1)

#define cGfxFall		4
#define cGfxShake		3
#define cGfxCursors		2

#define cGfxBrickElement 4
#define cGfxMaxElements ( cMaxElements + 1 )

#define cGfxWinBlending 180	

#define cGfxCursorSpeed	3
#define cGfxMaxTextLine	128

#define cGfxMaxPartTime		60
#define cGfxExePartTime		6
#define cGfxParticleSet		4
#define cGfxMaxParticles	cGridX * cGridY
#define cGfxParticleLife	50
#define cGfxParticleSpeed	30
#define cGfxParticleMinSp	10
#define cGfxParticleFall	4
#define cGfxParticleState	3

#define cGfxMaxWave			16
#define cGfxStrLen			200

#define cGfxMaxAlpha		255
#define cGfxAlphaStep		16
#define cGfxWelcomeWait		1200

#define cGfxJTextLive		30
#define cGfxJTextSpeed		-10

#define cGfxRoadmapBX		96
#define cGfxRoadmapBY		329
#define cGfxRoadmapDY		-51
#define cGfxRoadmapBSize	50
#define cGfxRoadmapIter		32

#define cGfxTutorialSteps	12

/******************************************************************************
LOCAL GRAPHICS DATA (VIDEO BUFFERS, IMAGES, FONTS, ETC.)
******************************************************************************/

typedef char BNX_HELPLINE[ cGfxMaxTextLine ];

typedef struct BNX_PARTICLE
{
	BNX_INT16	x[ cGfxParticleSet ];
	BNX_INT16	y[ cGfxParticleSet ];
	BNX_INT16	dx[ cGfxParticleSet ];
	BNX_INT16	dy[ cGfxParticleSet ];
	BNX_INT16	status;

} BNX_PARTICLE;

typedef struct BNX_JUMPYTEXT
{
	BNX_INT16	x;
	BNX_INT16	y;
	BNX_INT16	index;
	BNX_INT16	downtime;
} BNX_JUMPYTEXT;

typedef struct BNX_GFX
{
	SDL_Surface		*screen;

	SDL_Surface		*logo;
	SDL_Surface		*splash;
	SDL_Surface		*roadmap;
	SDL_Surface		*help;
	SDL_Surface		*window;

	SDL_Surface		*background[ cMaxModes ];
	SDL_Surface		*elements[ cGfxMaxElements ];
	SDL_Surface		*movecount;
	SDL_Surface		*cursors[ cGfxCursors ];
	SDL_Surface		*markers[ cMaxPlayers ];
	SDL_Surface		*part[ cGfxParticleState ];

	SDL_Surface		*font;

	BNX_HELPLINE	*helptxt;
	BNX_INT16		helplin;

	BNX_JUMPYTEXT	jtext;

	BNX_PARTICLE	particle[ cGfxMaxParticles ];

} BNX_GFX;

/******************************************************************************
PUBLIC FUNCTIONS
******************************************************************************/

BNX_BOOL gfxInit();

void gfxUpdate();

void gfxRenderEntry( void );

void gfxRenderMenu( const BNX_INT16 option );

void gfxRenderHelp( BNX_INT16 *line );

void gfxRenderHof( BNX_HALL *hof );

void gfxRenderGame( BNX_GAME *game );

void gfxPrintText( BNX_INT16 x, BNX_INT16 y, const char *text );

void gfxPrintTextWave( BNX_INT16 x, BNX_INT16 y, const char *text, BNX_INT16 start );

void gfxMessageBox( BNX_INT16 x, BNX_INT16 y, const char *text );

/******************************************************************************
HELPER FUNCTIONS
******************************************************************************/

#endif
