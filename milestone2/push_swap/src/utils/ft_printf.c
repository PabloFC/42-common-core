/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:58 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/23 10:23:06 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void ft_putstr(char *s)
{
    while (*s)
        ft_putchar(*s++);
}

static void ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'd')
        {
            ft_putnbr(va_arg(args, int));
            format++;
            count++;
        }
        else
        {
            ft_putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}