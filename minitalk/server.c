/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:57:11 by nliu              #+#    #+#             */
/*   Updated: 2023/10/16 19:02:30 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_handler(int mysig, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		c = 0;
		i = 0;
		pid = 0;
	}
	mysig -= SIGUSR1;
	c = c << 1 | mysig;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		ft_putchar(c);
		i = 0;
		c = 0;
		pid = 0;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sig;
	int					sig_return;

	sig.sa_sigaction = &my_handler;
	sig.sa_flags = SA_SIGINFO;
	sig_return = sigaction(SIGUSR1, &sig, NULL);
	if (sig_return == -1)
		exit(1);
	sig_return = sigaction(SIGUSR2, &sig, NULL);
	if (sig_return == -1)
		exit(1);
	ft_putstr("Server ID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		sleep(1);
}
