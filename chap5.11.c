#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chap5-1.h"
#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
int getline1(char s[],int lim);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[1000];
	nlines = 0;
	while ((len = getline1(line, 1000)) > 0)
		if (nlines >= maxlines || (p = allocPos(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline*/
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
};
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
void qsort1(void *v[], int left, int right,
int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right) /* do nothing if array contains */
		return; /* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort1(v, left, last-1, comp);
	qsort1(v, last+1, right, comp);
}

void swap(void ** v, int a, int b){
	void * temp;
	temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

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

int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int main(int argc, char* argv[]){/*
	int nlines;
	int numeric = 0;
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort1((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}*/

}
