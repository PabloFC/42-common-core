/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:48:11 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/25 12:41:03 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack_node **a, t_stack_node **b, bool print)
{
    t_stack_node *tmp;

    if (!*b)
        return;

    tmp = *b;
    *b = (*b)->next;
    if (*b)
        (*b)->prev = NULL;

    tmp->next = *a;
    if (*a)
        (*a)->prev = tmp;
    *a = tmp;

    if (print)
        write(1, "pa\n", 3);
}

void pb(t_stack_node **a, t_stack_node **b, bool print)
{
    t_stack_node *tmp;

    if (!*a)
        return;

    tmp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->prev = NULL;

    tmp->next = *b;
    if (*b)
        (*b)->prev = tmp;
    *b = tmp;

    if (print)
        write(1, "pb\n", 3);
}