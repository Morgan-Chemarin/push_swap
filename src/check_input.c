/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:32:02 by dev               #+#    #+#             */
/*   Updated: 2025/04/12 19:14:03 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_duplicates(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fill_numbers_from_argument(char *arg, int *nums, int *index)
{
	char	**split;
	int		j;
	long	n;

	j = 0;
	split = ft_split(arg, ' ');
	if (!split)
		exit(EXIT_FAILURE);
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			error_msg("Error");
		n = ft_atol(split[j]);
		if (n < INT_MIN || n > INT_MAX)
			error_msg("Error");
		nums[*index] = (int)n;
		(*index)++;
		j++;
	}
	free_split(split);
}

void	count_total_numbers(int ac, char **av, int *count)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			exit(EXIT_FAILURE);
		j = 0;
		while (split[j])
		{
			(*count)++;
			j++;
		}
		free_split(split);
		i++;
	}
}

void	check_input(int ac, char **av)
{
	int	count;
	int	index;
	int	*nums;
	int	i;

	count = 0;
	index = 0;
	i = 1;
	count_total_numbers(ac, av, &count);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		exit(EXIT_FAILURE);
	while (i < ac)
	{
		fill_numbers_from_argument(av[i], nums, &index);
		i++;
	}
	if (has_duplicates(nums, count))
		error_msg("Error");
	free(nums);
}
