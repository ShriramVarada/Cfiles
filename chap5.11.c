//#include <stdio.h>
//#include <stdlib.h>
//#define MAXLINES 5000 /* max #lines to be sorted */
//char *lineptr[MAXLINES]; /* pointers to text lines */
//int readlines(char *lineptr[], int maxlines)
//{
//	int len, nlines;
//	char *p, line[1000];
//	nlines = 0;
//	while ((len = getline1(line, 1000)) > 0)
//		if (nlines >= maxlines || (p = allocPos(len)) == NULL)
//			return -1;
//		else {
//			line[len-1] = '\0'; /* delete newline*/
//			strcpy1(p, line);
//			lineptr[nlines++] = p;
//		}
//	return nlines;
//};
//void writelines(char *lineptr[], int nlines)
//{
//	int i;
//	for (i = 0; i < nlines; i++)
//		printf("%s\n", lineptr[i]);
//}
//void qsort1(void *v[], int left, int right,
//int (*comp)(void *, void *))
//{
//	int i, last;
//	void swap(void *v[], int, int);
//	if (left >= right) /* do nothing if array contains */
//		return; /* fewer than two elements */
//	swap(v, left, (left + right)/2);
//	last = left;
//	for (i = left+1; i <= right; i++)
//		if ((*comp)(v[i], v[left]) < 0)
//			swap(v, ++last, i);
//	swap(v, left, last);
//	qsort1(v, left, last-1, comp);
//	qsort1(v, last+1, right, comp);
//}
//int numcmp(char *, char *);
//int main(int argc, char* argv[]){
//	int nlines; /* number of input lines read */
//	int numeric = 0; /* 1 if numeric sort */
//	if (argc > 1 && strcmp(argv[1], "-n") == 0)
//		numeric = 1;
//	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
//		qsort1((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
//		writelines(lineptr, nlines);
//		return 0;
//	} else {
//		printf("input too big to sort\n");
//		return 1;
//	}
//return EXIT_SUCCESS;
//}
