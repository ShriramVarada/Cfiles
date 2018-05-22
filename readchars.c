#include <stdio.h>
#include <stdlib.h>
#include "file.h"

char* fgetc2(char* s, int n, FILE* in){
	register char* cs;
	register int c;
	cs=s;

	while(--n > 0 && (c = getc(in)) != EOF)
		if((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (cs == s) ? NULL : cs;
}

int fputs2(char* s, FILE* out){
	int c;
	while(c = *s++)
		putc(c, out);

	return (s == NULL || ferror(out)) ? EOF : 0;
}
