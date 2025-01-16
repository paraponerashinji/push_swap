/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:34:17 by aharder           #+#    #+#             */
/*   Updated: 2025/01/16 14:35:20 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
