#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
static double stack[MAXVAL];
static int sp=0;

void push(double f){
	if(sp < MAXVAL)
		stack[sp++]=f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return stack[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
