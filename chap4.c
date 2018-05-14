#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.h"
#undef strindex
int strindex(char *, char *);
int getline1(char*, int);
double atof1(char *);
int atoi1(char*);
int getop(char*);

#define dprint(expr) printf(#expr " = %g\n", expr) /* printf("x/y" " = &g\n", x/y);*/
#define paste(front, back) front ## back

int main(void){
	/*double sum;
	char line[1000];
	sum = 0;
	while (getline1(line, 1000) > 0)
		printf("\t%g\n", sum += atof1(line));*/

	char squota = '\'';
	long day = 1000L * 60L * 60L * 24L;
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char pattern[] = "ould";


	int type;
	double op2;
	char s[100];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
			break;
			case '+':
				push(pop() + pop());
			break;
			case '*':
				push(pop() * pop());
			break;
			case '-':
			op2 = pop();
				push(pop() - op2);
			break;
			case '/':
				op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
			case '\n':
				printf("\t%.8g\n", pop());
			break;
			default:
				printf("error: unknown command %s\n", s);
			break;
		}
	}


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


