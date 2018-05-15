#include <stdio.h>
#include <stdlib.h>
int getch(void);
void ungetch(int);
int isdigit(int);
int isspace(int);
/* getint: get next integer from input into *pn */
int getint1(int *pn)
{
	int c, sign;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
void swap(int *px, int *py) /* interchange *px and *py */
{
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}

void quickSort(int arr[], int left, int right){
	int last;
	if(left < right){
		int mid = (left+right)/2;

		swap(&arr[left], &arr[mid]);
		last=left;
		for(int i=left+1; i < right; ++i){
			 if(arr[i] < arr[left])
				 swap(&arr[++last], &arr[i]);
		}

		swap(&arr[last], &arr[left]);

		quickSort(arr, left, last-1);
		quickSort(arr, last+1, right);
	}
}

int main(void){
	int a=1, b=2;
	printf("a = %d, b = %d\n",a,b);
	swap(&a,&b);
	printf("a = %d, b = %d\n",a,b);
	int arr[] = {2,4,5,1,2,8,9,10};
	quickSort(arr, 0, 7);
	for(int i = 0; i< 8; i++)
		printf("%d ", arr[i]);
	return EXIT_SUCCESS;
}
