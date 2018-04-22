/*
#include <stdio.h>
#include <stdlib.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')
unsigned getbits1(unsigned, int, int);
int bitcount(unsigned);
int main(void){

	printf("%d\n",2 << 7);
	printf("%d\n""j""\n",0 || 0);
	printf(BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(7));
	printf("%x\n", getbits1 (7, 3,2));
	printf("%d", bitcount(31));
return EXIT_SUCCESS;
}
unsigned getbits1(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 1)
			b++;
	return b;
}
*/
