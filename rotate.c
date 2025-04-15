/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:09:23 by dev               #+#    #+#             */
/*   Updated: 2025/04/15 15:43:10 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *stack;
	*stack = (*stack)->next;
	tail->next->next = NULL;
}

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	write (1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	write (1, "rb\n", 3);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
