#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

/* Yeah, I'm using Pike Style includes :P */
#ifndef VAR
#include "h/var.h"
#endif
#ifndef UTL
#include "h/utl.h"
#endif
#ifndef WIN
#include "h/win.h"
#endif
#ifndef DRW
#include "h/drw.h"
#endif

/*
 * So far:
 * var_		- variable
 * utl_		- utility
 * win_		- window
 * drw_		- draw
 * upd_		- update
 */


var_screen screen;
var_input input;


int main()
{
	screen.width = 640;
	screen.height = 480;

	win_newwin(&screen);
	while (1)
	{
		drw_cls(&screen, 0, 0, 0, 255);

		drw_col(&screen, 255, 0, 0, 255);
		drw_rectf(&screen, 20, 20, 13, 13);
		drw_col(&screen, 0, 255, 0, 255);
		drw_line(&screen, 50, 50, 400, 400);
		drw_col(&screen, 0, 0, 255, 255);
		drw_pix(&screen, 460, 64);

		drw_blit(&screen);
		if (SDL_PollEvent(&(input.e))) {
			if (input.e.type == SDL_QUIT)
				break;
			else if (input.e.type == SDL_KEYDOWN) {
				if (input._KEYSCAN == SDL_SCANCODE_D)
					utl_dbmsg("D key is down");
			}
		}
	}
	utl_fail("Closing");
}
