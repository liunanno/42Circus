/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:57:19 by nliu              #+#    #+#             */
/*   Updated: 2023/10/07 21:04:27 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void action(int sig)
{
    static int received = 0;
    if (sig == SIGUSR1)
        received++;
    else
    {
        ft_putnbr_fd(received, 1);
        ft_putchar_fd('\n');
        exit(0);
    }
}

static void mt_kill(int pid, char *str)
{
    int     i;
    char    c;

    while (*str)
    {
        i = 8;
        c = *str++;
        while (i--)
        {
            if (c >> i & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            usleep(100);
        }
    }
    i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1);
        usleep(100);
    }
}

int main(int ac, char **av)
{
    if (ac != 3 || !ft_strlen(av[2]))
        return (1);
    ft_printf("Client sent:   %d\n", ft_strlen(av[2]));
    ft_printf("Server received: ");
    signal(SIGUSR1, action);
    signal(SIGUSR2, action);
    mt_kill(argv[1], argv[2]);
    while (1)
        pause();
    return (0);
}