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

int    has_duplicate(int num, char **argv, int pos, int argc)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (i != pos && ft_atoi(argv[i]) == num)
            return (1);
        i++;
    }
    return (0);
}

int    check_args(int argc, char *argv[])
{
    int i;
    int j;
    int num;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
                return (print_error());
            j++;
        }
        num = ft_atoi(argv[i]);
        if (has_duplicate(num, argv, i, argc))
            return (print_error());
        i++;
    }
    return (1);
}