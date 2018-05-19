#include <stdio.h>
#include <stdlib.h>

#include "chap5-1.h"
static char* allocp = charBuffer;
char * allocPos(int n){
	if(charBuffer + MAXSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}else
		return 0;
}

void free1(char * p){
	if(allocp > charBuffer && p < charBuffer + MAXSIZE && p >= charBuffer)
		allocp = p;
}
