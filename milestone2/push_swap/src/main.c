/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:01:39 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/28 10:17:37 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b = NULL;
    int size;

    if (argc < 2)
        return 0;

    a = parse_args(argc, argv);
    size = stack_size(a);

    if (is_sorted(a))
    {
        free_stack(&a);
        return 0;
    }

    if (size == 2)
        sort_two(&a);
    else if (size == 3)
        sort_three(&a);
    else if (size <= 5)
        sort_four_five(&a, &b);
    else
        chunk_sort(&a, &b);

    free_stack(&a);
    return 0;
}