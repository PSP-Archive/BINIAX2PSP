#ifndef _BNX_TXT_H
#define _BNX_TXT_H

#include "game.h"

char *TXT_HofCase[] = {
	"BEST ARCADE SCORES",
	"BEST TACTIC SCORES"
};

char *TXT_MenuMain[ cMaxOptions ] = {
		"CONTINUE LAST GAME",
		"NEW ARCADE GAME",
		"NEW TACTIC GAME",
		"MULTIPLAYER",
		"HALL OF FAME",
		"HELP",
		"EXIT"
};

char *TXT_MenuMulti[ cMaxOptions ] = {
		"SAME MACHINE MULTIPLAYER",
		"START NETWORK GAME",
		"JOIN NETWORK GAME",
		"BACK"
};

char *TXT_Extras[ cMaxExtras ] = {
		"MINOR COMBO +5",
		"COMBO +10",
		"BIG COMBO +20",
		"MEGA COMBO +40",
		"FIELD MASTERED +100",
		"NEW BROOM",
};

#endif