#define WIN
int win_newwin(var_screen *screen)
{
	if (SDL_CreateWindowAndRenderer(screen->width, screen->height, 
									SDL_WINDOW_OPENGL, 
									&(screen->w), &(screen->r)))
		utl_fail("lod_newwin: Failed to create window and renderer");

	screen->s = SDL_CreateRGBSurface(0, screen->width, screen->height, 32,
									0x00FF0000,
									0x0000FF00,
									0x000000FF,
									0xFF000000);
	if (!screen->s)
		utl_fail("lod_newwin: Failed to create RGBSurface");

	screen->t = SDL_CreateTexture(screen->r,
								 SDL_PIXELFORMAT_ARGB8888,
								 SDL_TEXTUREACCESS_STREAMING,
								 screen->width, screen->height);
	if (!screen->t)
		utl_fail("lod_newwin: Failed to create Texture");

	SDL_SetRenderDrawColor(screen->r, 0, 0, 0, 255);
	SDL_SetTextureAlphaMod(screen->t, 155);

	return 1;
}

