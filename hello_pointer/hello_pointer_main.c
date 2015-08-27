/**
 * The main program of hello_pointer package.
 * Created on March 25, 2015 Wed.
 * Author: Guanglin Du
 */
#include <stdio.h>
#include "hello_pointer.h"
 
 /**
  * Shows the size of each data type in bytes.
  */
 void sizeof_types()
 {
	printf("The size of type init is %d bytes\n", sizeof(int));
	printf("The size of type unsigned is %d bytes\n", sizeof(unsigned));
	printf("The size of type short is %d bytes\n", sizeof(short));
	printf("The size of type long is %d bytes\n", sizeof(long));
	printf("The size of type float is %d bytes\n", sizeof(float));
	printf("The size of type double is %d bytes\n", sizeof(double));
	printf("The size of type char is %d bytes\n", sizeof(char));
 }
 
int main(int argc, char *argv[])
{
	int a = 1, b = 2;
	int c = 10, d = 5;
	
	sizeof_types();
	printf("\n");
	
	// Defines a point to a function
	//void (*pf1)(int *, int *); // OK
	void (*pf1)(int *a, int *b); // OK, too
	void (*pf2)(int *, int *);
	
	printf("--- Hello, Pointer\n"); 
	simple_pointers();
	 	
	printf("\n--- Swap two integers with pointers\n");
	printf("Before swapping, a, b = %d, %d\n", a, b);
	//swap(&a, &b);
	pf1 = swap; // assign swap to the function pointer
	//pf1 = &swap; // OK, too
	//pf1(&a, &b);
	callback_demo(&a, &b, pf1);
	printf("After swapping, a, b = %d, %d\n", a, b);

	printf("\n--- Sort two integers with function pointers\n");
	printf("Before sort, c, d = %d, %d\n", c, d);
	pf2 = ascending_sort;
	callback_demo(&c, &d, pf2);
	printf("After the ascending sort, c, d = %d, %d\n", c, d);
	
	pf2 = descending_sort;
	callback_demo(&c, &d, pf2);
	printf("After the descending sort, c, d = %d, %d\n", c, d);	

	return 0;
}
