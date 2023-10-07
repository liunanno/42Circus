/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:35:02 by nliu              #+#    #+#             */
/*   Updated: 2023/10/07 19:35:08 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    ft_printf("The PID of this process is: %d\n", getpid());
    while (1)
        usleep(50);
    signal(SIGUSR1, info_client);
	signal(SIGUSR2, info_client);
}