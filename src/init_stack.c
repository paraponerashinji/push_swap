/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:10:34 by aharder           #+#    #+#             */
/*   Updated: 2025/01/13 20:20:56 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stacks(t_stack **a, t_stack **b)
{
	*a = NULL;
	*b = NULL;
}

void	assign_indices(t_stack **a)
{
	t_stack	*current;
	t_stack	*compare;
	unsigned int		index;

	current = *a;
	while (current)
	{
		index = 0;
		compare = *a;
		while (compare)
		{
			if (compare->stack < current->stack)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	add_to_stack(t_stack **a, int value)
{
	t_stack	*buffer;
	t_stack	*last;

	buffer = malloc(sizeof(t_stack));
	buffer->stack = value;
	buffer->next = NULL;
	if (!*a)
		*a = buffer;
	else
	{
		last = *a;
		while (last->next)
			last = last->next;
		last->next = buffer;
	}
}

void	init_stack_a(t_stack **a, int argc, char *argv[])
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	*a = NULL;
	while (args[i])
		add_to_stack(a, ft_atoi(args[i++]));
	if (argc == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	assign_indices(a);
}

int	stack_size(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
