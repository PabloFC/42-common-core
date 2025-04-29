/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:48:11 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/29 11:19:52 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the top node from stack 'b' to stack 'a'.
void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	t_stack_node	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	if (print)
		write(1, "pa\n", 3);
}

// Moves the top node from stack 'b' to stack 'a'.
void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	t_stack_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	if (print)
		write(1, "pb\n", 3);
}
