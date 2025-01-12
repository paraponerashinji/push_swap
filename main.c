/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:08:56 by aharder           #+#    #+#             */
/*   Updated: 2025/01/12 22:03:23 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct  s_stack
{
    int *stack;
    int top;
    int size;
}   t_stack;

int     print_error(void)
{
    ft_printf("Error\n");
    return (0);
}
int     is_full(t_stack *stack)
{
    if (stack->top == stack->size - 1)
        return (1);
    return (0);
}
int     get_size(char **values)
{
    int i;
    int size;
    char **str;

    str = ft_split(values[1], ' ');
    i = 0;
    size = 0;
    while (str[i])
    {
        size++;
        i++;
    }
    free(str);
    return (size);
}
void    push(t_stack *src, t_stack *dest, char name)
{
    if (src->top < 0)
        return ;
    if (dest->top < dest->size - 1)
    {
        dest->top++;
        dest->stack[dest->top] = src->stack[src->top];
        src->top--;
        ft_printf("p%c\n", name);
    }
}
void    rotate(t_stack *stack, char name)
{
    int i;
    int tmp;

    if (stack->top < 1)
        return ;
    i = 0;
    tmp = stack->stack[0];
    while (i < stack->top)
    {
        stack->stack[i] = stack->stack[i + 1];
        i++;
    }
    stack->stack[stack->top] = tmp;
    ft_printf("r%c\n", name);
}
void    init_stack(t_stack *stack, int size)
{
    stack->stack = ft_calloc(size, sizeof(int));
    stack->top = -1;
}
void    fill_stack(t_stack *stack, char **values, int argc)
{
    int i;

    i = 1;
    stack->size = argc;
    while (i < argc)
    {
        if(!is_full(stack))
        {
            stack->top++;
            stack->stack[stack->top] = ft_atoi(values[i]);
        }
        i++;
    }
}
int    find_biggest(t_stack *stack)
{
    int i;
    int max;

    i = 0;
    max = stack->stack[0];
    while (i <= stack->top)
    {
        if (stack->stack[i] > max)
            max = stack->stack[i];
        i++;
    }
    return (max);
}
int    find_bits(int max)
{
    int i;

    i = 0;
    while (max > 0)
    {
        i++;
        max >>= 1;
    }
    return (i);
}
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int ii;
    int max;
    int biggest;

    biggest = find_biggest(stack_a);
    max = find_bits(biggest);
    i = 0;
    while (i < max)
    {
        ii = 0;
        while (ii <= biggest)
        {
            if(((stack_a->stack[stack_a->top] >> i) & 1) == 1)
                rotate(stack_a, 'a');
            else
            {
                push(stack_a, stack_b, 'b');
            }
            ii++;
        }
        while (stack_b->top != -1)
            push(stack_b, stack_a, 'a');
        i++;
    }
}

void    print_stack(t_stack *stack)
{
    int i;

    i = 0;
    while (i <= stack->top)
    {
        ft_printf("%d ", stack->stack[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_stack stack_a;
    t_stack stack_b;
    int size;
    char **str;
    if (argc == 2)
    {
        size = get_size(argv);
        str = ft_split(argv[1], ' ');
    }
    else
    {
        size = argc - 1;
        str = argv;
    }
    init_stack(&stack_a, 100);
    init_stack(&stack_b, 100);
    fill_stack(&stack_a, str, size);
    sort_stack(&stack_a, &stack_b);
    print_stack(&stack_a);
}