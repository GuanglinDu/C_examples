#ifndef HELLO_POINTER_H
#define HELLO_POINTER_H

void simple_pointers();

void swap(int *a, int *b);

/**
 * Calls back the function pointer passed to sort.
 * 
 * @param a the first integer to be sorted
 * @param b the second integer to be sorted
 * @param fp the function pointer to be used as the sorter
 */
void callback_demo(int *a, int *b, void (*fp)(int *x, int *y));

void ascending_sort(int*a, int *b);

void descending_sort(int*a, int *b);

#endif // HELLO_POINTER_H
