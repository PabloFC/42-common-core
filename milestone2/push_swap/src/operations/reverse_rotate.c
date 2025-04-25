/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:58:17 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/25 12:45:30 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack_node **a, bool print)
{
    t_stack_node *last;
    t_stack_node *second_last;

    if (!*a || !(*a)->next)
        return;
    last = *a;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->prev = NULL;
    last->next = *a;
    (*a)->prev = last;
    *a = last;
    if (print)
        write(1, "rra\n", 4);
}

void rrb(t_stack_node **b, bool print)
{
    t_stack_node *last;
    t_stack_node *second_last;

    if (!*b || !(*b)->next)
        return;
    last = *b;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->prev = NULL;
    last->next = *b;
    (*b)->prev = last;
    *b = last;
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rra(a, false);
    rrb(b, false);
    if (print)
        write(1, "rrr\n", 4);

}