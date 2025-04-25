/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:55:51 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/25 13:46:51 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int	get_max_bits(t_stack_node *stack)
{
	int	max;
	int	bits;

	max = get_max_index(stack);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	i;
	int	j;
	int	size;
	int	bit;
	t_stack_node *node;

	size = stack_size(*a);
	bit = get_max_bits(*a);
	i = 0;
	while (i < bit)
	{
		j = 0;
		while (j < size)
		{
			node = *a;
			if (((node->index >> i) & 1) == 1)
				ra(a, true);
			else
				pb(a, b, true);
			j++;
		}
		while (*b)
			pa(a, b, true);
		i++;
	}
}
