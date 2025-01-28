/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:58:42 by aharder           #+#    #+#             */
/*   Updated: 2025/01/15 21:43:33 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_stack
{
	int				stack;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		print_error(void);
// Check_args
int		has_duplicate(int num, char **args, int pos);
int		check_args(int argc, char *argv[]);

// Moves
void	push(t_stack **src, t_stack **dest, char name);
void	swap(t_stack **stack, char name);
void	rotate(t_stack **stack, char name);
void	rrotate(t_stack **stack, char name);
// Init_stack
int		stack_size(t_stack **stack);
void	add_to_stack(t_stack **a, int value);
void	init_stacks(t_stack **a, t_stack **b);
void	assign_indices(t_stack **a);
void	init_stack_a(t_stack **a, int argc, char *argv[]);
// Sorting
int		find_min_pos(t_stack **stack);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	radix_sort_stack_b(t_stack **stack_a, t_stack **stack_b,
			int bit_pos, int bit_max);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
// Utilities
int		is_sorted(t_stack **stack);
void	free_stacks(t_stack **a, t_stack **b);
int		print_error(void);
int		main(int argc, char *argv[]);
