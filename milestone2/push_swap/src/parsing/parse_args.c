/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:16:02 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/23 10:16:14 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valid_number(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static void check_duplicates(t_stack_node *stack)
{
    t_stack_node *tmp;
    t_stack_node *compare;

    tmp = stack;
    while (tmp)
    {
        compare = tmp->next;
        while (compare)
        {
            if (tmp->value == compare->value)
                exit_with_error();
            compare = compare->next;
        }
        tmp = tmp->next;
    }
}

static void assign_indexes(t_stack_node *stack)
{
    t_stack_node *tmp;
    t_stack_node *compare;
    int index;

    tmp = stack;
    while (tmp)
    {
        compare = stack;
        index = 0;
        while (compare)
        {
            if (compare->value < tmp->value)
                index++;
            compare = compare->next;
        }
        tmp->index = index;
        tmp = tmp->next;
    }
}

t_stack_node *parse_args(int argc, char **argv)
{
    t_stack_node *stack_a;
    long num;
    int i;

    stack_a = NULL;
    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
            exit_with_error();
        num = ft_atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            exit_with_error();
        if (i == 1)
            stack_a = stack_new((int)num);
        else
            stack_add_back(&stack_a, stack_new((int)num));
        i++;
    }
    check_duplicates(stack_a);
    assign_indexes(stack_a);
    return (stack_a);
}