/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:29:03 by dev               #+#    #+#             */
/*   Updated: 2025/04/15 15:43:02 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	append_node(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*tmp;

	node = new_node(value);
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_stack	*init_list(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;
	long	n;
	char	**split;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			n = ft_atol(split[j]);
			append_node(&stack_a, (int)n);
			j++;
		}
		free_split(split);
		i++;
	}
	return (stack_a);
}

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	parse_and_fill(int ac, char **av, int *nums, int *index)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!fill_numbers_from_argument(av[i], nums, index))
		{
			free(nums);
			error_msg("Error");
		}
		i++;
	}
}
