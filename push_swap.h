#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int     *array;
    int     top;        // stack'in en üstündeki elemanın indeksi
    int     capacity;
} t_stack;

// Stack işlemleri
void    stack_init(t_stack *stack, int capacity);
void    stack_push(t_stack *stack, int value);  // Stack'e eleman ekler
int     stack_pop(t_stack *stack);              // Stack'ten eleman çıkarır
int     stack_peek(t_stack *stack);             // En üstteki elemanı gösterir
int     is_empty(t_stack *stack);               // Stack boş mu kontrol eder
int     is_full(t_stack *stack);                // Stack dolu mu kontrol eder
void    stack_destroy(t_stack *stack);

// Sıralama işlemleri
void    sort_stack(t_stack *a, t_stack *b);
void    sort_three(t_stack *a);
void    sort_small(t_stack *a, t_stack *b);
void    sort_large(t_stack *a, t_stack *b);

// Stack operasyonları
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

// Yardımcı fonksiyonlar
int     is_sorted(t_stack *stack);
int     find_min(t_stack *stack);
int     find_max(t_stack *stack);
void    error_exit(void);

#endif 