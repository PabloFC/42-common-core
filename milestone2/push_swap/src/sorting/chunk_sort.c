/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:00 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/01 11:15:17 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (20);
	else
		return (45);
}

/*The is_in_chunk function checks if a node's 
index falls within a specified range (start to end)
and returns true if it does, otherwise false.*/
static bool	is_in_chunk(t_stack_node *node, int start, int end)
{
	return (node->index >= start && node->index <= end);
}

/*The push_chunk_to_b function is responsible for
 moving elements from stack a to stack b based on 
 a specific range of indices (start to end).*/
static void	push_chunk_to_b(t_stack_node **a,
t_stack_node **b, int start, int end)
{
	int		size;

	size = stack_size(*a);
	while (size > 0)
	{
		if (is_in_chunk(*a, start, end))
			pb(a, b, true);
		else
			ra(a, true);
		size--;
	}
}

/*The chunk_sort function sorts stack a by dividing
it into chunks, moving elements to stack b based
on index ranges, and then reconstructing stack a in sorted order*/
void	chunk_sort(t_stack_node **a, t_stack_node **b)
{
	int		total_size;
	int		chunk_size;
	int		start;
	int		end;
	int		max_pos;

	total_size = stack_size(*a);
	chunk_size = get_chunk_size(total_size);
	start = 0;
	end = chunk_size - 1;
	while (start <= total_size - 1)
	{
		push_chunk_to_b(a, b, start, end);
		start = end + 1;
		end = start + chunk_size - 1;
		if (end > total_size - 1)
			end = total_size - 1;
	}
	while (*b)
	{
		max_pos = find_max_index_pos(b);
		move_to_top(b, max_pos, false);
		pa(a, b, true);
	}
}
