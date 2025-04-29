/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:58:24 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/29 12:54:53 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move the first node of stack a to the end of the stack.
void	ra(t_stack_node **a, bool print)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	(*a)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print)
		write(1, "ra\n", 3);
}

//move the first node of stack a to the end of the stack.
void	rb(t_stack_node **b, bool print)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	(*b)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print)
		write(1, "rb\n", 3);
}

// performs a simultaneous forward rotation on both stacks a and b,
// moving the first node of each stack to the end.
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		write(1, "rr\n", 3);
}
