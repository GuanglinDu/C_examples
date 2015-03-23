/**
 * Links against the static and shared library once, respectively.
 * See Makefile on how to create a static library and a shared library based on pointer_examples.c.
 * See http://www.adp-gmbh.ch/cpp/gcc/create_lib.html
 * 
 * @author Guanglin Du (dglqxq@163.com)
 * @version Mar. 21, 2015 Sat.
 */
#include <stdio.h>
#include "pointer_examples.h"

int main(int argc, char *argv[])
{
	int a, b, s2, *ps2;
	a = 10;
	b = 20;
	s2 = 0;

	ps2 = &s2;
	sum02(&a, &b, ps2);
	printf("--- Hi, I'm using a static/shared library\n");
	printf("link_lib_main: %d + %d = %d\n", a, b, s2);
	
	return 0;
}
