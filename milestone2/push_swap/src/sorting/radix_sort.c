/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:55:51 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/24 13:18:48 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void radix_sort(t_stack_node **stack_a, t_stack_node **stack_b) {
    int max_index = get_max_index(*stack_a);
    int max_bits = 0;
    int bit = 0;
    int size;
    
    while ((max_index >> max_bits) != 0)
        max_bits++;

    while (bit < max_bits) {
        size = stack_size(*stack_a);
        while (size-- > 0) {
            if (((*stack_a)->index >> bit) & 1)
                ra(stack_a, true);
            else
                pb(stack_a, stack_b, true);
        }
        while (*stack_b)
            pa(stack_a, stack_b, true);
        bit++;
    }
}