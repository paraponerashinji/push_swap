/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:14:45 by aharder           #+#    #+#             */
/*   Updated: 2025/01/13 20:21:00 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     print_error(void)
{
    write(2, "Error\n", 6);
    return (0);
}

int     is_sorted(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next)
    {
        if (tmp->stack > tmp->next->stack)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    free_stacks(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    while (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        free(tmp);
    }
    while (*b)
    {
        tmp = *b;
        *b = (*b)->next;
        free(tmp);
    }
}

void    print_stacks(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    ft_printf("Stack A:\n");
    tmp = *a;
    while (tmp)
    {
        ft_printf("%d\n", tmp->stack);
        tmp = tmp->next;
    }
    ft_printf("Stack B:\n");
    tmp = *b;
    while (tmp)
    {
        ft_printf("%d\n", tmp->stack);
        tmp = tmp->next;
    }
}