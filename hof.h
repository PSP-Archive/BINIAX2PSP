/******************************************************************************
BINIAX HALL OF FAME DEFINITIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

#ifndef _BNX_HOF_H
#define _BNX_HOF_H

/******************************************************************************
INCLUDES
******************************************************************************/

#include "inc.h"

#define cHofEntries		7
#define cHofNameLen		30
#define cHofInitScore	1000

/******************************************************************************
HALL OF FAME DATATYPES
******************************************************************************/
typedef struct BNX_HALL_ENTRY
{
	char		name[ cHofNameLen ];
	BNX_INT32	score;
} BNX_HALL_ENTRY;

typedef struct BNX_HALL
{
	BNX_HALL_ENTRY	arcade[ cHofEntries ];
	BNX_HALL_ENTRY	tactic[ cHofEntries ];
} BNX_HALL;

/******************************************************************************
FUNCTIONS
******************************************************************************/

BNX_BOOL hofInit();

BNX_BOOL hofSave();

void hofView();

BNX_BOOL hofEnter( BNX_GAME *game );

BNX_HALL *hofGet();

#endif
