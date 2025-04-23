/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:21:04 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/23 10:21:14 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exit_with_error(void)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit(EXIT_FAILURE);
}

long ft_atol(const char *str)
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}