/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:54:16 by aharder           #+#    #+#             */
/*   Updated: 2025/01/15 21:07:11 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;
	int		min_pos;
	unsigned int		min;

	tmp = *stack;
	pos = 0;
	min_pos = 0;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

void	radix_sort_stack_b(t_stack **stack_a, t_stack **stack_b,
		int bit_pos, int bit_max)
{
	int	size_b;

	size_b = stack_size(stack_b);
	while (size_b-- && bit_pos <= bit_max && !is_sorted(stack_a))
	{
		if ((((*stack_b)->index >> bit_pos) & 1) == 0)
			rotate(stack_b, 'b');
		else
			push(stack_b, stack_a, 'a');
	}
	if (is_sorted(stack_a))
	{
		while (*stack_b)
			push(stack_b, stack_a, 'a');
	}
}

int	get_bit_size(int size)
{
	int	bit_size;

	bit_size = 0;
	while (size > 1)
	{
		size /= 2;
		bit_size++;
	}
	return (bit_size);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	bit_pos;
	int	bit_max;
	int	size;
	int	current_size;

	size = stack_size(stack_a);
	bit_max = get_bit_size(size);
	bit_pos = 0;
	while (bit_pos <= bit_max)
	{
		current_size = stack_size(stack_a);
		while (current_size-- && !is_sorted(stack_a))
		{
			if ((((*stack_a)->index >> bit_pos) & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, 'a');
		}
		radix_sort_stack_b(stack_a, stack_b, bit_pos + 1, bit_max);
		bit_pos++;
	}
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}
