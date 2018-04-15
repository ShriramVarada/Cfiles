/*
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000  maximum input line length
int getline(char line[], int maxline);
void copy(char to[], char from[]);
int main(void){

	int len;  current line length
	int max;  maximum length seen so far
	char line[MAXLINE];  current input line
	char longest[MAXLINE];  longest line saved here
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)  there was a line
	printf("%s", longest);
	return 0;

return EXIT_SUCCESS;
}
int getline(char s[],int lim)
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
 copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

*/
