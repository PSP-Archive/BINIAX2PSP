/******************************************************************************
BINIAX NETWORK-RELATED DEFINITIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2006.
******************************************************************************/

#ifndef _BNX_NET_H
#define _BNX_NET_H

/******************************************************************************
INCLUDES
******************************************************************************/

#include <SDL_net.h>

#include "inc.h"

/******************************************************************************
LOCAL NETWORK DATA (SOCKETS, IP's, ETC.)
******************************************************************************/

#define cNetPortServer	8291
#define cNetPortClient	8192
#define cNetTimeout	(5*1000)
#define cNetFlagByte (BNX_UINT8) (69)

typedef struct BNX_NET 
{

	TCPsocket		tcpServerRead;
	TCPsocket		tcpClientRead;

} BNX_NET;

/******************************************************************************
FUNCTIONS
******************************************************************************/

BNX_BOOL netInit();
void netClose();

BNX_BOOL netSendGame( BNX_GAME *game );
BNX_BOOL netSendKeys( BNX_INP *keys );

BNX_BOOL netReceiveGame( BNX_GAME *game );
BNX_BOOL netReceiveKeys( BNX_INP *keys );

BNX_BOOL netListen();
BNX_BOOL netConnect( char* host );

#endif
