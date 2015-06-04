#include <stdio.h>
#include "hello_pointer.h"

void simple_pointers()
{
	int x = 1, y = 2, z[10];
	z[0] = 100;
	
	//int *ip; 	/* ip is a pointer to int */
	//int* ip; // OK
	int * ip; // OK
	//ip = &x; /* ip now points to x */
	ip = &x;
	printf("The address of x: %p, the size of the address is %d bytes.\n", ip, sizeof(ip));
	
	y = *ip; 	/* y is now 1 */
	printf("y = %d\n", y);
	*ip = 0;  /* x is now 0 */
	printf("*ip = %d\n", *ip);
	ip = &z[0];  /* ip now points to z[0] */
 	printf("ip, *ip = %p, %d\n", ip, *ip);
 	
 	char *cp, c = 'd';
 	cp = &c;
 	printf("c = %c, size of cp is %d bytes\n", *cp, sizeof(cp));
 	
 	long li = 100.0l, *lp;
 	lp = &li;
 	printf("li = %lu, size of li is %d bytes\n", *lp, sizeof(lp));	
}

void swap(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c; 
}

void callback_demo(int *a, int *b, void ( *fp)(int *x, int *y)) {
	fp(a, b); // call back
}

void ascending_sort(int *a, int *b) {
	if (*a > * b) {
		int c = *a;
		*a = *b;
		*b = c;
	}
}
