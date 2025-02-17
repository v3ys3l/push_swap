// push_swap.h
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_SIZE 100

// Stack manipülasyon fonksiyonları
void    push_a(int *a, int *b, int *a_size, int *b_size);
void    push_b(int *a, int *b, int *a_size, int *b_size);
void    swap_a(int *a, int a_size);
void    swap_b(int *b, int b_size);
void    rotate_a(int *a, int *a_size);
void    rotate_b(int *b, int *b_size);
void    reverse_rotate_a(int *a, int *a_size);
void    reverse_rotate_b(int *b, int *b_size);

// Algoritma fonksiyonları
void    radix_sort(int *a, int *b, int a_size);
int     get_max_bit(int *a, int size);
void    counting_sort(int *a, int *b, int size, int exp);
// Yardımcı fonksiyonlar
int     get_array_size(int *a);

#endif
