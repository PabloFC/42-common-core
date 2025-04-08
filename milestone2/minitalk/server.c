/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:37:00 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/08 11:24:29 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/*
The function ft_signal_to_char reconstructs a character
from signals (SIGUSR1 as bit 1 and SIGUSR2 as bit 0).
When it receives 8 bits, it prints the character
using ft_printf and resets the variables to process the next one.
*/

void ft_signal_to_char(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Usage: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID -> %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1,ft_signal_to_char);
		signal(SIGUSR2,ft_signal_to_char);
		pause ();
	}
	return (0);
}