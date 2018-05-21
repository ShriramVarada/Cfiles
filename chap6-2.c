#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "chap6-1.h"
struct key keytab[] = {
		{"auto", 0},
		{"break", 0},
		{"case", 0},
		{"char", 0},
		{"const", 0},
		{"continue", 0},
		{"default", 0},
	/* ... */
		{"unsigned", 0},
		{"void", 0},
		{"volatile", 0},
		{"while", 0}
};


struct key *binsearch2(char *word, struct key *tab, int n)
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;
	while (low < high) {
		mid = low + (high-low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
	else
		return mid;
	}
	return NULL;
}



//int main(void){
//
//	int n;
//	int NKEYS = sizeof(keytab)/sizeof(keytab[0]);
//	char word[MAXWORD];
//	while (getword(word, MAXWORD) != EOF){
//		if (isalpha(word[0]))
//			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
//				keytab[n].count++;
//	for (n = 0; n < NKEYS; n++)
//		if (keytab[n].count > 0)
//			printf("%4d %s\n", keytab[n].count, keytab[n].word);
//	return 0;
//	}
//}

