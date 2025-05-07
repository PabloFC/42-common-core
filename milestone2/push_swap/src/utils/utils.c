/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:23:52 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/07 10:23:41 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strncpy(char *dst, const char *src, int n)
{
	while (n-- && *src)
		*dst++ = *src++;
	*dst = '\0';
}

//The `is_sorted` function checks if a linked
// list stack is sorted in ascending order.
bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		ft_printf("%d (idx: %d)\n", stack->value, stack->index);
		stack = stack->next;
	}
	ft_printf("----\n");
}
