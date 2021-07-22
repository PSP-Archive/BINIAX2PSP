/******************************************************************************
BINIAX ALL INCLUDES
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

#ifndef _BNX_INC_H
#define _BNX_INC_H

/******************************************************************************
INCLUDES
******************************************************************************/

#include "game.h"
#include "hof.h"

#define __WIN32

/* Desktop / SDL includes */
#ifdef __WIN32
#include "types.h"
#include "inp.h"
#include "gfx.h"
#include "snd.h"
#include "sys.h"
#include "cfg.h"
//#include "net.h"

//#include <SDL.h>

#endif

/* WinCE / EasyCE includes */
#ifdef __WINCE
#include "wince/types.h"
#include "wince/inp.h"
#include "wince/gfx.h"
#include "wince/snd.h"
#include "wince/sys.h"
#endif

/* Symbain / Series60 includes */
#ifdef __SERIES60
#include "symbian/types.h"
#include "symbian/inp.h"
#include "symbian/gfx.h"
#include "symbian/snd.h"
#include "symbian/sys.h"
#endif


#endif
