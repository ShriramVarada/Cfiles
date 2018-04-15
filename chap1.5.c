//#include <stdio.h>
//#include <stdlib.h>
//#define IN 1 /* inside a word */
//#define OUT 0 /* outside a word */
//int main(void){/*
//	int c;
//	while ((c = getchar()) != EOF)
//		putchar(c);
//	long nc;
//	nc = 0;
//	while (getchar() != EOF)
//		++nc;
//	printf("%ld\n", nc);
//
//	int c, nl;
//	nl = 0;
//	while ((c = getchar()) != EOF)
//		if (c == '\n')
//			++nl;
//	printf("%d\n", nl);*/
//
//	int c, nl, nw, nc, c1=0, state;
//	nl = nw = nc = 0;
//	while ((c = getchar()) != EOF) {
//		++nc;
//		if (c == '\n'){
//			++nl;
//		}
//		if (c == ' ' || c == '\n' || c == '\t'){
//			state = OUT;
//		}else if(state == OUT){
//			state = IN;
//			++nw;
//		}
//		c1 = c;
//	}nw++;
//	if(c1 != '\n'){
//		nl++;
//	}
//	printf("%d %d %d\n", nl, nw, nc);
//
//	return EXIT_SUCCESS;
//}
