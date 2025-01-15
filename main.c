/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:08:56 by aharder           #+#    #+#             */
/*   Updated: 2025/01/15 21:06:54 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		return (0);
	init_stacks(&a, &b);
	init_stack_a(&a, argc, argv);
	if (is_sorted(&a))
	{
		free_stacks(&a, &b);
		return (0);
	}
	if (stack_size(&a) <= 5)
		sort_small(&a, &b);
	else
		sort_stacks(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
