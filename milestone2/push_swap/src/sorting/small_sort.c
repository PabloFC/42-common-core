/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:45:24 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/22 11:09:44 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack_node **a)
{
    if ((*a)->value > (*a)->next->value)
        sa(a, true);
}

void sort_three(t_stack_node **a)
{
    int first_pos = (*a)->value;
    int middle_pos = (*a)->next->value;
    int last_pos = (*a)->next->next->value;

    if (first_pos > middle_pos && middle_pos < last_pos && last_pos > first_pos)
        sa(a, true);
    else if (first_pos > middle_pos && middle_pos > last_pos)
    {
        sa(a, true);
        rra(a, true);
    }
    else if (first_pos > middle_pos && middle_pos < last_pos && last_pos < first_pos)
        ra(a, true);
    else if (first_pos < middle_pos && middle_pos > last_pos && last_pos > first_pos)
    {
        sa(a, true);
        ra(a, true);
    }
    else if (first_pos < middle_pos && middle_pos > last_pos && last_pos < first_pos)
        rra(a, true);
}

void sort_four_five(t_stack_node **a, t_stack_node **b)
{
    int size = stack_size(*a);

    while (size > 3)
    {
        int min_pos = find_min_index_pos(a);
        move_to_top(a, min_pos, true);
        pb(a, b, true);
        size--;
    }
    sort_three(a);
    while (*b)
        pa(a, b, true);
}