#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#define getchar() getc(stdin)
#define putchar() putc(c, stdout)
int main(int argc, char **argv){
	FILE *fp;

	if(argc==1){
		filecopy(stdin, stdout);
		fclose(stdin);
		fclose(stdout);
	}
	else{
		while(--argc > 0){
			if((fp = fopen(*++argv, "r")) == NULL){
				printf("Cannot open file %s", *argv);
				return 1;
			}else{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
}

void filecopy(FILE * in, FILE * out){
	int c;
	while((c = getc(in)) != EOF)
		putc(c, out);
}
