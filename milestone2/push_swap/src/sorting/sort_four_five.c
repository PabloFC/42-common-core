/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:19:27 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/30 11:19:32 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_five(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	while (size > 3)
	{
		min_pos = find_min_index_pos(a);
		move_to_top(a, min_pos, true);
		pb(a, b, true);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, true);
}
