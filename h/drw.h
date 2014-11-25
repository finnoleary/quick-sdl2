#define DRW

void drw_cls(var_screen *s, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(s->r, r, g, b, a);	
	SDL_RenderClear(s->r);
}

void drw_blit(var_screen *s)
{
	/* SDL_UpdateTexture(s->t, NULL, (s->s)->pixels, (s->s)->pitch);
	SDL_RenderCopy(s->r, s->t, NULL, NULL); */
	SDL_RenderPresent(s->r);
}

void drw_col(var_screen *s, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(s->r, r, g, b, a);
}

void drw_pix(var_screen *s, int x, int y)
{
	SDL_RenderDrawPoint(s->r, x, y);
}

void drw_line(var_screen *s, int x0, int y0, int x1, int y1)
{
	SDL_RenderDrawLine(s->r, x0, y0, x1, y1);
}

void drw_rect(var_screen *s, int x, int y, int h, int w)
{
	SDL_Rect *r = &var_rect;
	r->x = x; r->y = y; r->h = h; r->w = w;
	SDL_RenderDrawRect(s->r, r);
}

void drw_rectf(var_screen *s, int x, int y, int h, int w)
{
	SDL_Rect *r = &var_rect;
	r->x = x; r->y = y; r->h = h; r->w = w;
	SDL_RenderFillRect(s->r, r);
}
