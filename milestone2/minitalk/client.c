/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:26:14 by pafuente          #+#    #+#             */
/*   Updated: 2025/03/27 13:09:10 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

//The function converts a byte into a sequence of signals 
//(SIGUSR1 and SIGUSR2) that represent the bits of the byte.
//Inter-process communication is used to send messages character by character.

void	transmit_signal(int target_pid, unsigned char byte)
{
	int				bit_index;
	unsigned char	current_bit;

	bit_index = 8;
	while (bit_index > 0)
	{
		bit_index--;
		current_bit = byte >> bit_index;
		if (current_bit == 0)
			kill(target_pid, SIGUSR2);
		else
			kill(target_pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	int			server_pid;
	const char	*message;
	int			i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}
