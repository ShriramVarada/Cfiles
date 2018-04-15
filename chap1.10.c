#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */
int getline(void);
void copy(void);
/* print longest input line; specialized version */
main()
{
	int len;
	extern int max;
	extern char longest[]; // redundant extern declaration
	max = 0;
	while ((len = getline()) > 0)
	if (len > max) {
		max = len;
		copy();
	}
	if (max > 0) /* there was a line */
		printf("%s", longest);
	return 0;
}

/* getline: specialized version */
int getline(void)
{
	int c, i;
	extern char line[];
	for (i = 0; i < (MAXLINE - 1) && (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
/* copy: specialized version */
void copy(void)
{
	int i;
	extern char line[], longest[];
	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}

/*
In certain circumstances, the extern declaration can be omitted. If the definition of the external variable occurs in the source file before its use in a particular function, then there is no need for an extern declaration in the function. The extern declarations in main, getline and copy are thus redundant. In fact, common practice is to place definitions of all external variables at the beginning of the source file, and then omit all extern declarations.
If the program is in several source files, and a variable is defined in file1 and used in file2 and file3, then extern declarations are needed in file2 and file3 to connect the occurrences of the variable. The usual practice is to collect extern declarations of variables and functions in a separate file, historically called a header, that is included by #include at the front of each source file. The suffix .h is conventional for header names. The functions of the standard library, for example, are declared in headers like <stdio.h>.
*/
