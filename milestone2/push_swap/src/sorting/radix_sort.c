/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:55:51 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/22 11:25:13 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int get_max_bits(t_stack_node **stack)
{
    int max = get_max_index(*stack);
    int max_bits = 0;

    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix_sort(t_stack_node **a, t_stack_node **b)
{
    int max_bits = get_max_bits(a);
    int size;
    int i, j;

    for (i = 0; i < max_bits; i++)
    {
        size = stack_size(*a);
        for (j = 0; j < size; j++)
        {
            if ((((*a)->index >> i) & 1))
                ra(a, true);
            else
                pb(a, b, true);
        }
        while (*b)
            pa(a, b, true);
    }
}