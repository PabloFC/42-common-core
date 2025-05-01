/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:22:44 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/01 11:23:41 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The find_max_index_pos function iterates through
a stack to find the position of the node with the 
highest index. It returns the position (0-based)
of this maximum index.*/
int	find_max_index_pos(t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				max_index;
	int				max_pos;
	int				current_pos;

	tmp = *stack;
	max_index = tmp->index;
	max_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			max_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (max_pos);
}

/*The `find_min_index_pos` function iterates through
 a stack to find the position of the node with the
smallest index. */
int	find_min_index_pos(t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				min_index;
	int				min_pos;
	int				current_pos;

	tmp = *stack;
	min_index = tmp->index;
	min_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (min_pos);
}

void	move_to_top(t_stack_node **stack, int pos, bool is_stack_a)
{
	int	size;

	size = stack_size(*stack);
	if (pos > size / 2)
	{
		while (pos++ < size)
		{
			if (is_stack_a)
				rra(stack, true);
			else
				rrb(stack, true);
		}
	}
	else
	{
		while (pos-- > 0)
		{
			if (is_stack_a)
				ra(stack, true);
			else
				rb(stack, true);
		}
	}
}

int	get_max_index(t_stack_node *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_min_index(t_stack_node *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}
