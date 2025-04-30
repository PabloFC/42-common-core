/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:34:54 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/30 11:35:09 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_one(t_stack_node **a)
{
	sa(a, true);
}

void	case_two(t_stack_node **a)
{
	sa(a, true);
	rra(a, true);
}

void	case_three(t_stack_node **a)
{
	ra(a, true);
}

void	case_four(t_stack_node **a)
{
	sa(a, true);
	ra(a, true);
}

void	case_five(t_stack_node **a)
{
	rra(a, true);
}
