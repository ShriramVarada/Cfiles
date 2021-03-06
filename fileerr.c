#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#define getchar() getc(stdin)
#define putchar() putc(c, stdout)
int main(int argc, char **argv){

	FILE *fp;
	char* prog = argv[0];
		if(argc==1){
			filecopy(stdin, stdout);
			fclose(stdin);
			fclose(stdout);
		}
		else{
			while(--argc > 0){
				if((fp = fopen(*++argv, "r")) == NULL){
					fprintf(stderr, "%s: can't open %s\n", prog, *argv);
					exit(1);
				}else{
					filecopy(fp, stdout);
					fclose(fp);
				}
			}
		}
		if (ferror(stdout)) {
			fprintf(stderr, "%s: error writing stdout\n", prog);
			exit(2);
		}
	exit(0);
}
void filecopy(FILE * in, FILE * out){
	int c;
	while((c = getc(in)) != EOF)
		putc(c, out);
}
