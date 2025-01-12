/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:05:11 by aharder           #+#    #+#             */
/*   Updated: 2025/01/12 00:53:13 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct  s_stack
{
    int *arr;
    int top;
    int size;
}   t_stack;
/*
int     check_args(char **str, int argc)
{
    int i;

    i = 0;
    if (argc < 2)
        return (0);
    if (argc == 2)
        str = ft_split(str[1], ' ');
    else
        i = 1;
    while (str[i] != '\0')
    {
        if (!ft_isnum(str[i]))
        {
            if (argc == 2)
                free(str);
            return (0);
        }
    }
    if (argc == 2)
        free(str);
    return (1);
}*/

int     is_full(t_stack *stack)
{
    return (stack->top == stack->size - 1);
}

int     is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->top)
    {
        if(stack->arr[i] > stack->arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}
void    init_stack(t_stack *stack, int size)
{
    stack->arr = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
}

void    free_stack(t_stack *stack)
{
    if (stack->arr != NULL)
        free(stack->arr);
}
void    push(t_stack *src, t_stack *dest, char name)
{
    if (src->top == -1)
        return;
    dest->top++;
    dest->arr[dest->top] = src->arr[src->top];
    src->top--;
    ft_printf("p%c\n", name);
}
void    rotate(t_stack *stack, char name)
{
    int buffer;
    int i;

    i = 0;
    buffer = stack->arr[0];
    if (stack->top < 1)
        return ;
    while (i < stack->top)
    {
        stack->arr[i] = stack->arr[i + 1];
        i++;
    }
    stack->arr[stack->top] = buffer;
    ft_printf("r%c\n", name);
}
void    fill_stack(t_stack *stack, char **values, int argc)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if(!is_full(stack))
        {
            stack->top++;
            stack->arr[stack->top] = ft_atoi(values[i]);
        }
        i++;
    }
}
int     get_size(char **argv)
{
    int i;
    char    **str;

    i = 0;
    str = ft_split(argv[1], ' ');
    while (str[i] != NULL)
        i++;
    free(str);
    return (i);

}
int     get_max(t_stack *stack)
{
    int max;
    int i;

    i = 1;
    max = stack->arr[0];
    while (i <= stack->top)
    {
        if (stack->arr[i] > max)
            max = stack->arr[i];
        i++;
    }
    return (max);
}

void    sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
    int i;
    int ii;
    int max;
    int bit_size;

    bit_size = 0;
    i = 0;
    max = get_max(stack_a);
    while (max > 0)
    {
        bit_size++;
        max >>= 1;
    }
    while (i <= bit_size)
    {
        ii = 0;
        while (ii++ < size)
        {
            if(((stack_a->arr[stack_a->top] >> i) & 1) == 1)
                rotate(stack_a, 'a');
            else
            {
                push(stack_a, stack_b, 'b');
            }
        }
        while (stack_b->top != -1)
            push(stack_b, stack_a, 'a');
        i++;
    }
}
void	radix_sort_stack_b(t_stack *stack_a, t_stack *stack_b, int bit_size, int j)
{
	while (stack_b->top-- && j <= bit_size && !is_sorted(stack_a))
	{
		if (((stack_b->arr[stack_b->top] >> j) & 1) == 0)
			rotate(stack_b, 'b');
		else
			push(stack_b, stack_a, 'a');
	}
	if (is_sorted(stack_b))
		while (stack_b->top-- > -1)
			push(stack_b, stack_a, 'a');
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack_a->size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack_a->size;
		while (size-- && !is_sorted(stack_a))
		{
			if (((stack_a->arr[stack_a->top] >> j) & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, 'a');
		}
        radix_sort_stack_b(stack_a, stack_b, bit_size, j + 1);
	}
	while (stack_b->top-- > -1)
		push(stack_b, stack_a, 'a');
}

void    print_stack(t_stack *stack, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ft_printf("%d ", stack->arr[i]);
        i++;
    }
    ft_printf("\n");
}
int main(int argc, char *argv[])
{
    t_stack stack_a;
    t_stack stack_b;
    /*if (argc == 2)
    {
        size = get_size(argv);
        argv = ft_split(argv[1]);
    }
    if (!check_args(argc, argv))
        return(0);*/
    init_stack(&stack_a, argc - 1);
    init_stack(&stack_b, argc - 1);
    fill_stack(&stack_a, argv, argc);
    print_stack(&stack_a, argc - 1);
    if (is_sorted(&stack_a))
    {
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (0);
    }
    radix_sort(&stack_a, &stack_b);
    print_stack(&stack_a, argc - 1);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
