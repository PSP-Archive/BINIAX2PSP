/******************************************************************************
BINIAX INPUT-RELATED IMPLEMENTATIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2007
******************************************************************************/

/******************************************************************************
INCLUDES
******************************************************************************/

#include <stdlib.h>

#include "inc.h"

/******************************************************************************
FUNCTIONS
******************************************************************************/

SDL_Joystick *joy;

BNX_BOOL inpInit()
{
	_Inp.keyUp		= BNX_FALSE;
	_Inp.keyDown	= BNX_FALSE;
	_Inp.keyLeft	= BNX_FALSE;
	_Inp.keyRight	= BNX_FALSE;
	_Inp.keyAltUp	= BNX_FALSE;
	_Inp.keyAltDown	= BNX_FALSE;
	_Inp.keyAltLeft	= BNX_FALSE;
	_Inp.keyAltRight= BNX_FALSE;
	_Inp.keyPageUp	= BNX_FALSE;
	_Inp.keyPageDown= BNX_FALSE;
	_Inp.keyA		= BNX_FALSE;
	_Inp.keyB		= BNX_FALSE;
	_Inp.keyQuit	= BNX_FALSE;
	_Inp.keyDel		= BNX_FALSE;
	_Inp.letter		= 0;

	if(SDL_NumJoysticks()>0) {
                joy=SDL_JoystickOpen(0);
                if(!joy) {
                       fprintf(stdout,"could not open joystick #0\n");
                 }
         }

	return BNX_TRUE;
}

void inpUpdate()
{
    SDL_Event event;

    while( SDL_PollEvent( &event ) ) 
	{

        switch( event.type ) 
		{

			case SDL_JOYBUTTONDOWN:
				if(event.jbutton.button==8)
					_Inp.keyUp              = BNX_TRUE;
				else if(event.jbutton.button==6)
					_Inp.keyDown              = BNX_TRUE;
				else if(event.jbutton.button==7)
					_Inp.keyLeft              = BNX_TRUE;
				else if(event.jbutton.button==9)
					_Inp.keyRight              = BNX_TRUE;
				else if(event.jbutton.button==1) {
					_Inp.keyA		= BNX_TRUE;
					_Inp.keyAltRight		= BNX_TRUE;
				}
				else if(event.jbutton.button==0) {
					_Inp.keyC		= BNX_TRUE;
					_Inp.keyAltUp		= BNX_TRUE;
				}
				else if(event.jbutton.button==2) {
					_Inp.keyA		= BNX_TRUE;
					_Inp.keyAltDown		= BNX_TRUE;
				}
				else if(event.jbutton.button==3) {
					_Inp.keyC		= BNX_TRUE;
					_Inp.keyAltLeft		= BNX_TRUE;
				}
				else if(event.jbutton.button==11 || event.jbutton.button==10)
					_Inp.keyB	= BNX_TRUE;
				break;
			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ) 
				{
					case SDLK_SPACE : 
						_Inp.keyC		= BNX_TRUE;
						break;
					case SDLK_RETURN : 
						_Inp.keyA		= BNX_TRUE;
						break;
					case SDLK_ESCAPE : 
						_Inp.keyB		= BNX_TRUE;
						break;
					case SDLK_KP8:
					case SDLK_UP : 
						_Inp.keyUp		= BNX_TRUE;
						break;
					case SDLK_KP2:
					case SDLK_DOWN : 
						_Inp.keyDown	= BNX_TRUE;
						break;
					case SDLK_KP4:
					case SDLK_LEFT : 
						_Inp.keyLeft	= BNX_TRUE;
						break;
					case SDLK_KP6:
					case SDLK_RIGHT : 
						_Inp.keyRight	= BNX_TRUE;
						break;

					case SDLK_w : 
						_Inp.keyAltUp	= BNX_TRUE;
						break;
					case SDLK_s : 
						_Inp.keyAltDown	= BNX_TRUE;
						break;
					case SDLK_a : 
						_Inp.keyAltLeft	= BNX_TRUE;
						break;
					case SDLK_d : 
						_Inp.keyAltRight= BNX_TRUE;
						break;

					case SDLK_BACKSPACE :
					case SDLK_DELETE :
						_Inp.keyDel = BNX_TRUE;
						break;
					case SDLK_PAGEUP : 
						_Inp.keyPageUp	= BNX_TRUE;
						break;
					case SDLK_PAGEDOWN : 
						_Inp.keyPageDown= BNX_TRUE;
						break;
				}
				if ( event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z )
				{
					_Inp.letter = (event.key.keysym.sym - SDLK_a) + 'A';
				}
			break;

			case SDL_QUIT:
				SDL_Quit();
				exit( 2 );
			break;

		}
	}
}

BNX_BOOL inpKeyLeft()
{
	if ( _Inp.keyLeft == BNX_TRUE )
	{
		_Inp.keyLeft = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyRight()
{
	if ( _Inp.keyRight == BNX_TRUE )
	{
		_Inp.keyRight = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyUp()
{
	if ( _Inp.keyUp == BNX_TRUE )
	{
		_Inp.keyUp = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyDown()
{
	if ( _Inp.keyDown == BNX_TRUE )
	{
		_Inp.keyDown = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyAltLeft()
{
	if ( _Inp.keyAltLeft == BNX_TRUE )
	{
		_Inp.keyAltLeft = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyAltRight()
{
	if ( _Inp.keyAltRight == BNX_TRUE )
	{
		_Inp.keyAltRight = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyAltUp()
{
	if ( _Inp.keyAltUp == BNX_TRUE )
	{
		_Inp.keyAltUp = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyAltDown()
{
	if ( _Inp.keyAltDown == BNX_TRUE )
	{
		_Inp.keyAltDown = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyA()
{
	if ( _Inp.keyA == BNX_TRUE )
	{
		_Inp.keyA = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyB()
{
	if ( _Inp.keyB == BNX_TRUE )
	{
		_Inp.keyB = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyC()
{
	if ( _Inp.keyC == BNX_TRUE )
	{
		_Inp.keyC = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyPageUp()
{
	if ( _Inp.keyPageUp == BNX_TRUE )
	{
		_Inp.keyPageUp = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyPageDown()
{
	if ( _Inp.keyPageDown == BNX_TRUE )
	{
		_Inp.keyPageDown = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpKeyDel()
{
	if ( _Inp.keyDel == BNX_TRUE )
	{
		_Inp.keyDel = BNX_FALSE;
		return BNX_TRUE;
	}

	return BNX_FALSE;
}

BNX_BOOL inpExit()
{
	return _Inp.keyQuit;
}

char inpGetChar()
{
	char ch = 0;
	if ( _Inp.letter > 0 )
	{
		ch = _Inp.letter;
		_Inp.letter = 0;
	}

	return ch;
}

BNX_INP *inpDirect()
{
	return &_Inp;
}
