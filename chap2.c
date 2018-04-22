
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define VTAB '\013'
#define BELL '\x7'
#define MAXLINE 1000

int strlen1(const char *);
enum yesNo { NO=1, YES=0};
int lower2(int);
int atoi1(char *);
void squeeze(char *, int);
void strcat1(char *, char *);

int main(void){

	//In the test part of if, while, for, etc., ``true'' just means ``non-zero'', so this makes no difference.

	printf("%o\n", BELL);
	printf("%x\n", VTAB);
	printf("%o\n", MAXLINE);
	printf("%d\n", strlen1("Narayana"));
	printf("%d\n", YES);
	printf("%d\n", atoi1("234"));
	printf("%c\n", lower2('H'));
	char s[]="Sachin";
	squeeze(s, 97);
	printf("%s", s);
	return EXIT_SUCCESS;
}
int strlen1(const char s[])
{
	int i=0;
	while (s[i] != '\0')
		++i;
	return i;
}
int atoi1(char s[])
{
	int i, n=0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
int lower2(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
void strcat1(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')  //find end of s
		i++;
	while ((s[i++] = t[j++]) != '\0')  //copy t
		;
}

