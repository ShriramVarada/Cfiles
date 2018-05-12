#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXVAL 100
#define NUMBER '0'
int strindex(char *, char *);
int getline1(char*, int);
double atof1(char *);
int atoi1(char*);
int getop(char*);
int getch();

int main(void){
	double sum;
	char line[1000];
	sum = 0;
	while (getline1(line, 1000) > 0)
		printf("\t%g\n", sum += atof1(line));
return EXIT_SUCCESS;
}

int getline1(char line[], int lim){
	int c, i=0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		line[i++]=c;
	line[i]='\0';
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

double atof1(char s[]){
	int sign, i=0;
	double val,power;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;

}

int atoi1(char s[])
{
	return (int) atof1(s);
}

int getop(char s[]){
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
	ungetch(c);
	return NUMBER;
}
