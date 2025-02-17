// push_swap.c
#include "push_swap.h"

void    push_a(int *a, int *b, int *a_size, int *b_size)
{
    if (*b_size == 0)
        return;

    a[*a_size] = b[*b_size - 1];
    (*a_size)++;
    (*b_size)--;
}

void    push_b(int *a, int *b, int *a_size, int *b_size)
{
    if (*a_size == 0)
        return;

    b[*b_size] = a[*a_size - 1];
    (*b_size)++;
    (*a_size)--;
}

void    swap_a(int *a, int a_size)
{
    int temp;
    if (a_size < 2)
        return;

    temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}

void    swap_b(int *b, int b_size)
{
    int temp;
    if (b_size < 2)
        return;

    temp = b[0];
    b[0] = b[1];
    b[1] = temp;
}

void    rotate_a(int *a, int *a_size)
{
    int temp;
    int i;

    if (*a_size < 2)
        return;

    temp = a[0];
    for (i = 0; i < *a_size - 1; i++)
        a[i] = a[i + 1];
    a[*a_size - 1] = temp;
}

void    rotate_b(int *b, int *b_size)
{
    int temp;
    int i;

    if (*b_size < 2)
        return;

    temp = b[0];
    for (i = 0; i < *b_size - 1; i++)
        b[i] = b[i + 1];
    b[*b_size - 1] = temp;
}

void    reverse_rotate_a(int *a, int *a_size)
{
    int temp;
    int i;

    if (*a_size < 2)
        return;

    temp = a[*a_size - 1];
    for (i = *a_size - 1; i > 0; i--)
        a[i] = a[i - 1];
    a[0] = temp;
}

void    reverse_rotate_b(int *b, int *b_size)
{
    int temp;
    int i;

    if (*b_size < 2)
        return;

    temp = b[*b_size - 1];
    for (i = *b_size - 1; i > 0; i--)
        b[i] = b[i - 1];
    b[0] = temp;
}

int     get_array_size(int *a)
{
    int size = 0;

    while (a[size] != -1)
        size++;
    return size;
}

int     get_max_bit(int *a, int size)
{
    int max = a[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void    counting_sort(int *a, int *b, int size, int exp)
{
    int count[10] = {0};
    int i;
    int value;

    // Sayıları count dizisine göre yerleştir
    for (i = 0; i < size; i++)
    {
        value = (a[i] / exp) % 10;
        count[value]++;
    }

    // Count dizisini biriktir
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Elemanları b stackine aktar
    for (i = size - 1; i >= 0; i--)
    {
        value = (a[i] / exp) % 10;
        b[count[value] - 1] = a[i];
        count[value]--;
    }

    // b stackindeki elemanları a stackine geri aktar
    for (i = 0; i < size; i++)
    {
        a[i] = b[i];
    }
}


void    radix_sort(int *a, int *b, int a_size)
{
    int max_bit = get_max_bit(a, a_size);
    int exp = 1;

    while (max_bit / exp > 0)
    {
        counting_sort(a, b, a_size, exp);
        exp *= 10;
    }
}



int main(int argc, char **argv)
{
    int a[MAX_SIZE];
    int b[MAX_SIZE];
    int i;
    int size = 0;

    if (argc < 2)
        return (0);

    // Inputları array'e ekleyin
    for (i = 1; i < argc; i++)
    {
        a[size] = atoi(argv[i]);
        size++;
    }

    // a arrayini sıralamak için radix sort'u kullan
    radix_sort(a, b, size);

    // Sonucu yazdır
    for (i = 0; i < size; i++)
        printf("%d\n", a[i]);  // Sayıyı düzgün bir şekilde yazdırıyoruz

    return (0);
}
