/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <aharder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:09:16 by aharder           #+#    #+#             */
/*   Updated: 2025/01/13 20:20:46 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_duplicate(int num, char **args, int pos)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (i != pos && ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	is_too_big(const char *str)
{
	unsigned int	output;
	int				posneg;

	output = 0;
	posneg = 1;
	if (*str == '-')
		posneg = posneg * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		output = output * 10 + *str - '0';
		str++;
	}
	if (posneg == 1)
	{
		if (output > 2147483647)
			return (1);
	}
	else
	{
		if (output > 2147483648)
			return (1);
	}
	return (0);
}

int	is_valid(int i, char **args)
{
	int	num;
	int	j;

	j = 0;
	while (args[i][j] != '\0')
	{
		if (j == 0 && args[i][j] == '-' && args[i][j + 1] != '\0')
			j++;
		else if (!ft_isdigit(args[i][j]))
		{
			return (print_error());
		}
		else
			j++;
	}
	num = ft_atoi(args[i]);
	if (has_duplicate(num, args, i) || is_too_big(args[i]))
		return (print_error());
	return (1);
}

int	check_args(int argc, char *argv[])
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args[0] == NULL)
			return (print_error());
	}
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		if (!is_valid(i, args))
			return (0);
		i++;
	}
	return (1);
}
