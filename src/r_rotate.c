/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:11:29 by dev               #+#    #+#             */
/*   Updated: 2025/04/14 14:40:07 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*prev_tail;
	t_stack	*new_tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prev_tail = *stack;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *stack;
	new_tail->next = NULL;
	*stack = prev_tail;
}

void	r_rotate_a(t_stack **stack)
{
	r_rotate(stack);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **stack)
{
	r_rotate(stack);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	write(1, "rrr\n", 4);
}
