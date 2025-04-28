/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:00 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/28 10:14:33 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_chunk_size(int total_size) {
    if (total_size <= 100)
        return 20; // 5 chunks de 20
    else
        return 45; // para 500 → ~11 chunks
}

static bool is_in_chunk(t_stack_node *node, int start, int end) {
    return (node->index >= start && node->index <= end);
}

static void push_chunk_to_b(t_stack_node **a, t_stack_node **b, int start, int end) {
    int size = stack_size(*a);
    while (size > 0) {
        if (is_in_chunk(*a, start, end)) {
            pb(a, b, true);
        } else {
            ra(a, true);
        }
        size--;
    }
}

void chunk_sort(t_stack_node **a, t_stack_node **b) {
    int total_size = stack_size(*a);
    int chunk_size = get_chunk_size(total_size);
    int start = 0;
    int end = chunk_size - 1;

    while (start <= total_size - 1) {
        push_chunk_to_b(a, b, start, end);
        start = end + 1;
        end = start + chunk_size - 1;
        if (end > total_size - 1)
            end = total_size - 1;
    }

    // Ahora ordenamos de mayor a menor desde B a A
    while (*b) {
        int max_pos = find_max_index_pos(b);
        move_to_top(b, max_pos, false);
        pa(a, b, true);
    }
}
