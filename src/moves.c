/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:59:12 by aharder           #+#    #+#             */
/*   Updated: 2025/01/13 20:21:10 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push(t_stack **src, t_stack **dest, char name)
{
    t_stack *tmp;

    if (!src || !*src)
        return;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
    ft_printf("p%c\n", name);
}

void    swap(t_stack **stack, char name)
{
    t_stack *tmp;

    if (!(*stack) || !(*stack)->next)
        return;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
    ft_printf("s%c\n", name);
}

void    rotate(t_stack **stack, char name)
{
    t_stack *tmp;
    t_stack *last;

    if (!(*stack) || !(*stack)->next)
        return;
    tmp = *stack;
    last = *stack;
    *stack = (*stack)->next;
    while (last->next)
        last = last->next;
    last->next = tmp;
    tmp->next = NULL;
    ft_printf("r%c\n", name);
}

void    rrotate(t_stack **stack, char name)
{
    t_stack *tmp;
    t_stack *last;

    if (!(*stack) || !(*stack)->next)
        return;
    last = *stack;
    while (last->next->next)
        last = last->next;
    tmp = last->next;
    last->next = NULL;
    tmp->next = *stack;
    *stack = tmp;
    ft_printf("rr%c\n", name);
}