/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:32:42 by vbicer            #+#    #+#             */
/*   Updated: 2025/02/19 02:54:33 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sa(t_stack *a)
{
    if (a->size > 1)
    {
        ft_swap(&a->arr[0], &a->arr[1]);
        write(1, "sa\n", 3);
    }
}

void sb(t_stack *b)
{
    if (b->size > 1)
    {
        ft_swap(&b->arr[0], &b->arr[1]);
        write(1, "sb\n", 3);
    }
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->size > 0)
    {
        for (int i = a->size; i > 0; i--)
            a->arr[i] = a->arr[i - 1];
        a->arr[0] = b->arr[0];
        a->size++;
        for (int i = 0; i < b->size - 1; i++)
            b->arr[i] = b->arr[i + 1];
        b->size--;
        write(1, "pa\n", 3);
    }
}

void pb(t_stack *a, t_stack *b)
{
    if (a->size > 0)
    {
        for (int i = b->size; i > 0; i--)
            b->arr[i] = b->arr[i - 1];
        b->arr[0] = a->arr[0];
        b->size++;
        for (int i = 0; i < a->size - 1; i++)
            a->arr[i] = a->arr[i + 1];
        a->size--;
        write(1, "pb\n", 3);
    }
}

void ra(t_stack *a)
{
    if (a->size > 1)
    {
        int temp = a->arr[0];
        for (int i = 0; i < a->size - 1; i++)
            a->arr[i] = a->arr[i + 1];
        a->arr[a->size - 1] = temp;
        write(1, "ra\n", 3);
    }
}

void rb(t_stack *b)
{
    if (b->size > 1)
    {
        int temp = b->arr[0];
        for (int i = 0; i < b->size - 1; i++)
            b->arr[i] = b->arr[i + 1];
        b->arr[b->size - 1] = temp;
        write(1, "rb\n", 3);
    }
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}

void rra(t_stack *a)
{
    if (a->size > 1)
    {
        int temp = a->arr[a->size - 1];
        for (int i = a->size - 1; i > 0; i--)
            a->arr[i] = a->arr[i - 1];
        a->arr[0] = temp;
        write(1, "rra\n", 4);
    }
}

void rrb(t_stack *b)
{
    if (b->size > 1)
    {
        int temp = b->arr[b->size - 1];
        for (int i = b->size - 1; i > 0; i--)
            b->arr[i] = b->arr[i - 1];
        b->arr[0] = temp;
        write(1, "rrb\n", 4);
    }
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}

int is_sorted(t_stack *a)
{
    for (int i = 0; i < a->size - 1; i++)
        if (a->arr[i] > a->arr[i + 1])
            return 0;
    return 1;
}

void selection_sort(t_stack *a)
{
    for (int i = 0; i < a->size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < a->size; j++)
            if (a->arr[j] < a->arr[min_idx])
                min_idx = j;

        if (min_idx != i)
        {
            ft_swap(&a->arr[i], &a->arr[min_idx]);
            write(1, "sa\n", 3);
        }
    }
}

void radix_sort(t_stack *a, t_stack *b)
{
    int max = get_max(a);
    int bits = 0;

    // Max değeri için bit uzunluğunu hesapla
    while ((max >> bits) != 0)
        bits++;

    // Her bit için işlemi yap
    for (int i = 0; i < bits; i++)
    {
        // a yığındaki her eleman için, bit kontrolü yaparak sıralama
        for (int j = 0; j < a->size; j++)
        {
            if ((a->arr[0] >> i) & 1)
                ra(a);  // Eğer bit 1 ise, `ra` uygula
            else
                pb(a, b);  // Eğer bit 0 ise, `pb` ile b'ye taşı
        }

        // b'deki tüm elemanları a'ya geri taşı
        while (b->size > 0)
            pa(a, b);
    }
}

int get_max(t_stack *stack)
{
    int max = stack->arr[0];
    for (int i = 1; i < stack->size; i++)
        if (stack->arr[i] > max)
            max = stack->arr[i];
    return max;
}

void print_stack(t_stack *stack)
{
    for (int i = 0; i < stack->size; i++)
        printf("%d ", stack->arr[i]);
    printf("\n");
}

void free_stack(t_stack *stack)
{
    free(stack->arr);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i;

    // Stack 'a' ve 'b' başlatma
    a.size = argc - 1;
    a.arr = (int *)malloc(sizeof(int) * a.size);
    b.size = 0;
    b.arr = (int *)malloc(sizeof(int) * a.size);

    // Argümanları stack 'a'ya kopyalama
    for (i = 0; i < a.size; i++)
    {
        a.arr[i] = atoi(argv[i + 1]);
    }

    // Hedefimiz sıralı olmasını sağlamak
    if (!is_sorted(&a))
    {
        // Radix sort veya selection sort kullanabiliriz
        radix_sort(&a, &b); // Radix sort kullanılacak
        // selection_sort(&a); // Alternatif olarak bu da kullanılabilir
    }

    // Sonuçları yazdırma (isteğe bağlı)
    // print_stack(&a);

    // Belleği temizleme
    free_stack(&a);
    free_stack(&b);

    return 0;
}
