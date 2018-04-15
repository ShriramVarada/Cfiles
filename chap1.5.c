#include <stdio.h>
#include <stdlib.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
int main(void){/*
	int c;
	while ((c = getchar()) != EOF)
		putchar(c);
	long nc;
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);

	int c, numberOfLines;C:\Users\Shriram\OneDrive - University of Iowa\practice
	numberOfLines = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++numberOfLines;
	printf("%d\n", numberOfLines);*/

	int c, numberOfLines, numberOfWords, numberOfCharacters, c1=0, state;
	numberOfLines = numberOfWords = numberOfCharacters = 0;
	while ((c = getchar()) != EOF) {
		++numberOfCharacters;
		if (c == '\n'){
			++numberOfLines;
		}
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}else if(state == OUT){
			state = IN;
			++numberOfWords;
		}
		c1 = c;
	}numberOfWords++;
	if(c1 != '\n'){
		numberOfLines++;
	}
	printf("%d %d %d\n", numberOfLines, numberOfWords, numberOfCharacters);

	return EXIT_SUCCESS;
}
