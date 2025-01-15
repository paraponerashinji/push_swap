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
	int		min;

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

void	sort_two(t_stack **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, 'a');
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first > second && second < third && third > first)
		swap(stack, 'a');
	else if (first > second && second > third)
	{
		swap(stack, 'a');
		rrotate(stack, 'a');
	}
	else if (first > second && second < third && third < first)
		rotate(stack, 'a');
	else if (first < second && second > third && third > first)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (first < second && second > third && third < first)
		rrotate(stack, 'a');
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a);
	if (min_pos == 1)
		rotate(stack_a, 'a');
	else if (min_pos == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (min_pos == 3)
		rrotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a);
	if (min_pos == 1)
		rotate(stack_a, 'a');
	else if (min_pos == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (min_pos == 3)
	{
		rrotate(stack_a, 'a');
		rrotate(stack_a, 'a');
	}
	else if (min_pos == 4)
		rrotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_four(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
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
