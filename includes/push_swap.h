/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:42:12 by dev               #+#    #+#             */
/*   Updated: 2025/04/14 14:40:11 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//check_input.c
int		has_duplicates(int *nums, int size);
int		is_valid_number(char *str);
int		fill_numbers_from_argument(char *arg, int *nums, int *index);
void	count_total_numbers(int ac, char **av, int *count);
void	check_input(int ac, char **av);

//initialize.c
t_stack	*init_list(int ac, char **av);
void	index_stack(t_stack *stack);
void	parse_and_fill(int ac, char **av, int *nums, int *index);

//instructions
void	swap(t_stack **stack);
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_from, t_stack **stack_to);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	r_rotate(t_stack **stack);
void	r_rotate_a(t_stack **stack);
void	r_rotate_b(t_stack **stack);
void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b);

//sort_utils.c
int		count_nodes(t_stack *stack);
int		find_biggest(t_stack *stack);
int		find_bits(int biggest_nbr);
int		sorted(t_stack **stack);
int		count_nodes(t_stack *stack);

//sort.c
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

//free_and_error.c
void	free_stack(t_stack **stack);
void	free_split(char **split);
void	error_msg(char *str);

#endif