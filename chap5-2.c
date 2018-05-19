#include <stdio.h>
#include <stdlib.h>
#include "chap5-1.h"
#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
#define MAXLEN 1000 /* max length of any input line */
int getline1(char *, int);
char *allocPos(int);
void strcpy1(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

int strcmp(char *s, char *t)
{
	int i;
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}


/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline1(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = allocPos(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline*/
			strcpy1(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
/* writelines: write output lines *//*
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}*/

int getline1(char s[],int lim)
{
	int c, i;
//	Similarly, it would be unfortunate if c were tested against EOF before getchar is called;
//	therefore the call and assignment must occur before the character in c is tested.
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

char *month_name(int n)
{
	static char *name[] = {
	"Illegal month",
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
	};
	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(void){
	char* message = "hello\n";
	char d='a';
	char *c=&d;
	int i=0;
	while(*(message+i) != '\0'){
		printf("%c", *(message+i));
		*c = *(message+i);       /*QUESTION.. WHY NOT *c = *(message + i)*/
		printf("%c\n", *c);
		//*c++=*message++;
		i++;
	}
/*
	int nlines;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}*/
}
