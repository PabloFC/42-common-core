/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:45:24 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/30 11:45:27 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

void	sort_three(t_stack_node **a)
{
	int	first;
	int	middle;
	int	last;

	first = (*a)->value;
	middle = (*a)->next->value;
	last = (*a)->next->next->value;
	if (first > middle && middle < last && last > first)
		case_one(a);
	else if (first > middle && middle > last)
		case_two(a);
	else if (first > middle && middle < last && last < first)
		case_three(a);
	else if (first < middle && middle > last && last > first)
		case_four(a);
	else if (first < middle && middle > last && last < first)
		case_five(a);
}
