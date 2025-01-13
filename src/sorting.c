/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:01:57 by aharder           #+#    #+#             */
/*   Updated: 2025/01/13 20:23:44 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sort_two(t_stack **stack_a)
{
    if ((*stack_a)->stack > (*stack_a)->next->stack)
        swap(stack_a, 'a');
}

void    sort_three(t_stack **stack_a)
{
    if ((*stack_a)->stack > (*stack_a)->next->stack && 
        (*stack_a)->next->stack > (*stack_a)->next->next->stack)
    {
        swap(stack_a, 'a');
        rrotate(stack_a, 'a');
    }
    else if ((*stack_a)->stack > (*stack_a)->next->stack)
        swap(stack_a, 'a');
    else if ((*stack_a)->next->stack > (*stack_a)->next->next->stack)
        rrotate(stack_a, 'a');
    if ((*stack_a)->stack > (*stack_a)->next->stack)
        swap(stack_a, 'a');
}

void    sort_small(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    size = stack_size(stack_a);
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else
        sort_more_than_three(stack_a, stack_b);
}
void    sort_more_than_three(t_stack **stack_a, t_stack **stack_b)
{
    int min;
    int min_pos;
    t_stack *tmp;

    while (stack_size(stack_a) > 3)
    {
        min_pos = 0;
        min = (*stack_a)->index;
        tmp = *stack_a;
        while (tmp)
        {
            if (tmp->index < min)
            {
                min = tmp->index;
                min_pos++;
            }
            tmp = tmp->next;
        }
        if (min_pos <= stack_size(stack_a) / 2)
            while ((*stack_a)->index != min)
                rotate(stack_a, 'a');
        else
            while ((*stack_a)->index != min)
                rrotate(stack_a, 'a');
        push(stack_a, stack_b, 'b');
    }
    sort_three(stack_a);
    while (*stack_b)
        push(stack_b, stack_a, 'a');
}

void    sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
        int     i;
        int     size;
        int     max_num;
        int     pos;
        t_stack *tmp;

        size = stack_size(stack_a);
        max_num = 0;
        tmp = *stack_a;
        while (tmp)
        {
            if (tmp->index > max_num)
                max_num = tmp->index;
            tmp = tmp->next;
        }
        pos = 0;
        while ((max_num >> pos) > 0)
        {
            i = 0;
            while (i < size)
            {
                if (((*stack_a)->index >> pos) & 1)
                    rotate(stack_a, 'a');
                else
                    push(stack_a, stack_b, 'b');
                i++;
            }
            while (*stack_b)
                push(stack_b, stack_a, 'a');
            pos++;
        }
}