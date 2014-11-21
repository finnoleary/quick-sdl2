#define VAR
typedef struct {
	char name[32];
	bool full_p;
	int width, height;
	SDL_Window *w;
	SDL_Renderer *r;
	SDL_Surface *s;
	SDL_Texture *t;
} var_screen;

typedef struct {
	SDL_Event e;	
} var_input;

#define _KEYSCAN e.key.keysym.scancode
#define _KEYCODE e.key.keysym.sym
#define _KEYMOD	 e.key.keysym.mod

/* <include keys.h here> */
