/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:58:20 by nliu              #+#    #+#             */
/*   Updated: 2023/10/16 19:02:43 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_received(int a)
{
	(void)a;
	ft_putstr("Message Sent\n");
}

static void	send_byte_to_server(char byte, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int ac, char *av[])
{
	char	*str;
	pid_t	pid;

	signal(SIGUSR1, message_received);
	if (ac != 3)
	{
		ft_putstr("Client takes two Arguments:\n◦ The PID.\n◦ String to send.");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	while (*str)
	{
		send_byte_to_server(*str, pid);
		str++;
	}
	send_byte_to_server(0, pid);
	return (0);
}
