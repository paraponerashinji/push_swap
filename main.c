/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:05:11 by aharder           #+#    #+#             */
/*   Updated: 2024/12/22 22:39:46 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

typedef	struct	s_value
{
	int	max;
	int	min;
}	t_value;

typedef struct	s_array
{
	int	*input;
	int	size;
	int	*output;
}	t_array;

typedef	struct s_answer
{
	int	i;
	int	value;
	int	ineg;
	int	valueneg;
}	t_answer;

t_value	maxint(int *list, int size)
{
	int	i;
	t_value	value;

	i = 0;
	value.min = list[0];
	value.max = list[0];
	while (i < size)
	{
		if (list[i] < value.min)
			value.min = list[i];
		if (list[i] > value.max)
			value.max = list[i];
		i++;
	}
	return (value);
}

int	size_arg(char *str)
{
	int	size;
	char	**split;
	int	i;

	size = 0;
	split = ft_split(str, ' ');
	while (split[size] != NULL)
	{
		i = 0;
		while (split[size][i] != '\0')
		{
			if (split[size][i] == '-')
				i++;
			if (ft_isdigit(split[size][i]) == 0)
			{
				ft_printf("Erreur dans la liste prise en argument");
				exit(1);
			}
			i++;
		}
		size++;
	}
	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	return (size);
}

int	*parse_arg(char *str, int size)
{
	char	**split;
	int	*output;
	int	i;

	output = ft_calloc(size, sizeof(int));
	split = ft_split(str, ' ');
	i = 0;
	while (split[i] != NULL)
	{
		output[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (output);
}

int	*countint(t_array array, t_value value)
{
	int	*output;
	int	i;

	i = 0;
	output = ft_calloc((value.max - value.min + 1), sizeof(int));
	while (i < array.size)
	{
		output[array.input[i] - value.min]++;
		i++;
	}
	return (output);
}

int	*sort_array(t_array array, int	*count_array, t_value value)
{
	int	i;
	int	ii;
	int	iii;

	i = 0;
	ii = 0;
	array.output = ft_calloc(array.size, sizeof(int));
	while (i <= value.max - value.min)
	{
		iii = 0;
		while (iii < count_array[i])
		{
			array.output[ii++] = i + value.min;
			iii++;
		}
		i++;
	}
	return (array.output);
	
}
/*
t_answer	*answer_array(array, value)
{
	t_answer	*answer;
	int	i;
	int	ii;
	int	iii;

	ii = 0;
	i = 0;
	answer = ft_calloc(value.max, sizeof(t_answer));
	while (i <= value.max - value.min)
	{
		iii = 0;
		while (iii < count_array[i])
		{
			if (i + value.min >= 0)
			{
				answer[ii].i = ii;
				answer[ii].value = i + value.min;
			}
			if (i + value.min < 0)
			{
				answer[ii].ineg = ii;
				answer[ii].valueneg = i + value.min;
			}
			ii++;
			iii++;
		}
		i++;
	} 
}*/
t_answer *answer_array(int *count_array, t_value value) {
    int size = value.max - value.min + 1;
    t_answer *answer = (t_answer *)calloc(size, sizeof(t_answer));
    int i, ii, iii;

    ii = 0;
    i = 0;

    // Parcours du tableau count_array pour remplir answer
    while (i < size) {
        iii = 0;
        while (iii < count_array[i]) {
            if (i + value.min >= 0) {
                answer[i + value.min].i = ii;
                answer[i + value.min].value = i + value.min;
            } else {
                answer[i + value.min].ineg = ii;
                answer[i + value.min].valueneg = i + value.min;
            }
            ii++;
            iii++;
        }
        i++;
    }

    return answer;
}
/*
void	get_instructions(t_array array, t_answer *answer)
{
	int	i;
	int	ii;

	ft_printf("pb\n");
	i = 1;
	while (i < array.size)
	{
		ii = 0;
		ft_printf("pb\n");
		while (	
	}
}*/

int	main(int argc, char *argv[])
{
	t_array	array;
	t_value	value;
	t_answer	*answer;
	int	*count_array;
	int	i;

	(void)argc;
	i = 0;
	array.size = size_arg(argv[1]);
	array.input = parse_arg(argv[1], array.size);
	value = maxint(array.input, array.size);
	count_array = countint(array, value);
	answer = answer_array(count_array, value);
	/*
	while (i < array.size)
	{
		ft_printf("%i ", array.output[i]);
		i++;
	}*/
	get_instructions(array, answer)
}
