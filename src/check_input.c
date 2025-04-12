/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:32:02 by dev               #+#    #+#             */
/*   Updated: 2025/04/12 12:47:02 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_duplicates(int *nums, int size)
{
	int i = 0;
	int j;

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
	int i = 0;

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

void	check_input(int ac, char **av)
{
	int		count = 0;
	int		i = 1;
	int		j;
	int		index = 0;
	char	**split;
	int		*nums;
	long	n;

	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
		i++;
	}
	nums = malloc(sizeof(int) * count);
	if (!nums)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
				error_msg("Error");
			n = ft_atol(split[j]);
			if (n < INT_MIN || n > INT_MAX)
				error_msg("Error");
			nums[index++] = (int)n;
			j++;
		}
		free_split(split);
		i++;
	}
	if (has_duplicates(nums, count))
		error_msg("Error");
	free(nums);
}
