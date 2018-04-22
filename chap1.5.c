/*
#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
int main(void){
//	/*int c;
//	while ((c = getchar()) != EOF)
//		putchar(c);
//	long nc;
//	nc = 0;
//	while (getchar() != EOF)
//		++nc;
//	printf("%ld\n", nc);
//
//	int c, numberOfLines;
//	numberOfLines = 0;
//	while ((c = getchar()) != EOF)
//		if (c == '\n')
//			++numberOfLines;
//	printf("%d\n", numberOfLines);

	int c, numberOfLines, numberOfWords, numberOfCharacters, c1='\n', state;
	numberOfLines = numberOfWords = numberOfCharacters = 0;
	while ((c = getchar()) != EOF) {
		++numberOfCharacters;
		//printf("%c", c);
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
	}if(numberOfLines > 0) numberOfWords++;
	if(c1 != '\n'){
		numberOfLines++;
	}
	printf("%d %d %d\n", numberOfLines, numberOfWords, numberOfCharacters);
	return EXIT_SUCCESS;
}
*/
