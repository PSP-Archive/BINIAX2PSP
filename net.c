/******************************************************************************
BINIAX NETWORK-RELATED IMPLEMENTATIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

/******************************************************************************
INCLUDES
******************************************************************************/

#include "inc.h"

/******************************************************************************
GLOBALS
******************************************************************************/

BNX_NET _Net;

/******************************************************************************
FUNCTIONS
******************************************************************************/

BNX_BOOL netInit()
{
	if ( SDLNet_Init() != 0 )
	{
		return BNX_FALSE;
	}

	_Net.tcpClientRead = 0;
	_Net.tcpServerRead = 0;

	return BNX_TRUE;
}

void netClose()
{
	SDLNet_TCP_Close( _Net.tcpClientRead );
	SDLNet_TCP_Close( _Net.tcpServerRead );
	SDLNet_Quit();
}

BNX_BOOL netSendGame( BNX_GAME *game )
{
	BNX_INT32	dataSize;

	dataSize = SDLNet_TCP_Send( _Net.tcpClientRead , (void *)game, sizeof( BNX_GAME ) );

	if ( dataSize != sizeof( BNX_GAME ) )
	{
		BNX_FALSE;
	}

	return BNX_TRUE;
}

BNX_BOOL netSendKeys( BNX_INP *keys )
{
	BNX_INT32	dataSize;

	dataSize = SDLNet_TCP_Send( _Net.tcpServerRead, (void *)keys, sizeof( BNX_INP ) );

	if ( dataSize != sizeof( BNX_INP ) )
	{
		BNX_FALSE;
	}

	return BNX_TRUE;
}

BNX_BOOL netReceiveGame( BNX_GAME *game )
{
	BNX_INT32	dataSize;

	dataSize = SDLNet_TCP_Recv( _Net.tcpClientRead, (void *)game, sizeof ( BNX_GAME ) );
	if ( dataSize != sizeof( BNX_GAME ) )
	{
		return BNX_FALSE;
	}

	return BNX_TRUE;
}

BNX_BOOL netReceiveKeys( BNX_INP *keys )
{
	BNX_INP		tmpKeys;
	BNX_INT32	dataSize;

	dataSize = SDLNet_TCP_Recv( _Net.tcpServerRead, &tmpKeys, sizeof ( BNX_INP ) );
	if ( dataSize != sizeof( BNX_INP ) )
	{
		return BNX_FALSE;
	}
	else
	{
		keys->keyAltDown	= tmpKeys.keyAltDown;
		keys->keyAltUp		= tmpKeys.keyAltUp;
		keys->keyAltLeft	= tmpKeys.keyAltLeft;
		keys->keyAltRight	= tmpKeys.keyAltRight;
		keys->moment		= tmpKeys.moment;
	}

	return BNX_TRUE;
}

BNX_BOOL netListen()
{
	IPaddress	ip;
	IPaddress	ip2;
	TCPsocket	servSocket;
	TCPsocket	servSocket2;
	BNX_INT32	startTime;
	BNX_UINT8	flag = cNetFlagByte;
	BNX_INT32	dataSize;

	// OPEN THE KEYBOARD TRANSFER SOCKET
	if ( SDLNet_ResolveHost( &ip, NULL, cNetPortServer ) != 0 )
	{
		return BNX_FALSE;
	}

	servSocket = SDLNet_TCP_Open( &ip );
	if ( servSocket == 0 )
	{
		return BNX_FALSE;
	}

	inpInit();
	do
	{
		inpUpdate();
		_Net.tcpServerRead = SDLNet_TCP_Accept( servSocket );

	} while ( inpKeyB() == BNX_FALSE && _Net.tcpServerRead == 0 );

	if ( _Net.tcpServerRead == 0 )
	{
		return BNX_FALSE;
	}

	dataSize = SDLNet_TCP_Send( _Net.tcpServerRead, &flag, sizeof( BNX_UINT8 ) );
	if ( dataSize != sizeof( BNX_UINT8 ) )
	{
		return BNX_FALSE;
	}


	// OPEN THE GAME TRANSFER SOCKET
	if ( SDLNet_ResolveHost( &ip2, NULL, cNetPortClient ) != 0 )
	{
		return BNX_FALSE;
	}

	servSocket2 = SDLNet_TCP_Open( &ip2 );
	if ( servSocket2 == 0 )
	{
		return BNX_FALSE;
	}

	startTime = sysGetTime();
	do
	{
		inpUpdate();
		_Net.tcpClientRead = SDLNet_TCP_Accept( servSocket2 );

	} while ( ((sysGetTime() - startTime) < cNetTimeout) && _Net.tcpClientRead == 0 );

	if ( _Net.tcpClientRead == 0 )
	{
		return BNX_FALSE;
	}

	return BNX_TRUE;
}

BNX_BOOL netConnect( char* host )
{
	IPaddress	ip;
	IPaddress	ip2;
	BNX_UINT8	flag = cNetFlagByte;
	BNX_INT32	dataSize;

	if ( SDLNet_ResolveHost( &ip, host, cNetPortServer ) != 0 )
	{
		return BNX_FALSE;
	}

	_Net.tcpServerRead = SDLNet_TCP_Open( &ip );
	if ( _Net.tcpServerRead == 0 )
	{
		return BNX_FALSE;
	}

	dataSize = SDLNet_TCP_Recv( _Net.tcpServerRead, &flag, sizeof( BNX_UINT8 ) );
	if ( dataSize != sizeof( BNX_UINT8 ) || flag != cNetFlagByte )
	{
		return BNX_FALSE;
	}

	if ( SDLNet_ResolveHost( &ip2, host, cNetPortClient ) != 0 )
	{
		return BNX_FALSE;
	}

	_Net.tcpClientRead = SDLNet_TCP_Open( &ip2 );
	if ( _Net.tcpClientRead == 0 )
	{
		return BNX_FALSE;
	}

	return BNX_TRUE;
}
