/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:26:14 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/08 10:47:02 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

//The function `ft_send_char_as_signals` sends 
//the bits of a character as signals to the process 
//specified by the `pid`.

void	ft_send_char_as_signals(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_char_as_signals(pid, argv[2][i]);
			i++;
		}
		ft_send_char_as_signals(pid, '\n');
	}
	else
	{
		write(2, "Error: wrong format.\n", 21);
		write(2, "Try: ./client <PID> <MESSAGE>\n", 30);
		return (1);
	}
	return (0);
}