#include "push_swap.h"

void sort_large(t_stack *a, t_stack *b)
{
    int min = find_min(a);
    int max = find_max(a);
    int range = max - min;
    int chunk_size = range / 5;
    int current_max = min + chunk_size;
    
    while (a->top > -1)
    {
        if (a->array[0] <= current_max)
        {
            pb(a, b);
            if (b->top > -1 && b->array[0] < min + chunk_size / 2)
                rb(b);
        }
        else
            ra(a);
            
        if (b->top == chunk_size - 1)
            current_max += chunk_size;
    }
    
    while (b->top > -1)
    {
        int max_b = find_max(b);
        
        while (b->array[0] != max_b)
        {
            if (max_b > b->array[0])
                rb(b);
            else
                rrb(b);
        }
        pa(a, b);
    }
}

// Stack başlatma fonksiyonu
void stack_init(t_stack *stack, int capacity)
{
    stack->array = (int *)malloc(sizeof(int) * capacity);
    if (!stack->array)
        error_exit();
    stack->top = -1;
    stack->capacity = capacity;
}

// Yardımcı fonksiyonlar
int find_min(t_stack *stack)
{
    int min;
    int i;
    
    if (stack->top == -1)
        return (0);
        
    min = stack->array[0];
    i = 1;
    while (i <= stack->top)
    {
        if (stack->array[i] < min)
            min = stack->array[i];
        i++;
    }
    return (min);
}

int find_max(t_stack *stack)
{
    int max;
    int i;
    
    if (stack->top == -1)
        return (0);
        
    max = stack->array[0];
    i = 1;
    while (i <= stack->top)
    {
        if (stack->array[i] > max)
            max = stack->array[i];
        i++;
    }
    return (max);
}

static int get_max_bits(t_stack *stack)
{
    int max = find_max(stack);
    int bits = 0;
    
    while (max > 0)
    {
        bits++;
        max >>= 1;
    }
    return (bits);
}

static int get_bit(int num, int pos)
{
    return ((num >> pos) & 1);
}

// Özel durumlar için geliştirilmiş kontrol fonksiyonları
static int count_inversions(t_stack *stack)
{
    int inversions;
    int i;
    int j;
    
    inversions = 0;
    i = stack->top;
    while (i > 0)
    {
        j = i - 1;
        while (j >= 0)
        {
            if (stack->array[i] > stack->array[j])
                inversions++;
            j--;
        }
        i--;
    }
    return (inversions);
}

static int find_best_rotation(t_stack *stack)
{
    int i;
    int min_pos;
    
    min_pos = stack->top;
    i = stack->top - 1;
    while (i >= 0)
    {
        if (stack->array[i] < stack->array[min_pos])
            min_pos = i;
        i--;
    }
    
    if (min_pos >= stack->top / 2)
        return (min_pos);
    return (-(stack->top - min_pos));
}

// Optimize edilmiş ters sıralama fonksiyonu
static void handle_reverse_sorted(t_stack *a, t_stack *b)
{
    int chunk = a->top / 3;
    int i = 0;
    
    while (i < chunk * 2)
    {
        pb(a, b);
        if (b->top > 0 && b->array[0] < b->array[1])
            sb(b);
        i++;
    }
    
    while (b->top > -1)
    {
        if (b->array[0] > b->array[b->top])
            rb(b);
        pa(a, b);
    }
}

// Optimize edilmiş neredeyse sıralı fonksiyonu
static void handle_almost_sorted(t_stack *a)
{
    int rotation = find_best_rotation(a);
    
    if (rotation > 0)
    {
        while (rotation--)
            ra(a);
    }
    else
    {
        while (rotation++)
            rra(a);
    }
    
    if (a->top >= 0 && a->array[0] > a->array[1])
        sa(a);
}

// Radix sort fonksiyonunu güncelle
void radix_sort(t_stack *a, t_stack *b)
{
    int inversions;
    
    if (is_sorted(a))
        return;
        
    inversions = count_inversions(a);
    
    if (inversions > (a->top * (a->top + 1)) / 2 - 2)
    {
        handle_reverse_sorted(a, b);
        return;
    }
    else if (inversions <= a->top + 2)
    {
        handle_almost_sorted(a);
        return;
    }
    
    normalize_array(a);
    int i = 0;
    
    while ((a->top + 1) >> i > 0)
    {
        int j = 0;
        while (j <= a->top)
        {
            if (get_bit(a->array[a->top], i) == 0)
            {
                pb(a, b);
                if (b->top > 0 && b->array[b->top] < b->array[b->top - 1])
                    sb(b);
            }
            else
                ra(a);
            j++;
        }
        while (b->top >= 0)
            pa(a, b);
        i++;
    }
}

static int get_pivot(t_stack *stack, int size)
{
    int i;
    int sum;
    
    sum = 0;
    i = 0;
    while (i < size)
    {
        sum += stack->array[stack->top - i];
        i++;
    }
    return (sum / size);
}

static int partition_stack(t_stack *a, t_stack *b, int size)
{
    int pivot;
    int elements_pushed;
    int i;
    
    if (size <= 3)
    {
        if (size == 2 && a->array[a->top] > a->array[a->top - 1])
            sa(a);
        else if (size == 3)
            sort_three(a);
        return (0);
    }
    
    pivot = get_pivot(a, size);
    elements_pushed = 0;
    i = 0;
    
    while (i < size)
    {
        if (a->array[a->top - i] <= pivot)
        {
            pb(a, b);
            elements_pushed++;
        }
        else
            ra(a);
        i++;
    }
    
    // Kalan elemanları başa getir
    i = 0;
    while (i < size - elements_pushed)
    {
        rra(a);
        i++;
    }
    
    return (elements_pushed);
}

void quick_sort(t_stack *a, t_stack *b, int size)
{
    int elements_pushed;
    
    if (size <= 1)
        return;
        
    elements_pushed = partition_stack(a, b, size);
    
    // A'daki üst yarıyı sırala
    quick_sort(a, b, size - elements_pushed);
    
    // B'deki alt yarıyı sırala ve geri gönder
    while (elements_pushed > 0)
    {
        pa(a, b);
        elements_pushed--;
    }
}

// Ana sıralama fonksiyonunu güncelle
void sort_stack(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
        return;
        
    if (a->top <= 2)
        sort_three(a);
    else if (a->top <= 4)
        sort_small(a, b);
    else
        quick_sort(a, b, a->top + 1);
}

// 3 sayıyı sıralama
void sort_three(t_stack *a)
{
    if (a->top <= 0)
        return;
    if (a->top == 1)
    {
        if (a->array[a->top] > a->array[a->top - 1])
            sa(a);
        return;
    }
    
    int first = a->array[a->top - 2];
    int second = a->array[a->top - 1];
    int third = a->array[a->top];
    
    if (first > second && second < third && third > first)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && third < first)
        ra(a);
    else if (first < second && second > third && third > first)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && third < first)
        rra(a);
}

void normalize_array(t_stack *a)
{
    int *temp;
    int i;
    int j;
    int pos;
    
    temp = (int *)malloc(sizeof(int) * (a->top + 1));
    if (!temp)
        error_exit();
        
    i = 0;
    while (i <= a->top)
    {
        temp[i] = a->array[i];
        i++;
    }
    
    i = 0;
    while (i <= a->top)
    {
        pos = 0;
        j = 0;
        while (j <= a->top)
        {
            if (temp[j] < temp[i])
                pos++;
            j++;
        }
        a->array[i] = pos;
        i++;
    }
    free(temp);
} 