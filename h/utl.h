#define UTL

#ifndef fprintf
#include <stdio.h>
#endif
#ifndef exit
#include <stdlib.h>
#endif

#ifndef NDEBUG
void utl_dbmsg(char *s) 
{
	printf("DEBUG: %s\n", s);
}
#else
	#define utl_dbmsg(ignore)((void) 0) /* It's so beautiful so why change it */
#endif

int utl_fail(char *s)
{
	#define ___FAIL "Program failed!\n"
	#define ___REAS "Reason: "
	#define ___FNDEF "Not handling free()-s as UTL_FREE is not defined.\n"
	#define ___FDEF "Free()-ing everything.\n"
	#define ___EXIT "Exiting... Goodbye!\n"
	
	fprintf(stderr, ___FAIL);
	fprintf(stderr, "%s%s.\n", ___REAS, s);
	
	#ifdef UTL_FREE
		fprintf(stderr, ___FDEF);
		UTL_FREE(); /* Yes I did just do this. Look on in horror >:D */
	#else
		fprintf(stderr, ___FNDEF);
	#endif

	fprintf(stderr, ___EXIT);

	#undef ___FAIL
	#undef ___REAS
	#undef ___FNDEF
	#undef ___FDEF
	#undef ___EXIT
	SDL_Quit();
	exit(1);
}

