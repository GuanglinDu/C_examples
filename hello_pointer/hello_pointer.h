#ifndef HELLO_POINTER_H
#define HELLO_POINTER_H

void simple_pointers();

void swap(int *a, int *b);

void callback_demo(int *a, int *b, void (*fp)(int *x, int *y));

void ascending_sort(int*a, int *b);

#endif // HELLO_POINTER_H
