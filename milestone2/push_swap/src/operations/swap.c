/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:58:20 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/21 13:41:53 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack_node **a, bool print)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!*a || !(*a)->next)
        return;
    first = *a;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *a = second;
    if (print)
        ft_printf("sa\n");
}

void sb(t_stack_node **b, bool print)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!*b || !(*b)->next)
        return;
    first = *b;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *b = second;
    if (print)
        ft_printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b, bool print)
{
    sa(a, false);
    sb(b, false);
    if (print)
        ft_printf("ss\n");
}