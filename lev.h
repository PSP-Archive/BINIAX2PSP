/******************************************************************************
BINIAX 2 LEVEL DEFINITIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2006-2007
******************************************************************************/

#ifndef _BNX_LEV_H
#define _BNX_LEV_H

#include "types.h"
#include "game.h"

#define cLinesPart01	3
#define cLinesPart02	3
#define cLinesPart03	4
#define cLinesPart04	4
#define cLinesPart05	6
#define cLinesPart06	6
#define cLinesPart07	6
#define cLinesPart08	6
#define cLinesPart09	4
#define cLinesPart10	5
#define cLinesPart11	5
#define cLinesPart12	5
#define cLinesPart13	10
#define cLinesPart14	10
#define cLinesAll		cLinesPart01+cLinesPart02+cLinesPart03+cLinesPart04+cLinesPart05+\
						cLinesPart06+cLinesPart07+cLinesPart08+cLinesPart09+cLinesPart10+\
						cLinesPart11+cLinesPart12+cLinesPart13+cLinesPart14

#define cMaxLevels			14		/* All possibe levels						*/
#define cMaxLevelsTurn		6		/* First N levels suitable for tactic mode	*/
#define cMaxLevelsMulti		10		/* First N levels suitable for multiplayer	*/
#define cStartLevelsAfter	100		/* Start the levels after 100 lines scroll  */
#define cNextLevelAt		30		/* Insert level at each N lines of scroll	*/
#define cLevelInactive		-1		/* Inacive value for all meanings			*/

static BNX_INT16 BNX_LEVEL_INFO[] = {	cLinesPart01, cLinesPart02, cLinesPart03, 
										cLinesPart04, cLinesPart05, cLinesPart06,
										cLinesPart07, cLinesPart08, cLinesPart09,
										cLinesPart10, cLinesPart11, cLinesPart12,
										cLinesPart13, cLinesPart13, cLinesPart14
									};

static char		BNX_LEVEL[ cLinesAll ][ cGridX ] = 
{
	// level 1 - 3 lines
	{ 0,1,0,1,0 },
	{ 0,0,0,0,0 },
	{ 1,0,0,0,1 },

	// level 2 - 3 lines
	{ 0,1,0,0,0 },
	{ 0,0,1,0,0 },
	{ 0,0,0,1,0 },

	// level 3 - 4 lines
	{ 1,0,0,0,1 },
	{ 1,0,1,0,1 },
	{ 1,0,0,0,1 },
	{ 1,0,0,0,1 },

	// level 4 - 4 lines
	{ 0,1,0,0,0 },
	{ 0,0,0,1,0 },
	{ 0,1,0,0,0 },
	{ 0,0,0,1,0 },

	// level 5 - 6 lines
	{ 1,0,0,0,1 },
	{ 1,0,0,0,1 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,1,0,1,0 },
	{ 0,1,0,1,0 },

	// level 6 - 6 lines
	{ 1,0,0,0,0 },
	{ 0,0,0,1,1 },
	{ 0,1,0,0,0 },
	{ 0,0,0,1,1 },
	{ 1,0,0,0,0 },
	{ 0,0,0,1,1 },

	// level 7 - 6 lines
	{ 0,1,0,1,0 },
	{ 0,1,0,1,0 },
	{ 0,0,0,1,0 },
	{ 0,0,0,1,0 },
	{ 0,1,0,0,0 },
	{ 0,1,0,0,0 },

	// level 8 - 6 lines
	{ 1,0,1,0,1 },
	{ 1,0,0,0,1 },
	{ 0,0,0,0,0 },
	{ 0,1,0,1,0 },
	{ 0,0,0,0,0 },
	{ 1,0,1,0,1 },

	// level 9 - 4 lines
	{ 0,0,1,0,0 },
	{ 0,1,0,1,0 },
	{ 0,1,0,1,0 },
	{ 0,0,1,0,0 },

	// level 10 - 5 lines
	{ 0,0,0,0,0 },
	{ 0,0,1,0,0 },
	{ 0,1,1,1,0 },
	{ 0,0,1,0,0 },
	{ 0,0,0,0,0 },

	// level 11 - 5 lines
	{ 0,1,0,1,0 },
	{ 0,0,1,0,0 },
	{ 0,0,0,1,0 },
	{ 0,0,1,0,0 },
	{ 0,1,0,0,0 },

	// level 12 - 5 lines
	{ 0,1,0,1,0 },
	{ 0,0,0,0,0 },
	{ 1,1,0,1,1 },
	{ 0,0,0,0,0 },
	{ 0,0,1,0,0 },

	// level 13 - 10 lines
	{ 1,0,0,0,1 },
	{ 0,1,0,1,0 },
	{ 0,1,0,1,0 },
	{ 0,0,0,0,0 },
	{ 0,0,1,0,0 },
	{ 0,0,1,0,0 },
	{ 0,0,0,0,0 },
	{ 0,1,0,1,0 },
	{ 0,1,0,1,0 },
	{ 1,0,0,0,1 },

	// level 14 - 10 lines
	{ 0,0,1,0,0 },
	{ 1,1,1,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,1,1,0 },
	{ 0,0,1,0,0 },
	{ 0,0,1,0,0 },
	{ 1,0,1,0,0 },
	{ 1,0,0,0,0 },
	{ 1,1,0,1,1 },
	{ 1,1,0,1,1 },

};

#endif