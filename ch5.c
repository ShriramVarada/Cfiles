#include <stdio.h>
#include <stdlib.h>
int getch(void);
void ungetch(int);
int isdigit(int);
int isspace(int);
/* getint: get next integer from input into *pn */
int getint1(int *pn)
{
	int c, sign;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
void swap(int *px, int *py) /* interchange *px and *py */
{
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}


int main(void){
	int a=1, b=2;
	printf("a = %d, b = %d\n",a,b);
	swap(&a,&b);
	printf("a = %d, b = %d",a,b);
	getint1(&b);
return EXIT_SUCCESS;
}
